#include <iostream>

using namespace std;

void insertionSort(int* data, int n)
{
    // 오름차순
    int tmp;
    for(int i = 0 ; i < n ; i++)
    {
        for( int j = i-1 ; j >= 0 && data[j] > data[j+1]; j--)
        {
            tmp = data[j+1];
            data[j+1] = data[j];
            data[j] = tmp;
        }
    }
}

void Insertionsort(int* data, int n)
{
    // 내림차순
    int tmp;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i-1; j>=0 && data[j] < data[j+1]; j--)
        {
            tmp = data[j+1];
            data[j+1] = data[j];
            data[j] = tmp;
        }
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

    // insertion sort part
    insertionSort(a,n);
    //Insertionsort(a,n);

    // print
    for( int i = 0 ; i < n ; i++)
        cout << a[i] << " ";
}
