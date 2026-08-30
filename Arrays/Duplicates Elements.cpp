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
    void duplicateelements();
    void duplicateElementsHash(int max);
    void UDuplicateElements(); //Bruteforce Technique for Finding Duplicates in an Unsorted Array
};
//Only for Sorted Arrays
void Array::duplicateelements()
{
    for (int i = 0; i < length-1; i++)
    {
        if (A[i]==A[i+1])
        {
            int j = i + 1;
            while (j < length && A[j]==A[i]) j++;
            cout << A[i] << " comes " << j-i << " times." << endl;
            i = j-1;

        }
        
    }
    
}
//By Hash Table method for Sorted Arrays
void Array::duplicateElementsHash(int max)
{
    int H[25] = {0};
    for (int i = 0; i < length; i++)
    {
        H[A[i]]++;
    }
    for (int i = 0; i < max; i++)
    {
        if (H[i]>1)
        {
            cout << i << " comes " << H[i] << " times." << endl;
        }
        
    }
    
    
}
void Array::UDuplicateElements()
{
    for (int i = 0; i < length; i++)
    {
        int count = 1;
        if (A[i] != -1)
        {
            for (int j = i+1; j < length; j++)
            {
                if (A[i]==A[j])
                {
                    count++;
                    A[j]=-1;
                }
                
            }
            if (count>1)
            {
                cout << A[i] << ", " << count << endl;
            }
            
        }
        
    }
    
}
int main()
{
    int a[10] = {8, 3, 6, 4, 6, 5, 6, 8, 2, 7};
    Array *b = new Array(a, 15, 10);
    // b->duplicateelements();
    b->duplicateElementsHash(20);
    //b->UDuplicateElements();
    return 0;
}