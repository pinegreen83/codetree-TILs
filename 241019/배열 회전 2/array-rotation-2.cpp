#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    int n, ldl, dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {0, 1}};
    cin >> n >> ldl;

    if(ldl < 0) ldl += 360;
    ldl %= 360;

    ldl /= 45;

    vector<vector<int>> map(n, vector<int>(n));
    vector<vector<bool>> check(n, vector<bool>(n, false));
    for(int i=0; i<n; i++) {
        check[i][i] = true;
        check[i][n-i-1] = true;
        check[i][n/2] = true;
        check[n/2][i] = true;
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) cin >> map[i][j];
    }

    vector<pair<int, int>> points;
    vector<vector<int>> remoteMap = map;
    for(int t=0; t<=n/2; t++) {
        points.clear();
        int moves = n - t*2;

        for(int i=t; i<t+moves-1; i++) {
            if(check[t][i]) points.push_back({t, i});
        }
        for(int i=t; i<t+moves-1; i++) {
            if(check[i][t+moves-1]) points.push_back({i, t+moves-1});
        }
        for(int i=t+moves-1; i>t; i--) {
            if(check[t+moves-1][i]) points.push_back({t+moves-1, i});
        }
        for(int i=t+moves-1; i>t; i--) {
            if(check[i][t]) points.push_back({i, t});
        }

        for(int i=0; i<8; i++) {
            int move = (i+ldl) % 8;
            remoteMap[points[move].first][points[move].second] = map[points[i].first][points[i].second];
        }
    }

    for(auto remote : remoteMap) {
        for(auto r : remote) cout << r << " ";
        cout << "\n";
    }

    return 0;
}