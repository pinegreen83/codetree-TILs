#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string str;
    cin >> str;

    int two = 1, ans = 0;
    for(auto i=str.end()-1; i>=str.begin(); i--) {
        if((char)*i == '1') ans += two;
        two *= 2;
    }
    cout << ans;

    return 0;
}