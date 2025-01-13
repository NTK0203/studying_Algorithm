n,k=list(map(int,input().split()))
n_p=1
k_p=1
for i in range(n,0,-1):
    n_p*=i
for i in range(1,n-k+1):
    k_p*=i
for i in range(1,k+1):
    k_p*=i
print(n_p//k_p)