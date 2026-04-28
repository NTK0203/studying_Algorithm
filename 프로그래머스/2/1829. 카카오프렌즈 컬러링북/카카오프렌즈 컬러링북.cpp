#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    vector<int> answer(2);
    queue<pair<int,int>> q;
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int color=picture[i][j];
            int cnt=1;
            if(color!=0){
                q.push({i,j});
                number_of_area++;
                picture[i][j]=0;
                //bfs
                while(!q.empty()){
                    pair<int,int> cur=q.front();
                    q.pop();
                    for(int k=0;k<4;k++){
                        int nx=cur.first+dx[k];
                        int ny=cur.second+dy[k];
                        if(nx<0 || nx>=m || ny<0 || ny>=n)
                            continue;
                        if(picture[nx][ny]==color){
                            q.push({nx,ny});
                            cnt++;
                            picture[nx][ny]=0;
                        }
                    }
                }
                if(cnt>max_size_of_one_area)
                    max_size_of_one_area=cnt;
            }
        }
    }
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}