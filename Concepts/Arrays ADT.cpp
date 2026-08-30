#include <iostream>
using namespace std;

struct Array
{
    int *A;
    int size;
    int length;

};

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void display(struct Array arr)
{
    int i;
    cout << "Elements are: ";
    for(i=0; i<arr.length; i++)
    {
        cout << arr.A[i] << " ";
    }
    cout << "Program Executed without any error" << endl;
}

void append(struct Array *b, int x)
{
    if (b->length < b->size) //b->length equivalent to (*b).length
    {
        b->A[b->length] = x;
        b->length++;
    }
    
}
void insert(struct Array *b, int index, int x)
{
    if (index>=0 && index<=b->length && b->length < b->size)
    {
        for (int i = b->length; i > index; i--)
        {
            b->A[i] = b->A[i-1]; 
        }
        b->A[index] = x;
        b->length++;
        
    }
}

int deleted(struct Array *b, int index)
{
    int x = b->A[index];
    if (index>=0 && index<b->length)
    {
        for (int i = index; i<b->length-1; i++)
        {
            b->A[i] = b->A[i+1];
        }
        b->length--;

    }
    return x;
    
}
//Linear search 
int LinearSearch(struct Array b, int key)
{
    for (int i = 0; i < b.length; i++)
    {
        if (key == b.A[i]){
            return i;
        }
    }
    return -1;
    
}
//Linear search has two types 1. Transposition Method 2. Move to front/head
int LinearSearch1(struct Array *b, int x)
{
    for (int i = 0; i < b->length; i++)
    {
    
        if (x == b->A[i])
        {
            if (i > 0)
            {
                swap(&b->A[i-1], &b->A[i]);
            }
            return i;
        }
        
    }
    return -1;
    
}

//Move to head method
int LinearSearch2(struct Array *b, int x)
{
    for (int i = 0; i < b->length; i++)
    {
        if (x == b->A[i])
        {
            if (i > 0)
            {
                swap(&b->A[i], &b->A[0]);
            }
            return i;
            
        }
        
    }
    return -1;
    
}
//Binary Search
int BinarySearch(struct Array b, int x)
{
    int l, mid, h;
    l = 0;
    h = b.length - 1;
    while (l <= h) 
    {
        mid = (l+h)/2;
        if (b.A[mid] == x)
        {
            return mid;
        }
        else if (b.A[mid] < x)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
        
    }
    return -1;
    
}
// Binary Search recursion based
int RBinarySearch(int a[], int l, int h, int x)
{
    int mid;
    if (l <= h)
    {
        mid = (l + h)/2;
        if (a[mid]==x)
        {
            return mid;
        }
        else if (a[mid] < x)
        {
            return RBinarySearch(a, mid + 1, h, x);
        }
        else
        {
            return RBinarySearch(a, l, mid - 1, x);
        }
        
        
    }
    return -1;
    
}
int get(struct Array b, int index)
{
    if (index >= 0 && index <= b.length)
    {
        return b.A[index];
    }
    return -1;
    
}

int maximum(struct Array b)
{
    int max = b.A[0];
    for (int i = 0; i < b.length; i++)
    {
        if (b.A[i] > max)
        {
            max = b.A[i];
        }
    
    }
    return max;
    
}
int minimum(struct Array b)
{
    int min = b.A[0];
    for (int i = 0; i < b.length; i++)
    {
        if (b.A[i] < min)
        {
            min = b.A[i];
        }
        
    }
    return min;
    
}
int sum(struct Array b)
{
    int total = 0;
    for (int i = 0; i < b.length; i++)
    {
        total += b.A[i];
    }
    return total;
}
int Rsum(struct Array b, int n)
{
    int total = 0;
    if (n < 0)
        return 0;
    else
        return Rsum(b, n-1) + b.A[n];
}
float average(struct Array b)
{
    return (float)sum(b)/b.length;
}
void set(struct Array *b, int index, int x)
{
    if (index >= 0 && index <= b->length)
    {
        b->A[index] = x;
    }
    
}
void reverse(struct Array *b)
{
    int i, j;
    for (i = 0, j = b->length-1 ; i<j; i++, j--)
    {
        swap(&b->A[i], &b->A[j]);
    }
    
}
void InsertSort(struct Array *b, int x)
{
    int i = b->length-1;
    if (b->length==b->size)
    {
        return;
    }
    while (i>=0 && b->A[i]>=x)
    {
        b->A[i+1]=b->A[i];
        i--;
    }
    b->A[i+1]=x;
    b->length++;
    
}
int isSorted(struct Array b)
{
    int i = 0;
    for (i = 0; i < b.length; i++)
    {
        if (b.A[i+1]>b.A[i])
        {
            return 1;
        }
        
    }
    return 0;
    
}
void Rearrange(struct Array *b)
{
    int i = 0, j = b->length-1;
    while (i>j)
    {
        while (b->A[i]<0)i++;
        while (b->A[i]>=0)j--;
        if (i<j)
        {
            swap(&b->A[i+1], &b->A[j]);
        }
        
        
        
    }
    
}
//For merging we need three arrays one for storing both arrays and it only possible only in sorted arrays
struct Array* merging(struct Array *b, struct Array *e)
{
    int i, j, k;
    i = j  = k = 0;
    struct Array *f = new Array; 
    //This only work if Array A already initialized with length like A[20] but here we using pointer version.
    f->size = b->length + e->length;
    f->length = b->length + e->length;
    f->A = new int[f->size];
    while (i<b->length && j<e->length)
    {
        if (b->A[i]<e->A[j])
        {
            f->A[k++] = b->A[i++];
        }
        else
        {
            f->A[k++] = e->A[j++];
        }
        
    } 
    for (; i < b->length; i++)
    {
        f->A[k] = b->A[i];
    }
    for (; j < f->length; j++)
    {
        f->A[k] = e->A[j];
    }
    /* we can use this version also
    while (i<b->length)
    {
        f->A[k++] = b->A[i++];
    }
    while (j<e->length)
    {
        f->A[k++] = e->A[j++];
    }
    */
   return f;
    
}
struct Array* Union(struct Array *b, struct Array *e)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *f = new Array;
    f->size = b->size + e->size;
    f->A = new int[f->size];
    while (i<b->length && j<e->length)
    {
        if (b->A[i]<e->A[j])
        {
            f->A[k++]=b->A[i++];
        }
        else if (b->A[i]>e->A[j])
        {
            f->A[k++]=e->A[j++];
        }
        else
        {
            f->A[k]=b->A[i];
            j++;
        }
        while (i<b->length)
        {
            f->A[k++]=b->A[i++];
        }
        while (j<e->length)
        {
            f->A[k++]=e->A[j++];
        }
           
    }
    f->length=k;
    return f;
    
}
struct Array* intersection(struct Array *b, struct Array *e)
{
    int i, j, k;
    i=j=k=0;
    struct Array *f = new Array;
    f->size = b->length;
    f->A = new int[f->size];
    while (i<b->length && j<e->length)
    {
        if (b->A[i]==e->A[j])
        {
            f->A[k++]=b->A[i++];
            j++;
        }
        else if (b->A[i]<e->A[j])
        {
            i++;
        }
        else
        {
            j++;
        }
        
        
    }
    f->length = k;
    return f;
    
}
struct Array* Difference(struct Array *b, struct Array *e)
{
    int i, j, k;
    i=j=k=0;
    struct Array *f = new Array;
    f->size = b->length;
    f->A = new int[f->size];
    while (i<b->length && j<e->length)
    {
        if (b->A[i]<e->A[j])
        {
            f->A[k++]=b->A[i++];
        }
        else if (b->A[i]>e->A[j])
        {
            j++;
        }
        else
        {
            i++, j++;
        }
    }
    while (i<b->length)
    {
        f->A[k++]=b->A[i++];
    }
    f->length = k;
    return f;
    
};



int main(){
    // Array arr;
    int c[5] = {2, 4, 5, 6, 15};
    Array b = {c, 10, 5}; //{{1, 2, 3, 4}, 10, 4} it cant be initialise without declaring an array because A is pointer and it stores only address but if we define actual array like A[10] then it will work fine.
    int d[5] = {2, 4, 5, 6, 10};
    Array e = {d, 10, 5};
    struct Array *f;
    f = Difference(&b, &e);
    // int i, n;
    // cout << "Enter the size of array: " << endl;
    // cin >> arr.size;
    // arr.A = new int[arr.size];
    // arr.length = 0;
    // cout << "Enter how many no. you want to store: " << endl;
    // cin >> n; 
    // cout << "Enter the all elements in array: " << endl;
    for(int i=0; i<f->length; i++)
    {
        cout << f->A[i] << endl;
    }
    // arr.length = n;
    // display(arr);
    // display(b);
    // append(&b, 5);
    // insert(&b, 2, 10);
    // cout << deleted(&b, 2) << endl;
    // display(b);
    return 0;
}