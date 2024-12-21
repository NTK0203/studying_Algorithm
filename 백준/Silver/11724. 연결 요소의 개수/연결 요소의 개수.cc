#include <iostream>
#include <stack>
#include <vector>
using namespace std;
void dfs(vector<int>*, bool*, stack<int>, int);

int main() {
  vector<int> vec[1001];
  bool check[1001] = {
      false,
  };
  int N, M, count = 0;
  stack<int> s;
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    vec[u].push_back(v);
    vec[v].push_back(u);
  }

  for (int i = 1; i <= N; i++) {
    if (check[i] == false) {
      check[i] = true;
      s.push(i);
      dfs(vec, check, s, i);
      count++;
    }
  }
  if (count==0)
    cout<<1;
  else
    cout<<count;

  return 0;
}

void dfs(vector<int>* vec, bool *check, stack<int> s, int i) {
  while(!s.empty()){
    for(int j=0;j<vec[i].size();j++){
      int cur=vec[i][j];
      if(check[cur]==false){
        check[cur]=true;
        s.push(cur);
        i=cur;
        j=0;
      }
      i=s.top();
    }
    s.pop();
  }
  return;
}