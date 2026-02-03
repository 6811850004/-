def score_grade(score):
    if score >= 80:
        print ('grade = 4')  
    elif score >= 70            :
        print ('grade = 3.5')
    elif score >= 60:
        print ('grade = 3')
    elif score >= 50    :
        print ('grade = 2.5')
    else:
        print ('grade = 0')
user_score = float(input("กรุณากรอกคะแนนของคุณ : "))
score_grade(user_score) 

    


print("________________________________________________")