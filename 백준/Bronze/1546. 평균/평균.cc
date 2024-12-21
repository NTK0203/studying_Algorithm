#include <iostream>
using namespace std;

int main() {
  int N;
  int num[1000];
  double mean = 0, M = 0;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> num[i];
    if (M < num[i])
      M = num[i];
  }
  for (int j = 0; j < N; j++)
    mean += ((float)(num[j] / M) * 100);
  mean /= N;
  cout << mean << endl;
  return 0;
}