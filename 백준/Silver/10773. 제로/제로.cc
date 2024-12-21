#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    long long input, result=0;
    stack<long long> st;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>input;
        if(input==0)
        {
            st.pop();
        }
        else
            st.push(input);
    }
    while(!st.empty())
    {
        result+=st.top();
        st.pop();
    }
    cout<<result;
}