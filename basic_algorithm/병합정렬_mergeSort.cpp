#include <iostream>

// ���� �迭�� ��� �̷� ������ ������ ������ ����� �ٽ� �����ϴ� ������ ���� ���ʿ��� �޸� ����� ���� �� �ִ�.
#define MX 1000
int sortArr[MX];
int cnt = 0;

using namespace std;

// where merge occurs
void mergeArray(int arr[], int start, int mid, int last)
{
    int i = start;
    int j = mid + 1;
    int index = start;

    // �� �� ��ġ��
    while(i <= mid && j <= last)
    {
        if(arr[i] <= arr[j])
        {
            sortArr[index++] = arr[i];
            i++;
        }
        else
        {
            sortArr[index++] = arr[j];
            j++;
        }
    }

    // ���� ������ ����
    if( i > mid)
    {
        for( int k = j ; k <= last; k++)
        {
            sortArr[index++] = arr[k];
        }
    }
    else
    {
        for( int k = i ; k <= last; k++)
        {
            sortArr[index++] = arr[k];
        }
    }

    //���� �迭���� ��¥ �迭�� �ű��
    for( int k = start ; k <= last; k++)
    {
        arr[k] = sortArr[k];
    }

}

// where dividing occurs
void mergeSort(int arr[], int start, int last)
{
    if(start < last)
    {
        int mid = (start + last) >> 1;
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,last);
        mergeArray(arr,start,mid,last);
    }
}


int main()
{

    // array ����
    int n ;
    cin >> n;
    int arr[n];
    for( int i = 0 ; i < n; i++)
        cin >> arr[i];

    // merge Sort
    mergeSort(arr,0,n-1);

    // print
    for(int i = 0 ; i < n ; i++)
        cout << arr[i] <<" ";

}
