move = [[2,1],[2,-1],[-2,1],[-2,-1],[1,2],[1,-2],[-1,2],[-1,-2]]
count = 0
location = list(input())
row=int(location[1])
col=ord(location[0])-96
for i in range(8):
    r=row+move[i][0]
    c=col+move[i][1]
    if(0<r<9 and 0<c<9):
        count+=1
print(count)