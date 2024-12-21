#include <iostream>
#include <string>
using namespace std;
class stack{
    private:
        int index[100000];
        int capacity;
        bool isempty;
    public:
        stack(){
            capacity=0;
            isempty=true;
        }
        void push(int X)
        {
            if(isempty)
                isempty=false;
            index[capacity++]=X;
        }
        int pop()
        {
            if(isempty)
                return -1;
            int num=index[--capacity];
            if(capacity==0)
                isempty=true;
            return num;
        }
        int size(){
            return capacity;
        }
        int empty(){
            return isempty?1:0;
        }
        int top()
        {
            if(isempty)
                return -1;
            return index[capacity-1];
        }
};
int main(){
    stack st;
    int N,num;
    string input;
    cin>>N;
    cin.ignore();
    for(int i=0;i<N;i++)
    {
        cin>>input;
        cin.ignore();
        if(input.find("push")!=string::npos)
        {
            cin>>num;
            cin.ignore();
            st.push(num);
        }
        else if(input.find("pop")!=string::npos)
            cout<<st.pop()<<"\n";
        else if(input.find("size")!=string::npos)
            cout<<st.size()<<"\n";
        else if(input.find("empty")!=string::npos)
            cout<<st.empty()<<"\n";
        else if(input.find("top")!=string::npos)
            cout<<st.top()<<"\n";
    }
}