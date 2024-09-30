#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    string str;
    cin >> str;

    int ans = 0;
    char last;
    for(auto c : str) {
        if(last != c) ans += 10;
        else ans += 5;
        last = c;
    }
    cout << ans;

    return 0;
}