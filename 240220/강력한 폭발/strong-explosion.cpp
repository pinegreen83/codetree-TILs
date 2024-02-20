#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int answer = 0;
vector<int> comb;
vector<vector<int>> map;
vector<vector<int>> bombs;
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
    if(bombs.size() == num)
    {
        int bomb = num;
        vector<vector<int>> temp = map;
        for(int i=0; i<num; i++)
        {
            for(int j=0; j<4; j++)
            {
                int dirx = bombs[i][0] + blow[comb[i]][j][0];
                int diry = bombs[i][1] + blow[comb[i]][j][1];
                if(IsRange(dirx, diry)) 
                {
                    if(!temp[dirx][diry])
                    {
                        temp[dirx][diry] = 1;
                        bomb++;
                    }
                }
            }
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
            if(map[i][j]) bombs.push_back({i, j});
        }
    }

    perm(0);

    cout << answer;

    return 0;
}