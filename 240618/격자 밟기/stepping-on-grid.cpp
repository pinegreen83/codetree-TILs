#include <iostream>

using namespace std;

int k, movecnt, ans = 0;
int map[6][6], dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool visited[6][6];

bool isin(int x, int y)
{
    return 1 <= x && x <= 5 && 1 <= y && y <= 5;
}

void backtrack(int cnt, int r1, int c1, int r2, int c2)
{
    if(movecnt == cnt)
    {
        if(r1 == r2 && c1 == c2) ans++;
        return;
    }
    else
    {
        if(r1 == r2 && c1 == c2) return;
    }
    for(int i=0; i<4; i++)
    {
        int dirr1 = r1 + dirs[i][0];
        int dirc1 = c1 + dirs[i][1];
        if(isin(dirr1, dirc1) && !visited[dirr1][dirc1])
        {
            if(!map[dirr1][dirc1])
            {
                for(int j=0; j<4; j++)
                {
                    int dirr2 = r2 + dirs[j][0];
                    int dirc2 = c2 + dirs[j][1];
                    if(isin(dirr2, dirc2) && !visited[dirr2][dirc2])
                    {
                        if(!map[dirr2][dirc2])
                        {
                            visited[dirr1][dirc1] = true;
                            visited[dirr2][dirc2] = true;
                            backtrack(cnt+1, dirr1, dirc1, dirr2, dirc2);
                            visited[dirr1][dirc1] = false;
                            visited[dirr2][dirc2] = false;
                        }
                    }
                }
            }
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> k;
    for(int i=0; i<k; i++)
    {
        int r, c;
        cin >> r >> c;
        map[r][c] = 1;
    }
    movecnt = (25 - k) / 2;

    visited[1][1] = true;
    visited[5][5] = true;
    backtrack(0, 1, 1, 5, 5);
    cout << ans;

    return 0;
}