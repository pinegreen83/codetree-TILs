#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, cnt;
int answer = 0;
vector<int> comb;
vector<vector<int>> map;
queue<pair<int, int>> q;
vector<vector<vector<int>>> blow = {
    {{-2, 0}, {-1, 0}, {1, 0}, {2, 0}},
    {{-1, 0}, {1, 0}, {0, -1}, {0, 1}},
    {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}}
};

bool IsRange(int x, int y)
{
    return 0 <= x && x < n && 0 <= y && y < n;
}

void perm(int num)
{
    if(cnt == num)
    {
        int bomb = cnt;
        vector<vector<int>> temp = map;
        for(auto i : comb)
        {
            pair<int, int> now = q.front();
            q.pop();
            for(int j=0; j<4; j++)
            {
                int dirx = now.first + blow[i][j][0];
                int diry = now.second + blow[i][j][1];
                if(IsRange(dirx, diry)) 
                {
                    if(!temp[dirx][diry])
                    {
                        temp[dirx][diry] = 1;
                        bomb++;
                    }
                }
            }
            q.push(now);
        }

        answer = max(answer, bomb);
        return;
    }
    for(int i=0; i<3; i++)
    {
        comb.push_back(i);
        perm(num+1);
        comb.pop_back();
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    map = vector<vector<int>>(n, vector<int>(n));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> map[i][j];
            if(map[i][j]) q.push(make_pair(i, j));
        }
    }
    cnt = q.size();

    perm(0);

    cout << answer;

    return 0;
}