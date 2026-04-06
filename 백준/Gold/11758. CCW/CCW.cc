#include <iostream>
#include <vector>
using namespace std;

int ccw(int x1, int x2, int x3, int y1, int y2, int y3){
    int result = (x2-x1)*(y3-y1)-(y2-y1)*(x3-x1);
    if(result==0)
        return 0;
    else if(result>0)
        return 1;
    return -1;

}

int main(){
    vector<pair<int,int>> v;
    for(int i=0;i<3;i++){
        pair<int,int> p;
        cin>>p.first>>p.second;
        v.push_back(p);
    }
    cout<<ccw(v[0].first,v[1].first,v[2].first,v[0].second,v[1].second,v[2].second);
}