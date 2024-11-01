#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int r, c, w;
    cin >> r >> c >> w;

    int h = r+w;
    vector<vector<int>> tri(h+1, vector<int>(h+1, 0));
    for(int i=1; i<=h; i++) {
        tri[i][i] = 1;
        tri[i][1] = 1;
    }

    for(int i=3; i<=h; i++) {
        for(int j=2; j<i; j++) {
            tri[i][j] = tri[i-1][j-1] + tri[i-1][j];
        }
    }

    long long ans = 0;
    int idx = 1;
    for(int i=r; i<r+w; i++) {
        for(int j=c; j<c+idx; j++) {
            ans += tri[i][j];
        }
        idx++;
    }
    cout << ans;
    
    return 0;
}