
from collections import deque

queue = deque()

def bfs(graph, v, visited):
    visited[v]=True
    print(v,end=' ')
    queue.append(v)
    while(queue):
        for i in range(len(graph[v])):
            if not visited[graph[v][i]]:
                queue.append(graph[v][i])
                print(graph[v][i],end=' ')
                visited[graph[v][i]]=True
        v=queue.popleft() 
        
    

graph=[
  [],
  [2,3,8],
  [1,7],
  [1,4,5],
  [3,5],
  [3,4],
  [7],
  [2,6,8],
  [1,7]
]
visited=[False]*9
bfs(graph,1,visited)