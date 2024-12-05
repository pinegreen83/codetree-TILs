#include <iostream>
#include <vector>

using namespace std;

int n;

bool isin(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    vector<vector<char>> map(n, vector<char>(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) cin >> map[i][j];
    }

    vector<vector<char>> player(n, vector<char>(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) cin >> player[i][j];
    }

    int dirs[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(player[i][j] == 'x') {
                int cnt = 0;
                for(int d=0; d<8; d++) {
                    int dirx = i + dirs[d][0];
                    int diry = j + dirs[d][1];

                    if(isin(dirx, diry) && map[dirx][diry] == '*') cnt++;
                }
                cout << cnt;
            }
            else cout << '.';
        }
        cout << "\n";
    }

    return 0;
}