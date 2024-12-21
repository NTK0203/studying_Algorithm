#include <iostream>
using namespace std;

int main() {
  int X, dp[1000001], temp;
  cin >> X;
  dp[0] = 0;
  dp[1] = 0;
  for (int i = 2; i <= X; i++) {
    if (i % 2 == 0 && i % 3 == 0) {
      if (dp[i / 2] > dp[i / 3])
        temp = dp[i / 3] + 1;
      else
        temp = dp[i / 2] + 1;
    } else if (i % 3 == 0)
      temp = dp[i / 3] + 1;
    else if (i % 2 == 0)
      temp = dp[i / 2] + 1;
    else
      temp = dp[i - 1] + 1;
    if (temp > (dp[i - 1] + 1))
      temp = dp[i - 1] + 1;
    dp[i] = temp;
  }
  cout << dp[X] << endl;
  return 0;
}