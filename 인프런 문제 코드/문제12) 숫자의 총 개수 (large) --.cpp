#include <iostream>

using namespace std;

int main(){
    int N, cnt = 0, level = 1;
    cin >> N;
    
    while(N)
    {
        cnt += N%10 * level++;
        N /= 10;
         cout << cnt << " ";

    }
    cout << cnt;
}

