N,M = map(int,input().split())
number = []
max=0
for i in range(N):
    number = list(map(int,input().split()))
    min_num=min(number)
    if(min_num>max):
        max=min_num
print(max)