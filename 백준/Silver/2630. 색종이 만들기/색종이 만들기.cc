#include <iostream>
using namespace std;
void divisor(int, int, int, bool**);
int b=0,w=0;

int main(){
    int N;
    cin>>N;
    bool **paper=new bool*[N];
    int i,j;
    for(i=0;i<N;i++)
        paper[i]=new bool[N];
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            cin>>paper[i][j];
    divisor(0,0,N,paper);
    cout<<w<<"\n"<<b<<"\n";
}
void divisor(int width, int length, int scale, bool **paper)
{
    bool check=paper[width][length];
    bool test=true;
    for(int i=width;i<width+scale;i++)
        for(int j=length;j<length+scale;j++)
        {
            if(check!=paper[i][j])
            {
                divisor(width,length,scale/2,paper);
                divisor(width+scale/2,length,scale/2,paper);
                divisor(width,length+scale/2,scale/2,paper);
                divisor(width+scale/2,length+scale/2,scale/2,paper);
                return;
            }
        }
    if(check==true)
        b++;
    else if(check==false)
        w++;
}