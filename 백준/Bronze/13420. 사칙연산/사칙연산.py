T = eval(input())

inputData = []
resultData = []
def check(inputData):
    if inputData[1] == '+' and ((int(inputData[0]) + int(inputData[2])) == int(inputData[4])):
        resultData.append('correct')
    elif inputData[1] == '-' and ((int(inputData[0]) - int(inputData[2])) == int(inputData[4])):
        resultData.append('correct')
    elif inputData[1] == '*' and ((int(inputData[0]) * int(inputData[2])) == int(inputData[4])):
        resultData.append('correct')
    elif inputData[1] == '/' and ((int(inputData[0]) / int(inputData[2])) == int(inputData[4])):
        resultData.append('correct')
    else:
        resultData.append('wrong answer')

for i in range(T):
    inputData = (input().split())
    check(inputData)

for i in range(T):
    print(resultData[i])