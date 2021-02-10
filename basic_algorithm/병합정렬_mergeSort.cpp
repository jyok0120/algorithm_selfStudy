#include <iostream>

// 정렬 배열의 경우 이런 식으로 전역에 선언을 해줘야 다시 선언하는 과정이 없어 불필요한 메모리 사용을 줄일 수 있다.
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

    // 값 비교 합치기
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

    // 남은 데이터 삽입
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

    //정렬 배열에서 진짜 배열로 옮기기
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

    // array 선언
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
