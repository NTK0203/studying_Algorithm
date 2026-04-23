N = int(input())
money = [500,100,50,10]
count=0
for i in money:
    count+=N//i
    N%=i
print(count)