T = eval(input())

testData = []
result = []

def getWay(N, initialList, goalList):
    count = 0
    gotoB = 0
    gotoW = 0
    resultNum = 0
    for i in range(N):
        if initialList[i] != goalList[i]:
            if initialList[i] == 'W':
                gotoB += 1
            else:
                gotoW += 1
    if gotoB >= gotoW:
        return gotoB
    else:
        return gotoW
            
for i in range(T):
    initialList = []
    goalList = []
    N = eval(input())
    initial = input()
    for i in range(N):
        initialList.append(initial[i])
    goal = input()
    for i in range(N):
        goalList.append(goal[i])
    result.append(getWay(N, initialList, goalList))

for i in range(T):
    print(result[i])