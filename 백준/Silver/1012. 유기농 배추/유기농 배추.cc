#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int bfs(int**,int,int,int, int);

int main(){
  int T, M, N, K;
  int x, y;
  cin>>T;
  for(int i=0;i<T;i++){
    cin>>M>>N>>K;
    int count=0;

    int** arr=new int*[N];
    for(int i=0;i<N;i++){
      arr[i]=new int[M];
      memset(arr[i],0,sizeof(int)*(M));
    }

    for(int i=0;i<K;i++){
      cin>>x>>y;
      arr[y][x]=1;
    }

    for(int i=0;i<N;i++)
      for(int j=0;j<M;j++){
        count+=bfs(arr,N,M,j,i);
      }

    cout<<count<<endl;

    for(int i=0;i<N;i++)
      delete[] arr[i];
    delete[] arr;
  }
  return 0;
}

int bfs(int** arr, int N, int M, int x, int y){
  if(arr[y][x]==0)//no way
    return 0;

  int direction[4][2] = {{1,0},{-1,0},{0,1},{0,-1}}; //up,down,right,left
  queue<pair<int,int>> q;
  q.push({y,x});

  while(!q.empty()){
    y = q.front().first;
    x = q.front().second;
    q.pop();
    for(int i=0;i<4;i++){
      int next_x = x+direction[i][1];
      int next_y = y+direction[i][0];

      if(next_x>=M||next_x<0||next_y>=N||next_y<0) //out of bounds
        continue;
      else if(arr[next_y][next_x]==0) //no way
        continue;
      else
      {
        q.push({next_y,next_x});
        arr[next_y][next_x]=0;
      }
    }
  }

  return 1;
}