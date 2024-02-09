#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, cnt;
vector<vector<int>> visit;
vector<vector<int>> map;
vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void DFS(int x, int y)
{
    cnt++;
    for(int i=0; i<4; i++)
    {
        int dirx = x + dirs[i][0];
        int diry = y + dirs[i][1];
        if(0 <= dirx && dirx < n && 0 <= diry && diry < n)
        {
            if(!visit[dirx][diry] && map[dirx][diry])
            {
                visit[dirx][diry] = 1;
                DFS(dirx, diry);
            }
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    visit = vector<vector<int>>(n, vector<int>(n));
    vector<int> villages;

    int num;
    for(int i=0; i<n; i++)
    {
        vector<int> temp;
        for(int j=0; j<n; j++)
        {
            cin >> num;
            temp.push_back(num);
        }
        map.push_back(temp);
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(map[i][j] && !visit[i][j])
            {
                cnt = 0;
                visit[i][j] = 1;
                DFS(i, j);
                villages.push_back(cnt);
            }
        }
    }

    sort(villages.begin(), villages.end());

    cout << villages.size();
    for(auto i : villages)
    {
        cout << endl << i;
    }

    return 0;
}