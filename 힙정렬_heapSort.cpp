#include <iostream>

using namespace std;

int n;
int heap[1000001];

// ������� ���, �ڽ� �������� root�� ����ذ��� ���� ����ȴٸ�,
// ������� ��� root �������� �ڽ��� ����ذ��� �Ʒ��� ����ȴ�.

// �����
void heapify(int i)
{
    // ���� �ڽ� ���
    int ch = 2 * i + 1;
    // ������ �ڽ� ��尡 ���� ���� ū ���
    if( ch < n && heap[ch] < heap[ch+1])
        ch++;

    // �θ� < �ڽ��̸� ��ġ ��ȯ
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


    // �� ����
    for(int i = n/2 ; i >= 0; i--)
    {
        heapify(i);
    }

    // ũ�⸦ �ٿ����� ���� ����
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
            // �ڽ� �� �� ū �� ã��
            if(heap[ch]<heap[ch+1]&& ch < i-1)
            {
                ch++;
            }

            // �θ𺸴� �ڽ��� ũ�� ��ȯ
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

    //���
    for(int i = 0 ; i< n; i++)
        cout << heap[i] << " ";
}
