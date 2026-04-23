N=int(input())
movement = list(map(str,input().split()))
x=1
y=1
for i in range(len(movement)):
    if(movement[i]=="R" and y<N):
        y+=1
    elif(movement[i]=="L" and y>1):
        y-=1
    elif(movement[i]=="U" and x>1):
        x-=1
    elif(movement[i]=="D" and x<N):
        x+=1
print(x,y)