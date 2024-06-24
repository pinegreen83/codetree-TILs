#include <iostream>
#include <string>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string s, t;
    cin >> s >> t;
    int tsize = t.size();
    
    string ans = "";
    for (char c : s) {
        ans += c;

        if (ans.size() >= tsize && ans.substr(ans.size() - tsize) == t) {
            ans.erase(ans.size() - tsize);
        }
    }
    cout << ans;

    return 0;
}