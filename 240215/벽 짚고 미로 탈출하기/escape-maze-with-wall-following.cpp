#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<char>> map;
int direction = 0; // 0 : right, 1 : down, 2 : left, 3 : up
vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
vector<vector<int>> rdirs = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

bool isIn(int x, int y)
{
    return 0 <= x && x < n && 0 <= y && y < n;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int answer = 0;
    cin >> n;
    int x, y;

    cin >> x >> y;
    map = vector<vector<char>>(n, vector<char>(n));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> map[i][j];
        }
    }
    x--;
    y--;
    
    int startx = x;
    int starty = y;
    // 진행
    while(true)
    {
        if(answer)
        {
            if(x == startx && y == starty && direction == 0)
            {
                answer = -1;
                break;
            }
        }
        // 진행 방향 앞이 격자 밖일 경우
        int dirx = x+dirs[direction][0];
        int diry = y+dirs[direction][1];
        if(!isIn(dirx, diry)) 
        {
            answer++;
            break;
        }
        // 진행 방향 앞이 격자 안일 경우
        // 진행 방향 앞에 블럭이 있을 경우
        if(map[dirx][diry] == '#')
        {
            // 반시계방향으로 90도 돌리기
            direction -= 1;
            if(direction < 0) direction = 3;
        }
        // 진행 방향 앞에 블럭이 없을 경우
        else
        {
            int rdirx = dirx + rdirs[direction][0];
            int rdiry = diry + rdirs[direction][1];
            // 진행하려는 방향 오른쪽에 벽이 없을 경우
            if(isIn(rdirx, rdiry) && map[rdirx][rdiry] == '.')
            {
                // 시계방향으로 90도 돌리기
                direction++;
                if(direction == 4) direction = 0;
                // 앞으로 진행
                x = rdirx;
                y = rdiry;
                answer+=2;
            }
            // 진행하려는 방향 오른쪽에 벽이 있을 경우
            else if(isIn(rdirx, rdiry) && map[rdirx][rdiry] == '#')
            {
                // 그냥 진행
                x = dirx;
                y = diry;
                answer++;
            }
        }
    }
        
    cout << answer;

    return 0;
}