#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> belt;
    vector<bool> robot;
    int n, k, cnt=0;

    belt.push_back(0); //dummy
    robot.push_back(false); //dummy
    cin>>n>>k;
    int up=1, down=n;

    for(int i=1;i<=n*2;i++){
        int a;
        cin>>a;
        belt.push_back(a);
        robot.push_back(false);
    }
    while(k>0){
        cnt++;
        up=(up-1) + ((up-1)==0?2*n:0);
        down=(down-1) + ((down-1)==0?2*n:0);
        if(robot[down])
            robot[down]=false;
        int cur=down, next=down+1;
        for(int i=0;i<n;i++){
            cur=(cur-1) + ((cur-1)==0?2*n:0);
            next=(next-1) + ((next-1)==0?2*n:0);

            if(robot[cur] && belt[next]>0 && !robot[next]){
                robot[cur]=false;
                robot[next]=true;

                if(--belt[next]==0)
                    k--;

                if(robot[down])
                    robot[down]=false;
            }
        }
        if(belt[up]>0){
            if(--belt[up]==0)
                k--;
            robot[up]=true;
        }
    }
    cout<<cnt;
}