#include <iostream>
#include <queue>

using namespace std;

struct Move {
    int x, y, time;
};

bool isin(int x, int y) {
    return 0 <= x && x < 8 && 0 <= y && y < 8;
}

int main() {
    // 여기에 코드를 작성해주세요.
    char map[8][8];
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) cin >> map[i][j];
    }

    int dirs[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    queue<Move> q;
    q.push(Move{7, 0, 0});

    bool canMove = false;
    while(!q.empty()) {
        Move now = q.front();
        q.pop();

        if(now.x == 0 && now.y == 7) {
            canMove = true;
            break;
        }

        char temp[8][8];
        for(int i=0; i<8; i++) {
            for(int j=0; j<8; j++) temp[i][j] = '.';
        }

        for(int i=0; i<8; i++) {
            for(int j=0; j<8; j++) {
                if(map[i][j] == '#' && i+now.time < 8) {
                    temp[i+now.time][j] = '#';
                }
            }
        }

        if(temp[now.x][now.y] != '#') {
            for(int d=0; d<8; d++) {
                int dirx = now.x + dirs[d][0];
                int diry = now.y + dirs[d][1];

                if(isin(dirx, diry)) {
                    if(temp[dirx][diry] == '.') {
                        q.push(Move{dirx, diry, now.time+1});
                    }
                }
            }
        }
    }
    cout << canMove;

    return 0;
}