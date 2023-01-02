N = 0
flag = True #토글 True False 반복
for i in range(8): # i = 0.1.2.3.4.5.6.7
    B = input() # ".F.F.F..."
    for j in range(8):  #j = 0.1.2.3.4.5.6.7
        if flag: #짝수 인덱스가 흰색
            if j % 2 == 0 and B[j] == 'F':
                N += 1
        else: #홀수 인덱스가 흰색
            if j % 2 == 1 and B[j] == 'F':
                N += 1
    flag = not flag

print(N)
