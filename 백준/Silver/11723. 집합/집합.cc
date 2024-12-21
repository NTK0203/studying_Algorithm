#include <iostream>

using namespace std;

bool S[21]={false,};

void add(int);
void remove(int);
void check(int);
void toggle(int);
void all();
void empty();

int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  
  int M, x;
  string input;
  cin>>M;
  for(int i=0;i<M;i++){
    cin>>input;
    
    if(input.compare("add")==0)
    {
      cin>>x;
      add(x);
    }
    else if(input.compare("remove")==0)
    {
      cin>>x;
      remove(x);
    }
    else if(input.compare("check")==0)
    {
      cin>>x;
      check(x);
    }
    else if(input.compare("toggle")==0)
    {
      cin>>x;
      toggle(x);
    }
    else if(input.compare("all")==0)
      all();
    else if(input.compare("empty")==0)
      empty();
  }
}
void add(int x){
  S[x]=true;
}
void remove(int x){
  S[x]=false;
}
void check(int x){
  if(S[x])
    cout<<1<<"\n";
  else
    cout<<0<<"\n";
}
void toggle(int x){
  if(S[x])
    S[x]=false;
  else
    S[x]=true;
}
void all(){
  for(int i=1;i<21;i++)
    S[i]=true;
}
void empty(){
  for(int i=1;i<21;i++)
    S[i]=false;
}