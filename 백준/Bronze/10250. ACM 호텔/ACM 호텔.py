def findRoomNumber(H, W, N):
    if N < H:
        return int(str(N)+'01')
    elif N % H == 0:
        room = N // H
        if room < 10:
            return int(str(H)+'0'+str(room))
        else:
            return int(str(H)+str(room))

    else:
        if H == 1:
            if N < 10:
                return int('10'+str(N))
            else:
                return int('1'+str(N))
        else:
            num = N // H
            floor = N % (num * H)
            if num < 9:
                return int(str(floor)+'0'+str(num+1))
            else:
                return int(str(floor)+str(num+1))

T = eval(input())
testData = []
for i in range(T):
    H, W, N = map(int, input().split()) 
    testData.append(findRoomNumber(H, W, N))

for i in range(T):
    print(testData[i])
