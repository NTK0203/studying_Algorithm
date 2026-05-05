#include <string>
#include <vector>

using namespace std;

int c, d;

int cola(int n){
    if(n<c)
        return 0;
    
    return n/c*d + cola(n/c*d + n%c);
}

int solution(int a, int b, int n) {
    c=a;
    d=b;
    return cola(n);
}