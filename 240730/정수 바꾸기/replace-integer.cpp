#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a, b;
    cin >> a >> b;

    int cnt = 0;
    while(b > a)
    {
        cnt++;
        if(b % 2 == 0)
        {
            b /= 2;
        }
        else if(b % 10 == 1)
        {
            b /= 10;
        }
        else break;
    }
    if(b == a) cout << cnt;
    else cout << -1;

    return 0;
}