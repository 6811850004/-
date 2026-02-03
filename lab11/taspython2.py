def calculate_area():
    print("\n--- โปรแกรมคำนวณพื้นที่สี่เหลี่ยม ---")
    width = float(input("ป้อนความกว้าง (Width): "))
    length = float(input("ป้อนความยาว (Length): "))
    
    # TODO: คำนวณพื้นที่ (กว้าง x ยาว)
    area = width * length
    
    print(f"พื้นที่สี่เหลี่ยมคือ: {area:.2f} ตารางหน่วย")

# เรียกใช้งานฟังก์ชัน
calculate_area()
print("________________________________________________")