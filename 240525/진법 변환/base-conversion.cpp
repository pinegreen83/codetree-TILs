#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string n;
    int m;
    cin >> n >> m;

    int num = 1, ans = 0;
    for(int i=n.size()-1; i>=0; i--)
    {
        char now = n[i];
        if('0' <= now && now <= '9')
        {
            ans += (now - '0') * num;
        }
        else ans += (now - 'A' + 10) * num;
        num *= m;
    }
    cout << ans;

    return 0;
}