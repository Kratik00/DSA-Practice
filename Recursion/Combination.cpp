#include <iostream>
using namespace std;

int comb(int n, int r){
    if (r == 0 || n == r)
    {
        return 1;
    }
    else
    {
        return comb(n-1, r) + comb(n-1, r-1);
    }
    
}

int main(){
    int combination;
    combination = comb(5, 3);
    cout << combination << endl;
    return 0;
}