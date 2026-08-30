#include <iostream>
using namespace std;

class Array
{
private:
    int *A;
    int size;
    int length;
public:
    Array()
    {
        size = 10;
        A = new int[size];
        length = 0;
    }
    Array(int sz)
    {
        size = sz;
        A = new int[size];
        length = 0;
    }
    Array(int a[],int sz, int n)
    {
        size = sz;
        A = new int[size];
        length = n;
        for (int i = 0; i < length; i++)
        {
            A[i] = a[i];
        }
        
    }
    ~Array()
    {
        delete []A;
    }
    int missingsingle();
    void missingmultiple();
    void missinginunsroted();

};

int Array::missingsingle()
{
    int diff = A[0];
    for (int i = 0; i < length; i++)
    {
        if (A[i] - i != diff)
        {
            return A[i]-1;
        }
        
    }
    return A[length-1]+1;
    
}
void Array::missingmultiple()
{
    int diff = A[0];
    for (int i = 0; i < length; i++)
    {
        if (A[i]-i!=diff)
        {
           while (diff<A[i]-i)
           {
            cout << i+diff << endl;
            diff++;
           }
            
        }
        
    }
    
}
void Array::missinginunsroted()
{
    int H[15]={0};
    for (int i = 0; i < length; i++)
    {
        H[A[i]]++;
    }
    for (int i = 0; i < length; i++)
    {
        if (H[i]==0)
        {
            cout << i << endl;
        }
        
    }
    
    
}
int main()
{
    int a[11] = {4, 5, 6, 10, 11, 3, 2, 1};
    Array *b;
    b = new Array(a, 11, 11);
    // cout<<b->missingsingle()<<endl;
    // b->missingmultiple();
    b->missinginunsroted();
    delete b;

    return 0;
}

