#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m, s;
    cin >> n >> m >> s;

    s--;
    vector<vector<char>> map(n, vector<char>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) cin >> map[i][j];
    }

    if(s % 2 == 1) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) cout << 'O';
            cout << "\n";
        }
    }
    else {
        if(s % 4 == 0) {
            for(auto ma : map) {
                for(auto ms : ma) cout << ms;
                cout << "\n";
            }
        }
        else {
            vector<vector<char>> temp(n, vector<char>(m, 'O'));
            int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for(int i=0; i<n; i++) {
                for(int j=0; j<m; j++) {
                    if(map[i][j] == 'O') {
                        for(int d=0; d<4; d++) {
                            int dirx = i + dirs[d][0];
                            int diry = j + dirs[d][1];

                            if(0 <= dirx && dirx < n && 0 <= diry && diry < m) {
                                temp[dirx][diry] = '.';
                            }
                        }
                        temp[i][j] = '.';
                    }
                }
            }

            for(auto tem : temp) {
                for(auto te : tem) cout << te;
                cout << "\n";
            }
        }
    }

    return 0;
}