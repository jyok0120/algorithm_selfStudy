#include <iostream>

using namespace std;

void bubbleSort(int* data, int n)
{
    // 오름차순
    int tmp;
    for(int i = 0 ; i < n ; i++)
    {
        for( int j = 0 ; j < ((n-1) - i); j++)
        {
            if(data[j]>data[j+1])
            {
                tmp = data[j+1];
                data[j+1] = data[j];
                data[j] = tmp;
            }
        }
    }
}

void Bubblesort(int* data, int n)
{
    // 내림차순
    int tmp;
    for(int i = 0 ; i < n ; i++)
    {
        for( int j = 0; j < ((n-1)-i); j++)
        {
            if(data[j] < data[j+1])
            {
                tmp = data[j+1];
                data[j+1] = data[j];
                data[j] = tmp;
            }
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

    // bubble sort part
    bubbleSort(a,n);
    //Bubblesort(a,n);

    // print
    for( int i = 0 ; i < n ; i++)
        cout << a[i] << " ";
}
