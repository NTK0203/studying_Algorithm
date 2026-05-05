#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    for(int i=1;i<=number;i++){
        int atk=0;
        for(int j=1;j*j<=i;j++){
            if(i%j==0){
                atk++;
                if(j*j!=i)
                    atk++;
            }
        }
        if(atk>limit)
            answer+=power;
        else
            answer+=atk;
    }
    return answer;
}