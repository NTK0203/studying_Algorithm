N = int(input())
hour = 0
min = 0
sec = 0
count=0
for hour in range(N+1):
    for min in range(60):
        for sec in range(60):
            if '3' in str(hour) + str(min) + str(sec): #문자열로 변환해서 조건문 최적화
                count+=1
print(count)