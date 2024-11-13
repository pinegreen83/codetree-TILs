#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;

    vector<int> blocks(m);
    for(int i=0; i<m; i++) cin >> blocks[i];

    int ans = 0;
    for(int i=0; i<m; i++) {
        int left = blocks[i];
        for(int j=i-1; j>=0; j--) {
            left = max(left, blocks[j]);
        }
        int right = blocks[i];
        for(int j=i+1; j<m; j++) {
            right = max(right, blocks[j]);
        }
        
        ans += min(left, right) - blocks[i];
    }
    cout << ans;

    return 0;
}