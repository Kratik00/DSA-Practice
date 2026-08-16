#include <iostream>
using namespace std;

double taylor(int a, int b){
    static double i = 1, j = 1;
    double r;
    if (b==0){
        return 1;
    }else {
        r = taylor(a, b-1);
        i = i * a;
        j = j * b;
        return r + i/j;
    }
}
// By Horner's Rule
double taylor1(double a, double b){
    static double sum = 1;
    if (b == 0)
    {
        return sum;
    }else 
    {
        sum = 1 + a/b * sum;
        return taylor1(a, b-1);
    }
    
}

int main(){
    double result;
    double result1;
    result1 = taylor1(1, 10);
    result = taylor(1, 10);
    cout << result << endl;
    cout << result1 << endl;
    return 0;
}