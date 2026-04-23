N, M = map(int, input().split())
x, y, d = map(int, input().split())
gameMap=[]
dx=[0,1,0,-1]
dy=[1,0,-1,0]
count=1
movement=4
check=1

for i in range(N):
    gameMap.append(list(map(int, input().split())))
gameMap[y][x]=1

def move():
    global x, y, count
    x+=dx[d]
    y+=dy[d]
    count+=1

def back():
    global x, y
    x-=dx[d]
    y-=dy[d]

while(check or movement):
    if(movement==0):
        back()
        check=0
        movement=4
        continue
    if(gameMap[y+dy[d]][x+dx[d]]==0):
        move()
        gameMap[y][x]=1
        check=1
        movement=4
        continue
    else:
      if(d==0):
          d=3
      else:
          d-=1
    movement-=1
print(count)