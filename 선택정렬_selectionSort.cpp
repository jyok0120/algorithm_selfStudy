#include <iostream>

using namespace std;

void selectionSort(int* data, int n)
{
    int Min, index, tmp;
    for( int i = 0 ; i < n ; i++)
    {
        Min = INT_MAX;
        for( int j = i ; j < n; j++)
        {
            if(Min > data[j])
            {
                Min = data[j];
                index = j;
            }
        }
        tmp = data[i];
        data[i] = data[index];
        data[index] = tmp;
    }
}

void Selectionsort(int* data, int n)
{
    int Max, index, tmp;
    for(int i = 0 ; i < n; i++)
    {
        Max = INT_MIN;
        for(int j = i; j < n; j++)
        {
            if(Max < data[j])
            {
                Max = data[j];
                index = j;
            }
        }
        tmp = data[i];
        data[i] = data[index];
        data[index] = tmp;
    }
}

int main()
{
    // get the array
    int n;
    cin >> n;
    int a[n];
    for( int i = 0 ; i < n ; i++)
        cin >> a[i];

    // selection sort part

    selectionSort(a,n);
    //Selectionsort(a,n);

    // print
    for( int i = 0 ; i < n ; i++)
        cout << a[i] << " ";
}
