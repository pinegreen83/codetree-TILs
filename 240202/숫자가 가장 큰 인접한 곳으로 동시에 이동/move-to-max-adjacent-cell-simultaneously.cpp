#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m, t;
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    cin >> n >> m >> t;

    vector<vector<int>> map(n, vector<int>(n));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> map[i][j];
        }
    }

    vector<vector<int>> marble(n, vector<int>(n));
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin >> a >> b;
        marble[a-1][b-1]++;
    }

    for(int time=1; time<=t; time++)
    {
        vector<vector<int>> temp(n, vector<int>(n));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(marble[i][j] == 1)
                {
                    int maxx = 0;
                    int maxy = 0;
                    int tempnum = 0;
                    for(int d=0; d<4; d++)
                    {
                        int dirx = i + dirs[d][0];
                        int diry = j + dirs[d][1];
                        if(0 <= dirx && dirx < n && 0 <= diry && diry < n)
                        {
                            if(map[dirx][diry] > tempnum)
                            {
                                tempnum = map[dirx][diry];
                                maxx = dirx;
                                maxy = diry;
                            }
                        }
                    }
                    temp[maxx][maxy]++;
                }
            }
        }

        marble = temp;
        for(int ni=0; ni<n; ni++)
        {
            for(int nj=0; nj<n; nj++)
            {
                if(marble[ni][nj] > 1)
                {
                    m -= marble[ni][nj];
                    marble[ni][nj] = 0;
                }
            }
        }
    }

    cout << m;

    return 0;
}