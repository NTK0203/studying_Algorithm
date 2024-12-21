#include <iostream>
#include <string>

using namespace std;

int main() {
  string num;
  bool check;
  while (1) {
    cin >> num;
    if (num.compare("0") == 0)
      break;

    switch (num.length()) {
    case (1):
      check = true;
      break;
    case (2):
      if (num[0] == num[1])
        check = true;
      else
        check = false;
        break;
    case (3):
      if (num[0] == num[2])
        check = true;
      else
        check = false;
        break;
    case (4):
      if (num[0] == num[3] && num[1] == num[2])
        check = true;
      else
        check = false;
        break;
    case (5):
      if (num[0] == num[4] && num[1] == num[3])
        check = true;
      else
        check = false;
        break;
    }
    if (check)
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }
  return 0;
}