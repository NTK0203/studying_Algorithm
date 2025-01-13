n=int(input())
arr=list(map(int,input().split()))
t,p =list(map(int,input().split()))

total=0
for i in range(6):
    total+=(arr[i]//t)
    if(arr[i]%t!=0):
        total+=1
print(total)
print(n//p,n%p)