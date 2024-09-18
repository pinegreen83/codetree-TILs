#include <iostream>
#include <vector>

using namespace std;

int n, maxAns = -10000000, minAns = 100000000;
int dirs[2][2] = {{1, 0}, {0, 1}};
vector<vector<char>> map;

bool isin(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

void DFS(int x, int y, char oper, int sum) {
    if(x == n-1 && y == n-1) {
        maxAns = max(maxAns, sum);
        minAns = min(minAns, sum);
        return;
    }

    for(int d=0; d<2; d++) {
        int dirx = x + dirs[d][0];
        int diry = y + dirs[d][1];

        if(isin(dirx, diry)) {
            if('0' <= map[dirx][diry] && map[dirx][diry] <= '5') {
                switch(oper) {
                    case '+':
                        DFS(dirx, diry, '.', sum + (map[dirx][diry] - '0'));
                    break;
                    case '-':
                        DFS(dirx, diry, '.', sum - (map[dirx][diry] - '0'));
                    break;
                    case 'x':
                        DFS(dirx, diry, '.', sum * (map[dirx][diry] - '0'));
                    break;
                }
            }
            else DFS(dirx, diry, map[dirx][diry], sum);
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    map = vector<vector<char>>(n, vector<char>(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) cin >> map[i][j];
    }

    DFS(0, 0, '.', (map[0][0] - '0'));
    cout << maxAns << " " << minAns;

    return 0;
}