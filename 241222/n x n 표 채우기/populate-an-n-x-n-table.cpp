#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;

    int dirs[5][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<int>> map(n+1, vector<int>(n+1));
    int idx = 1, num = 1, x = n/2 + 1, y = n/2 + 1;
    map[x][y] = idx++;
    x--;
    num += 2;
    for(int i=0; i<5; i++) {
        int move;
        if(i == 0 || i == 4) move = (num-1) / 2;
        else move = num-1;
        for(int j=0; j<move; j++) {
            map[x][y] = idx++;
            x += dirs[i][0];
            y += dirs[i][1];
        }
    }
    num += 2;

    while(num <= n)
    {
        x--;
        map[x][y] = idx++;
        for(int i=0; i<4; i++) {
            int move;
            if(i == 0) move = num - 2;
            else move = num - 1;
            for(int j=0; j<move; j++) {
                x += dirs[i][0];
                y += dirs[i][1];
                map[x][y] = idx++;
            }
        }
        num += 2;
    }

    int ax, ay;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(map[i][j] == m) {
                ax = i;
                ay = j;
            }
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    cout << ax << " " << ay;

    return 0;
}