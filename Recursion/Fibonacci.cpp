#include <iostream>
using namespace std;

int fibonacci(int n){
    if (n <= 1){
        return n;
    }else{
        return fibonacci(n-2) + fibonacci(n-1);
    }
}
/* By Memorization Method */
int fb[10];
int fib(int n){
    if (n <= 1){
        fb[n] = n;
        return n;
    }else{
        if (fb[n-2] == -1)
        {
            fb[n-2] = fib(n-2);
        }
        if (fb[n-1] == -1)
        {
            fb[n-1] = fib(n-1);
        }
        return fb[n-2] + fb[n-1];
        
    }
}
int main(){
    int result;
    int res;
    for (int i = 0; i < 10; i++){
        fb[i] = -1;
    }
    result = fibonacci(6);
    res = fib(6);
    cout << res << endl;
    cout << result << endl;
    return 0;
}