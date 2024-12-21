#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    stack<int> st;
    int n, count=0,num=1;
    char track[300000];
    bool check=true;
    cin>>n;
    int *input=new int[n];
    for(int i=0;i<n;i++)
        cin>>input[i];
    for(int j=0;j<n&&check==true;j++)
    {
        while(check==true)
        {
            if(st.empty())
            {
                st.push(num++);
                track[count++]='+';
            }
            if(input[j]<st.top())
                check=false;
            if(input[j]==st.top())
            {
                st.pop();
                track[count++]='-';
                break;
            }
            st.push(num++);
            track[count++]='+';
        }
    }
    for(int k=0;k<count&&check==true;k++)
        cout<<track[k]<<"\n";
    if(check==false)
        cout<<"NO";
}