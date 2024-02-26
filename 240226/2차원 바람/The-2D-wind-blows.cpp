#include <iostream>
#include <vector>

using namespace std;

int n, m, q;
vector<vector<int>> map;
vector<vector<int>> newmap;
vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isin(int x, int y)
{
    return 0 <= x && x < n && 0 <= y && y < m;
}

void wind(int sx, int sy, int ex, int ey) // 1 1 3 5
{
    int temp = map[sx][ey];
    for(int j=ey; j>sy; j--)
    {
        map[sx][j] = map[sx][j-1];
    }
    for(int i=sx; i<ex; i++)
    {
        map[i][sy] = map[i+1][sy];
    }
    for(int i=sy; i<ey; i++)
    {
        map[ex][i] = map[ex][i+1];
    }
    for(int i=ex; i>sx; i--)
    {
        map[i][ey] = map[i-1][ey];
    }
    map[sx+1][ey] = temp;
}

void calcavg(int x, int y)
{
    int cnt = 1;
    int now = map[x][y];
    for(int i=0; i<4; i++)
    {
        int dirx = x + dirs[i][0];
        int diry = y + dirs[i][1];
        if(isin(dirx, diry)) 
        {
            now += map[dirx][diry];
            cnt++;
        }
    }
    newmap[x][y] = now / cnt;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m >> q;
    int a;
    for(int i=0; i<n; i++)
    {
        vector<int> temp;
        for(int j=0; j<m; j++)
        {
            cin >> a;
            temp.push_back(a);
        }
        map.push_back(temp);
    }

    while(q > 0)
    {
        int startx, starty, endx, endy;
        cin >> startx >> starty >> endx >> endy;

        wind(startx-1, starty-1, endx-1, endy-1);

        newmap = map;
        for(int i=startx-1; i<endx; i++)
        {
            for(int j=starty-1; j<endy; j++)
            {
                calcavg(i, j);
            }
        }
        map = newmap;

        q--;
    }

    for(auto& m : map)
    {
        for(auto& i : m) cout << i << " ";
        cout << endl;
    }

    return 0;
}