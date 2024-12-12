#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

bool isin(int x, int y) {
    return 0 <= x && x <= 1000 && 0 <= y && y <= 1000;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n, x, y;
    cin >> n >> x >> y;

    bool map[1001][1001] = {false};
    bool visited[1001][1001] = {false};
    while(n--) {
        int a, b;
        cin >> a >> b;
        map[a][b] = true;
    }

    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    pq.push({0, x, y});
    visited[x][y] = true;

    while(!pq.empty()) {
        int cnt, nowx, nowy;
        tie(cnt, nowx, nowy) = pq.top();
        pq.pop();

        if(nowx == 0 && nowy == 0) {
            cout << cnt;
            break;
        }

        for(int d=0; d<4; d++) {
            int nextx = nowx + dirs[d][0];
            int nexty = nowy + dirs[d][1];

            if(isin(nextx, nexty) && !visited[nextx][nexty]) {
                visited[nextx][nexty] = true;
                if(map[nextx][nexty]) {
                    pq.push({cnt+1, nextx, nexty});
                }
                else pq.push({cnt, nextx, nexty});
            }
        }
    }

    return 0;
}