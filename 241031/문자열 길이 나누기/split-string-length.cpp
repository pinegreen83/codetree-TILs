#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    string ans;
    for(int i=0; i<n; i++) {
        string temp;
        cin >> temp;

        ans += temp;
    }

    int si = ans.size();
    for(int i=0; i<si/2; i++) cout << ans[i];
    cout << "\n";
    for(int i=si/2; i<si; i++) cout << ans[i];

    return 0;
}