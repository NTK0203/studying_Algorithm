#include <algorithm>
#include <iostream>
using namespace std;
int verticle(int, int, int);

int main() {
  int num[3];
  for (int i = 30000; i > 0; i--) {
    cin >> num[0] >> num[1] >> num[2];
    if (num[0] == 0 && num[1] == 0 && num[2] == 0)
      break;
    sort(num, num + 3);
    for (int j = 0; j < 3; j++)
      num[j] *= num[j];
    if ((num[0] + num[1]) == num[2])
      cout << "right" << endl;
    else
      cout << "wrong" << endl;
  }
  return 0;
}
