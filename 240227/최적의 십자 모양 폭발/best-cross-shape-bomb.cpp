#include <iostream>
#include <vector>

using namespace std;

int n, answer;
vector<vector<int>> map;
vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

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
            for(int d=0; d<4; d++)
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
    vector<vector<int>> newmap = map;
    newmap[x][y] = 0;
    for(int i=0; i<4; i++)
    {
        int dirx = x;
        int diry = y;
        for(int j=1; j<map[x][y]; j++)
        {
            dirx += dirs[i][0];
            diry += dirs[i][1];
            if(isin(dirx, diry))
            {
                newmap[dirx][diry] = 0;
            }
            else break;
        }
    }
    nowmax = max(nowmax, NumDown(newmap));

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