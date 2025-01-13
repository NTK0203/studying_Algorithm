n,m=list(map(int,input().split()))
arr=list(map(int,input().split()))
result=0
for i in range(n-2):
    for j in range(i+1,n-1,1):
        for k in range(j+1,n,1):
            sum=arr[i]+arr[j]+arr[k]
            if(m-sum>=0):
                if(result==0):
                    result=sum
                elif(m-result>m-sum):
                    result=sum
print(result)