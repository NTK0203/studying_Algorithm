#include <iostream>
using namespace std;
int main(){
  int N,num;
  int count=0;
  cin>>N;
  for(int i=0;i<N;i++){
    bool check=true;
    cin>>num;
    if(num==1)
      continue;

    for(int j=num-1;j>1;j--){
      if(num%j==0)
      {
        check=false;
        break;
      }
    }
    if(check==true)
      count++;
  }
  cout<<count;
  return 0;
}