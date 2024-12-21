#include <iostream>
using namespace std;
int sfind (int, int);
int gcd (int,int,int);
int lcm (int,int,int);


int main(){
  int a,b;
  cin>>a>>b;
  int s=sfind(a,b);
  cout<<gcd(a,b,s)<<"\n"<<lcm(a,b,s)<<endl;
  return 0;
}
int sfind(int a,int b){
  if(a<b)
    return a;
  else
    return b;
}

int gcd(int a, int b, int s){
  for(int i=s;i>0;i--){
    if(a%i==0&&b%i==0){
      return i;
    }
  }
}

int lcm(int a, int b, int s){
  for(int i=1;i>0;i++){
    int temp=s*i;
    if(temp%a==0&&temp%b==0){
        return temp;
      }
  }
}