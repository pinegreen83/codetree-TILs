#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string a, b;
    cin >> a >> b;

    int idx = 0, s = b.size(), ans = 0;
    while(idx < s) {
        ans++;
        for(int i=0; i<a.size(); i++) {
            if(a[i] == b[idx]) {
                idx++;
                if(idx == s) break;
            }
        }
    }
    cout << ans;

    return 0;
}