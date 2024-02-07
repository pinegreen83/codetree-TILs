#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    vector<vector<int>> map(n+1, vector<int>(n+1));
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int x, y;
    cin >> x >> y;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin >> map[i][j];
        }
    }

    bool cont = true;
    while(cont)
    {
        cont = false;
        cout << map[x][y];
        for(int i=0; i<4; i++)
        {
            int dirx = x + dirs[i][0];
            int diry = y + dirs[i][1];
            if(1 <= dirx && dirx <= n && 1 <= diry && diry <= n)
            {
                if(map[dirx][diry] > map[x][y])
                {
                    cout << " ";
                    x = dirx;
                    y = diry;
                    cont = true;
                    break;
                }
            }
        }
    }

    return 0;
}