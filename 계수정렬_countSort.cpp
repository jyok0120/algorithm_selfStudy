#include <iostream>

using namespace std;

int main()
{
    int temp;
    int cnt[6] = {0,}; // ���� ���� ��ŭ �迭�� ������ �Ѵ�. ����� 1 ~ 5�̹Ƿ� ũ�Ⱑ 6
    int arr[30] = {1,3,2,4,5,2,5,3,1,2,3,4,4,3,5,1,2,3,5,2,3,1,4,3,5,1,2,1,1,1};

    for(int i = 0 ; i < 30 ; i++)
        cnt[arr[i]]++;

    for(int i = 0 ; i <= 5 ; i++)
    {
        if(cnt[i] != 0)
        {
            for( int j = 0 ; j < cnt[i] ; j++)
                cout << i << " ";
        }
    }
}
