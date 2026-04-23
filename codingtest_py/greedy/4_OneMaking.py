N, K = map(int, input().split())
count=0
while(True):
    Q=N//K*K
    count+=N-Q
    N=Q
    if(N<K):
        break
    count+=1
    N//=K
count+=N-1
print(count)