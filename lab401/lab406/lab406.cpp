
#include <Arduino.h>

// --- PIN CONFIGURATION -----------------------------------------------------
const uint8_t SENSOR_L = A0;   // left IR sensor (analog or digital)
const uint8_t SENSOR_C = A1;   // center
const uint8_t SENSOR_R = A2;   // right

// Left motor
const uint8_t LM_PWM   = 5;    // PWM pin for left motor speed
const uint8_t LM_DIR1  = 2;    // direction pins
const uint8_t LM_DIR2  = 3;

// Right motor
const uint8_t RM_PWM   = 6;    // PWM pin for right motor speed
const uint8_t RM_DIR1  = 4;
const uint8_t RM_DIR2  = 7;

// --- PARAMS & PID ---------------------------------------------------------
const int BASE_SPEED = 150;
float Kp = 60.0f;
float Ki = 0.0f;
float Kd = 12.0f;

unsigned long lastTime = 0;
float integralTerm = 0.0f;
int lastError = 0;

// Thresholds for digital decision (if using analog sensors adjust accordingly)
const int THRESH = 500; // for analog readings 0-1023

// --- HELPERS ---------------------------------------------------------------
int readSensor(uint8_t pin) {
    // If you have digital sensors use digitalRead; analogRead if analog.
    return analogRead(pin);
}

void setMotor(int pwmPin, int dir1, int dir2, int speed) {
    // speed positive => forward, negative => reverse
    if (speed >= 0) {
        digitalWrite(dir1, HIGH);
        digitalWrite(dir2, LOW);
        analogWrite(pwmPin, constrain(speed, 0, 255));
    } else {
        digitalWrite(dir1, LOW);
        digitalWrite(dir2, HIGH);
        analogWrite(pwmPin, constrain(-speed, 0, 255));
    }
}

// Map sensor pattern to error value:
// center only -> error 0
// left only -> -1 (robot is right of line, turn left)
// right only -> +1 (robot is left of line, turn right)
// combinations map to -2..+2
int computeError(int l, int c, int r) {
    int L = (l > THRESH);
    int C = (c > THRESH);
    int R = (r > THRESH);

    if (C && !L && !R) return 0;
    if (L && !C && !R) return -2;
    if (!L && !C && R) return +2;
    if (L && C && !R) return -1;
    if (!L && C && R) return +1;
    if (L && C && R) return 0; // on intersection
    // fallback: prefer center; otherwise keep last error sign
    return lastError;
}

// --- SETUP & LOOP ---------------------------------------------------------
void setup() {
    // Motor pins
    pinMode(LM_DIR1, OUTPUT);
    pinMode(LM_DIR2, OUTPUT);
    pinMode(RM_DIR1, OUTPUT);
    pinMode(RM_DIR2, OUTPUT);
    pinMode(LM_PWM, OUTPUT);
    pinMode(RM_PWM, OUTPUT);

    // Sensors (analog pins default)
    pinMode(SENSOR_L, INPUT);
    pinMode(SENSOR_C, INPUT);
    pinMode(SENSOR_R, INPUT);

    Serial.begin(115200);
    lastTime = millis();
}

void loop() {
    // read sensors
    int sL = readSensor(SENSOR_L);
    int sC = readSensor(SENSOR_C);
    int sR = readSensor(SENSOR_R);

    int error = computeError(sL, sC, sR);

    // PID timing
    unsigned long now = millis();
    float dt = (now - lastTime) / 1000.0f;
    if (dt <= 0) dt = 0.001f;

    // PID
    integralTerm += error * dt;
    float derivative = (error - lastError) / dt;
    float output = Kp * error + Ki * integralTerm + Kd * derivative;

    lastError = error;
    lastTime = now;

    // convert PID output to motor speed difference
    int leftSpeed  = int(BASE_SPEED - output);
    int rightSpeed = int(BASE_SPEED + output);

    // constrain speeds
    leftSpeed  = constrain(leftSpeed, -255, 255);
    rightSpeed = constrain(rightSpeed, -255, 255);

    setMotor(LM_PWM, LM_DIR1, LM_DIR2, leftSpeed);
    setMotor(RM_PWM, RM_DIR1, RM_DIR2, rightSpeed);

    // debug
    Serial.print("L:"); Serial.print(sL);
    Serial.print(" C:"); Serial.print(sC);
    Serial.print(" R:"); Serial.print(sR);
    Serial.print(" err:"); Serial.print(error);
    Serial.print(" out:"); Serial.print(output);
    Serial.print(" Lsp:"); Serial.print(leftSpeed);
    Serial.print(" Rsp:"); Serial.println(rightSpeed);

    delay(10); // loop ~100Hz
}
