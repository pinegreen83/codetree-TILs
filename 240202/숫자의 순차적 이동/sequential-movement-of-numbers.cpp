#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    vector<vector<int>> map(n, vector<int>(n));
    vector<vector<int>> dirs = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> map[i][j];
        }
    }

    for(int t=1; t<=m; t++)
    {
        for(int a=1; a<=n*n; a++)
        {
            bool finish = false;
            for(int i=0; i<n; i++)
            {
                if(finish) break;
                for(int j=0; j<n; j++)
                {
                    if(map[i][j] == a)
                    {
                        int maxx = 0;
                        int maxy = 0;
                        int maxnum = 0;
                        for(int d=0; d<8; d++)
                        {
                            int dirx = i + dirs[d][0];
                            int diry = j + dirs[d][1];
                            if(0 <= dirx && dirx < n && 0 <= diry && diry < n)
                            {
                                if(map[dirx][diry] > maxnum)
                                {
                                    maxnum = map[dirx][diry];
                                    maxx = dirx;
                                    maxy = diry;
                                }
                            }
                        }
                        map[maxx][maxy] = map[i][j];
                        map[i][j] = maxnum;
                        finish = true;
                        break;
                    }
                }
            }
        }
    }

    for(auto a : map)
    {
        for(auto i : a)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}