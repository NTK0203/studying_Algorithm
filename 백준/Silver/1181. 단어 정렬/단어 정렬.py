n=int(input())
arr=list()
for i in range(n):
    word=input()
    arr.append([len(word),word])
temp=list()
for i in arr:
    if i not in temp:
        temp.append(i)
arr=temp
arr.sort(key=lambda x:x[1])
arr.sort(key=lambda x:x[0])
for i in range(len(arr)):
    print(arr[i][1])