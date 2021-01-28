#include <iostream>

using namespace std;

void quickSort(int* data, int start, int last)
{
    if(start>=last)
    {
        return; // only one element. no need to sort
    }

    int pivot = start;
    int big = start +1;
    int small = last;
    int tmp;

    while(big <= small)
    {
        while(big <= last && data[big] <= data[pivot])
        {
            big++;
        }

        while(data[small] >= data[pivot] && small > start)
        {
            small--;
        }

        if(big > small)
        {
            // 엇갈림이 발생하는 순간
            tmp = data[small];
            data[small]=data[pivot];
            data[pivot]=tmp;
        }
        else
        {
            tmp = data[big];
            data[big]=data[small];
            data[small]=tmp;
        }
    }

    // divide and conquer
    quickSort(data, start,small-1);
    quickSort(data, small+1,last);
}

void Quicksort(int* data, int start, int last)
{
    if(start>=last)
    {
        return; // only one element. no need to sort
    }

    int pivot = start;
    int small = start +1;
    int big = last;
    int tmp;

    while(small <= big)
    {
        while(small <= last && data[small] >= data[pivot])
        {
            small++;
        }
        while(big > start && data[big] <= data[pivot])
        {
            big--;
        }

        if(small > big)
        {
            // 엇갈림 발생하는 순간
            tmp = data[big];
            data[big] = data[pivot];
            data[pivot] = tmp;
        }
        else
        {
            tmp = data[big];
            data[big] = data[small];
            data[small] = tmp;
        }
    }

    // divide and conquer
    Quicksort(data, start, big-1);
    Quicksort(data, big+1, last);
}


int main()
{
    // get the array
    int n;
    cin >> n;
    int a[n];
    for( int i = 0 ; i < n ; i++)
        cin >> a[i];

    // quick sort called
    cout << "오름차순" << endl;
    quickSort(a,0,n-1);
    //cout << "내림차순" << endl;
    //Quicksort(a,0,n-1);

    // print
    for( int i = 0 ; i < n ; i++)
        cout << a[i] << " ";
}
