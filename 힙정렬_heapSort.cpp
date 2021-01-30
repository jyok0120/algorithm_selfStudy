#include <iostream>

using namespace std;

int n;
int heap[1000001];

// 상향식의 경우, 자식 기준으로 root를 계산해가며 위로 진행된다면,
// 하향식의 경우 root 기준으로 자식을 계산해가며 아래로 진행된다.

// 하향식
void heapify(int i)
{
    // 왼쪽 자식 노드
    int ch = 2 * i + 1;
    // 오른쪽 자식 노드가 왼쪽 보다 큰 경우
    if( ch < n && heap[ch] < heap[ch+1])
        ch++;

    // 부모 < 자식이면 위치 교환
    if(heap[i] < heap[ch])
    {
        int temp = heap[i];
        heap[i] = heap[ch];
        heap[ch] = temp;
    }

    if( ch <= n/2) heapify(ch);
}

int main()
{

    cin >> n;

    for(int i = 0 ; i < n; i++)
        cin >> heap[i];


    // 힙 생성
    for(int i = n/2 ; i >= 0; i--)
    {
        heapify(i);
    }

    // 크기를 줄여가며 정렬 진행
    for(int i = n-1; i >= 0; i--)
    {

        int temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;
        int root = 0;
        int ch = 1;
        do
        {
            ch = 2 * root + 1;
            // 자식 중 더 큰 값 찾기
            if(heap[ch]<heap[ch+1]&& ch < i-1)
            {
                ch++;
            }

            // 부모보다 자식이 크면 교환
            if(ch < i && heap[root]< heap[ch])
            {
                int temp = heap[root];
                heap[root] = heap[ch];
                heap[ch] = temp;
            }
            root = ch;
        }
        while(ch < i);
    }

    //출력
    for(int i = 0 ; i< n; i++)
        cout << heap[i] << " ";
}
