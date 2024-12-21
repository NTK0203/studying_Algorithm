#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  vector<int> v[101];
  bool check[101] = {
      false,
  };
  stack<int> s;
  s.push(1);
  check[1] = true;
  int n, c, f_in, b_in, count = 0, temp = 1;

  cin >> n >> c;

  for (int i = 0; i < c; i++) {
    cin >> f_in >> b_in;
    v[f_in].push_back(b_in);
    v[b_in].push_back(f_in);
  }

  while (!(s.empty())) {
    for (int i = 0; i < v[temp].size(); i++) {
      if (check[v[temp][i]] == false) {
        s.push(v[temp][i]);
        check[v[temp][i]] = true;
        temp = v[temp][i];
        i = 0;
      }
      temp = s.top();
    }
    s.pop();
  }

  for (int i = 2; i < 101; i++){
    if (check[i] == true)
      count++;
  }

  cout << count << endl;

  return 0;
}