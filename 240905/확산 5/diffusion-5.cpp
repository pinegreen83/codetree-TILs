#include <iostream>
#include <vector>

using namespace std;

int n, m, s, ans = 0, dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<int> now;
vector<vector<int>> map, temp;
vector<pair<int, int>> vpzero;

bool isin(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

void DFS(int x, int y) {
    for(int d=0; d<4; d++) {
        int dirx = x + dirs[d][0];
        int diry = y + dirs[d][1];

        if(isin(dirx, diry) && temp[dirx][diry] == 0) {
            temp[dirx][diry] = 2;
            DFS(dirx, diry);
        }
    }
}

void MakeMap() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(temp[i][j] == 2) {
                DFS(i, j);
            }
        }
    }

    int cnt = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(temp[i][j] == 0) cnt++;
        }
    }

    ans = max(ans, cnt);
}

void Comb(int cnt, int idx) {
    if(cnt == 3) {
        temp = map;
        for(int i=0; i<3; i++) {
            pair<int, int> np = vpzero[now[i]];
            temp[np.first][np.second] = 1;
        }
        MakeMap();
        return;
    }

    for(int i=idx; i<s; i++) {
        now.push_back(i);
        Comb(cnt+1, i+1);
        now.pop_back();
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;

    map = vector<vector<int>>(n, vector<int>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> map[i][j];
            if(map[i][j] == 0) {
                vpzero.push_back({i, j});
            }
        }
    }

    s = vpzero.size();

    Comb(0, 0);
    cout << ans;

    return 0;
}