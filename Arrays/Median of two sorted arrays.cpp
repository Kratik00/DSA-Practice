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
    Array(int a[], int sz, int n)
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
    Array* merging(Array *e);
    float median(Array *f);
};

Array* Array::merging(Array *e)
{
    int i, j, k;
    i = j = k = 0;
    Array *f = new Array;
    f->size = length + e->length;
    f->A = new int[f->size];
    while (i < length && j<e->length)
    {
        if (A[i]<e->A[j])
        {
            f->A[k++] = A[i++];   
        }

        else
        {
            f->A[k++] = e->A[j++];
        }  
    }
    while (i<length)
    {
        f->A[k++]=A[i++];
    }
    while (j<e->length)
    {
        f->A[k++]=e->A[j++];
    }
    f->length = k;
    return f;
  
}

float Array::median(Array *f)
{
    if (f->length%2!=0)
    {
        int k = (f->length+1)/2;
        return f->A[k-1];
    }
    else
    {
        int k = (f->length/2);
        return (f->A[k-1]+f->A[k])/2.0f;
    }
    
}

int main()
{
    int a[2] = {1, 2};
    Array *b = new Array(a, 4, 2);
    int d[2] = {3, 4};
    Array *e = new Array(d, 4, 2);
    Array *g = b->merging(e);
    cout << (float)g->median(g) << endl;

    delete b;
    delete e;
    delete g;
    return 0;
}
// IT WOULD ONLY CORRECT FOR THE O(M+N) TIME COMPLEXITY.