#include <iostream>
#include <string.h>
using namespace std;

int main(){
  int T,check;
  char input[51];
  cin>>T;
  for(int i=0;i<T;i++){
    cin>>input;
    check=0;
    for(int j=0;j<strlen(input);j++){
      if(check<0)
          break;
      if(input[j]=='(')
        check++;
      else
        check--;
    }
    if(check==0)
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
  }
}