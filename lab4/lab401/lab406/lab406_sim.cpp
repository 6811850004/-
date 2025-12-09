// --- การกำหนดค่าพินของเซ็นเซอร์และมอเตอร์ ---
#define SENSOR_LEFT 8
#define SENSOR_MIDDLE 9
#define SENSOR_RIGHT 10

// พิน PWM สำหรับควบคุมความเร็วของมอเตอร์ (ต้องเชื่อมต่อกับ Motor Driver)
#define MOTOR_LEFT 5
#define MOTOR_RIGHT 6

// ความเร็วพื้นฐานของมอเตอร์ (0-255)
const int BASE_SPEED = 100;

void setup() {
    // กำหนดพินเซ็นเซอร์เป็น INPUT
    pinMode(SENSOR_LEFT, INPUT);
    pinMode(SENSOR_MIDDLE, INPUT);
    pinMode(SENSOR_RIGHT, INPUT);

    // กำหนดพินมอเตอร์เป็น OUTPUT (สำหรับ PWM)
    pinMode(MOTOR_LEFT, OUTPUT);
    pinMode(MOTOR_RIGHT, OUTPUT);

    Serial.begin(9600); // เริ่มต้น Serial Monitor สำหรับการ Debug
}

// ฟังก์ชันควบคุมมอเตอร์
void setMotorSpeed(int leftSpeed, int rightSpeed) {
    // ในหุ่นยนต์จริง อาจต้องมี Logic เพิ่มเติมเพื่อกำหนดทิศทาง (ไปหน้า/หลัง)
    // แต่ในตัวอย่างนี้สมมติว่าค่าบวกคือ "ไปข้างหน้า"
    analogWrite(MOTOR_LEFT, leftSpeed);
    analogWrite(MOTOR_RIGHT, rightSpeed);
}

void loop() {
    // อ่านค่าจากเซ็นเซอร์ (สมมติ: LOW = เห็นเส้นสีดำ, HIGH = เห็นพื้นสีขาว)
    int val_L = digitalRead(SENSOR_LEFT);
    int val_M = digitalRead(SENSOR_MIDDLE);
    int val_R = digitalRead(SENSOR_RIGHT);

    // --- 1. เดินหน้าตรง (On the Line) ---
    if (val_M == LOW) { // เซ็นเซอร์กลางเห็นเส้น
        setMotorSpeed(BASE_SPEED, BASE_SPEED);
        Serial.println("Go Straight");
    }

    // --- 2. เลี้ยวซ้าย (Line shifted right) ---
    else if (val_R == LOW) { // เซ็นเซอร์ขวาเห็นเส้น (รถต้องเลี้ยวซ้ายเพื่อตามเส้น)
        setMotorSpeed(BASE_SPEED * 0.5, BASE_SPEED); // ลดความเร็วซ้าย
        Serial.println("Turn Left");
    }

    // --- 3. เลี้ยวขวา (Line shifted left) ---
    else if (val_L == LOW) { // เซ็นเซอร์ซ้ายเห็นเส้น (รถต้องเลี้ยวขวาเพื่อตามเส้น)
        setMotorSpeed(BASE_SPEED, BASE_SPEED * 0.5); // ลดความเร็วขวา
        Serial.println("Turn Right");
    }

    // --- 4. หาเส้น/หยุด (Off the Line) ---
    else { // ทั้งสามเซ็นเซอร์เห็นพื้นสีขาว (หลุดจากเส้น)
        // อาจจะให้หยุด, หมุนกลับหลัง, หรือหมุนช้าๆ เพื่อหาเส้น
        setMotorSpeed(0, 0);
        Serial.println("Stop / Lost Line");
    }
}