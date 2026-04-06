import sys

f={0:0, 1:1, 2:1}

def fibo(n):
    if n in f:
        return f[n]
    if n%2==0:
        f[n]=(fibo(n/2)*(fibo(n/2+1)+fibo(n/2-1)))
    else:
        f[n]=(fibo((n+1)/2)*fibo((n+1)/2)+fibo((n-1)/2)*fibo((n-1)/2))
    return f[n]
n = int(sys.stdin.readline())
print(fibo(n))