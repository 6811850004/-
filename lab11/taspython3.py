def calculate_salary():
    print("\n--- โปรแกรมคำนวณเงินเดือนพนักงาน ---")
    emp_id = input("รหัสพนักงาน: ")
    hours = float(input("ชั่วโมงทำงาน: "))
    rate = float(input("อัตราค่าจ้างต่อชั่วโมง: "))

    # TODO: คำนวณรายได้รวม (Gross Salary) ตามเงื่อนไข
    if hours >= 30:
        gross_salary = hours * (rate + 50)
    else:
        gross_salary = hours * rate

    # TODO: คำนวณภาษี 7% และรายได้สุทธิ (Net Salary)
    tax = gross_salary * 0.07
    net_salary = gross_salary - tax

    print(f"พนักงานรหัส: {emp_id}")
    print(f"รายได้รวม: {gross_salary:,.2f} บาท")
    print(f"ภาษีที่หัก (7%): {tax:,.2f} บาท")
    print(f"รายได้สุทธิ: {net_salary:,.2f} บาท")

calculate_salary()
