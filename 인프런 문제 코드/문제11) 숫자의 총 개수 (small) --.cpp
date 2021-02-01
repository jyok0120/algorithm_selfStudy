#include <iostream>

using namespace std;

int main(){
    int N, ans = 0, cnt;
    cin >> N;

    for( int i = 1 ; i <= N; i++)
    {
        int cur = i;
        while(cur)
        {
            cur /= 10;
            ans++;
        }
    }
    cout << ans;
}