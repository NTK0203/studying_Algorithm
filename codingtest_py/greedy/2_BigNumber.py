N,M,K = map(int,input().split())
number = list(map(int,input().split()))
number.sort(reverse=True)
seccount=M//K
sum=(M-seccount)*number[0]+seccount*number[1]
print(sum)