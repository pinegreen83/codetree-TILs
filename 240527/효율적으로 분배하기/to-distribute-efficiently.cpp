#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    int ans = 100000;
    for(int i=1; i<=n/5; i++)
    {
        int now = n, sum = i;
        now -= 5*i;
        if(now % 3 == 0)
        {
            sum += now / 3;
            ans = min(ans, sum);
        }
    }
    cout << (ans == 100000 ? -1 : ans);

    return 0;
}