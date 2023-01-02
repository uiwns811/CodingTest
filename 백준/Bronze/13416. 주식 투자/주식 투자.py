T = eval(input())

def findMaxProfit(profitData):
    if max(profitData) > 0:
        return max(profitData)
    elif max(profitData) <= 0:
        return 0

resultList = []

for i in range(T):
    N = eval(input())
    profitData = [0 for i in range(N)]
    result = 0
    for i in range(N):
        profitData[i] = list(map(int, input().split()))
        result += findMaxProfit(profitData[i])
    resultList.append(result)

for i in range(T):
    print(resultList[i])