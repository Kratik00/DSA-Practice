#include <iostream>
using namespace std;

class Array
{
private:
    int *A;
    int size;
    int length;
public:
    Array(int a[], int sz, int n)
    {
        size = sz;
        A = new int[size];
        length = n;
        for (int i = 0; i < length; i++)
        {
            A[i]=a[i];
        }    
    }
    ~Array()
    {
        delete []A;
    }
    void PairSum(int sum);
};
void Array::PairSum(int sum)
{
    for (int i = 0; i < length-1; i++)
    {
        for (int j = i+1; j < length; j++)
        {
            if (A[i]+A[j]==sum)
            {
                cout << A[i] << "," << A[j] << endl;
            }
            
        }
        
    }
    
}
int main()
{
    int a[10] = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14};
    Array *b = new Array(a, 15, 10);
    b->PairSum(10);
    return 0;
}