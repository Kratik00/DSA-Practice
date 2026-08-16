#include <iostream>
using namespace std;
int exponent1(int a, int b){
    if (b == 0){
        return 1;
    } else{
        return exponent1(a, b-1)*a;
    }
}
// By less stack memory
int exponent(int a, int b){
    if (b==0){
        return 1;
    }
    if (b%2==0){
        return exponent(a*a, b/2);
    } else{
        return a*exponent(a*a, (b-1)/2);
    }
}

int main(){
    int result1, result;
    result = exponent(4, 5);
    result1 = exponent1(4, 5);
    cout << result1 << endl;
    cout << result << endl;
    return 0;
}