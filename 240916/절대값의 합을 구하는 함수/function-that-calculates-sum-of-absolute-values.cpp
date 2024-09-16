#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, a, ans = 0;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> a;
        ans += abs(a);
    }
    cout << ans;

    return 0;
}