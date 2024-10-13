#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;

    char nums[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd','e','f'};

    string ans = "";
    while(n > 0) {
        ans += nums[n % m];
        n /= m;
    }

    for(int i=ans.size()-1; i>=0; i--) cout << ans[i];

    return 0;
}