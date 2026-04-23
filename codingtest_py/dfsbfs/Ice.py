count=0
frame=list()

def dfs(n,m):
    if n<0 or m<0 or n>=N or m>=M:
        return
    elif frame[n][m]==1:
        return
    frame[n][m]=1
    dfs(n-1,m) #W
    dfs(n+1,m) #E
    dfs(n,m-1) #S
    dfs(n,m+1) #N

N,M = map(int, input().split())
for i in range(N):
    frame.append(list(map(int,input())))
 
for i in range(N):
    for j in range(M):
        if frame[i][j]==0:
            dfs(i,j)
            count+=1
          
print(count)