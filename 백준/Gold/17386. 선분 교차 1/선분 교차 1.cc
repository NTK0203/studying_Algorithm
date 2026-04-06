#include <iostream>
#include <vector>
using namespace std;

int ccw(long long x1, long long x2, long long x3, long long y1, long long y2, long long y3){
    long result = (x2-x1)*(y3-y1)-(y2-y1)*(x3-x1);
    if(result==0)
        return 0;
    else if(result>0)
        return 1;
    return -1;
}

int main(){
    int result=0;
    pair<long, long> p1,p2,p3,p4;
    cin>>p1.first>>p1.second>>p2.first>>p2.second;
    cin>>p3.first>>p3.second>>p4.first>>p4.second;
    if(ccw(p1.first,p2.first,p3.first,p1.second,p2.second,p3.second)!=ccw(p1.first,p2.first,p4.first,p1.second,p2.second,p4.second))
        if(ccw(p3.first,p4.first,p1.first,p3.second,p4.second,p1.second)!=ccw(p3.first,p4.first,p2.first,p3.second,p4.second,p2.second))
            result=1;
    cout<<result;
}