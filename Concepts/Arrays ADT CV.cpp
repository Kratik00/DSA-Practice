//Class version of Arrays ADT.cpp
#include <iostream>
using namespace std;

class Array
{
private:
    int *A;
    int size;
    int length;
    void swap(int *x, int *y);
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
        A = new int[sz];
        length = 0;
    }
    ~Array()
    {
        delete []A;
    }
    void display();
    void append(int x);
    void insert(int index, int y);
    int deleted(int index);
    int LinearSearch(int key);
    int LinearSearch1(int x);
    int LinearSearch2(int x);
    int BinarySearch(int x);
    int get(int index);
    int maximum();
    int minimum();
    int sum();
    float average();
    void set(int index, int x);
    void reverse();
    void InsertSort(int x);
    int isSorted();
    void Rearrange();
    Array* merging(Array *e);
    Array* Union(Array *e);
    Array* intersection(Array *e);
    Array* difference(Array *e);

};
void Array::swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void Array::display()
{
    cout << "Elements are: ";
    for (int i = 0; i < length; i++)
    {
        cout << A[i] << " ";
    }
    
}
void Array::append(int x)
{
    if (length<size)
    {
        A[length] = x;
        length++;
    }
    
}
void Array::insert(int index, int x)
{
    if (index>=0 && index<length && length<size)
    {
        for (int i = length; i > index; i--)
        {
            A[i] = A[i-1];
        }
        A[index] = x;
        length++;
        
    }
    
}
int Array::deleted(int index)
{
    int x = A[index];
    if (index>=0 && index<length)
    {
        for (int i = index; i < length; i++)
        {
            A[i] = A[i+1];
        }
        length--;
        
    }
    return x;
    
}
int Array::LinearSearch(int key)
{
    for (int i = 0; i < length; i++)
    {
        if (key==A[i])
        {
            return i;
        }
        
    }
    return -1;
    
}
int Array::LinearSearch1(int x)
{
    for (int i = 0; i < length; i++)
    {
        if (x==A[i])
        {
            if (i>0)
            {
                swap(&A[i-1], &A[i]);
            }
            return i;
            
        }
        
    }
    return -1;
    
}
int Array::LinearSearch2(int x)
{
    for (int i = 0; i < length; i++)
    {
        if (x==A[i])
        {
            if (i>0)
            {
                swap(&A[i], &A[0]);
            }
            return i;
            
        }
        
    }
    return -1;
    
}
int Array::BinarySearch(int x)
{
    int l, mid, h;
    l = 0;
    h = length - 1;
    while (l<=h)
    {
        mid = (l+h)/2;
        if (A[mid]<x)
        {
            l = mid+1;
        }
        else if (A[mid]>x)
        {
            h = mid-1;
        }
        else
        {
            return mid;
        }
           
    }
    return -1;
    
}
int Array::get(int index)
{
    if (index>=0 && index<length)
    {
        return A[index];
    }
    return -1;
    
}
int Array::maximum()
{
    int max = A[0];
    for (int i = 0; i < length; i++)
    {
        if (max<A[i])
        {
            max = A[i];
        }
        
    }
    return max;
    
}
int Array::minimum()
{
    int min = A[0];
    for (int i = 0; i < length; i++)
    {
        if (min>A[i])
        {
            min = A[i];
        }
        
    }
    return min;
    
}
int Array::sum()
{
    int Sum = 0;
    for (int i = 0; i < length; i++)
    {
        Sum += A[i];
    }
    return Sum;
    
}
float Array::average()
{
    return (float)sum()/length;
}
void Array::set(int index, int x)
{
    if (index >= 0 && index < length)
    {
        A[index] = x;
    }
    
}
void Array::reverse()
{
    int i, j;
    for (i = 0, j = length - 1; i < j; i++, j--)
    {
        swap(&A[i], &A[j]);
    }
    
}
void Array::InsertSort(int x)
{
    int i = length - 1;
    if (length==size)
    {
        return;
    }
    while (i>=0 && A[i]>=x)
    {
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = x;
    length++;
  
}
int Array::isSorted()
{
    for (int i = 0; i < length; i++)
    {
        if (A[i+1]>A[i])
        {
            return 1;
        }
        
    }
    return 0;
    
}
void Array::Rearrange()
{
    int i = 0;
    int j = length - 1;
    while (A[i]<0)i++;
    while (A[j]>=0)j--;
    if (i<j)
    {
        swap(&A[i+1], &A[j]);
    }
    
}
Array* Array::merging(Array *e)
{
    int i, j, k;
    i = j = k = 0;
    Array *f = new Array;
    f->size = length + e->length;
    f->length = length + e->length;
    f->A = new int[f->size];
    while (i<length && j <e->length)
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
    while (i < length)
    {
        f->A[k++] = A[i++];
    }
    while (j < e->length)
    {
        f->A[k++] = e->A[j++];
    }
    return f;
    
    
    
}
Array* Array::Union(Array *e)
{
    int i, j, k;
    i = j = k = 0;
    Array *f = new Array;
    f->size = length + e->size;
    f->A = new int[f->size];
    while (i < length && j < e->length)
    {
        if (A[i]<e->A[j])
        {
            f->A[k++] = A[i++];
        }
        else if (A[i]>e->A[j])
        {
            f->A[k++]=e->A[j++];
        }
        else
        {
            f->A[k++]=A[i++];
            j++;
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
Array* Array::intersection(Array *e)
{
    int i, j, k;
    i = j = k = 0;
    Array *f = new Array;
    f->size = length;
    f->A = new int[f->size];
    while (i<length && j<e->length)
    {
        if (A[i]<e->A[j])
        {
            i++;
        }
        else if (A[i]>e->A[j])
        {
            j++;
        }
        else
        {
            f->A[k++]=A[i++];
            j++;
        }
         
    }
    f->length=k;
    return f;
    
}
Array* Array::difference(Array *e)
{
    int i, j, k;
    i = j = k = 0;
    Array *f = new Array;
    f->size = length;
    f->A = new int[f->size];
    while (i < length && j < e->length)
    {
       if (A[i]<e->A[j])
       {
            f->A[k++]=e->A[i++];
            j++;
       }
       else if (A[i]>e->A[j])
       {
            j++;
       }
       else
       {
            i++,j++;
       }
    }
    while (i < length)
    {
        f->A[k++]=A[i];
    }
    f->length = k;
    return f;
    
    
}
int main()
{
    Array *b;
    b = new Array();
    b->append(3);
    b->append(5);
    b->append(7);
    b->insert(0, 1);
    Array *y;
    y = new Array();
    y->append(3);
    y->append(6);
    y->append(9);
    y->append(12);
    y->append(15);
    //cout << b->deleted(0)<<endl;
    // cout << b->LinearSearch(5)<<endl;
    // cout << b->LinearSearch1(5)<<endl;
    // cout << b->LinearSearch2(5)<<endl;
    cout << b->average() << endl;
    b->display();
    cout << endl;
    Array *g = b->merging(y);
    g->display();
    return 0; 

}