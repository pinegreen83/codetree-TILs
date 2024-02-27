#include <iostream>
#include <vector>

using namespace std;

int n, answer;
vector<vector<int>> map;
vector<vector<int>> dirs = {{0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-2, 0}, {2, 0}, {0, -2}, {0, 2}};

bool isin(int x, int y)
{
    return 0 <= x && x < n && 0 <= y && y < n;
}

int NumDown(vector<vector<int>>& bombMap)
{
    for(int j=0; j<n; j++)
    {
        vector<int> temp;
        for(int i=n-1; i>=0; i--)
        {
            if(bombMap[i][j]) temp.push_back(bombMap[i][j]);
        }
        if(temp.size() < n)
        {
            int size = temp.size();
            for(int i=size; i<n; i++)
            {
                temp.push_back(0);
            }
        }

        for(int i=n-1; i>=0; i--)
        {
            bombMap[i][j] = temp[n-i-1];
        }
    }

    int same = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(bombMap[i][j] == 0) continue;
            for(int d=1; d<=4; d++)
            {
                int dirx = i + dirs[d][0];
                int diry = j + dirs[d][1];
                if(isin(dirx, diry))
                {
                    if(bombMap[i][j] == bombMap[dirx][diry]) 
                    {
                        same++;
                    }
                }
            }
        }
    }
    
    return same/2;
}

int Bomb(int x, int y)
{
    int nowmax = 0;
    int dir = 1;
    for(int b=0; b<3; b++)
    {
        vector<vector<int>> newmap = map;
        for(int i=0; i<dir; i++)
        {
            int dirx = x + dirs[i][0];
            int diry = y + dirs[i][1];
            if(isin(dirx, diry))
            {
                newmap[dirx][diry] = 0;
            }
        }

        nowmax = max(nowmax, NumDown(newmap));
        dir += 4;
    }

    return nowmax;
}

void FindMax()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            answer = max(answer, Bomb(i, j));
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    answer = 0;
    cin >> n;
    map = vector<vector<int>>(n, vector<int>(n));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> map[i][j];
        }
    }

    FindMax();

    cout << answer;
    
    return 0;
}