#include <iostream>
using namespace std;

int main() {
  int N, q, r;
  cin >> N;
  q = N / 5;
  r = N % 5;
  for (int i = q; i >= 0; i--) {
    if (r % 3 == 0)
      break;
    q--;
    r += 5;
  }
  if (q == -1)
    cout << -1 << endl;
  else
    cout << q + r / 3 << endl;
  return 0;
}