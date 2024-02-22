#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int answer;
vector<int> coin;
vector<int> perms;
vector<bool> visit(10);
vector<int> mstart(2);
vector<int> mend(2);
vector<vector<int>> coins(10);

void perm(int cnt)
{
    if(cnt == 3)
    {
        int move = 0;
        int startx = mstart[0];
        int starty = mstart[1];
        for(int i=0; i<3; i++)
        {
            int now = perms[i];
            move += abs(startx - coins[now][0]) + abs(starty - coins[now][1]);
            startx = coins[now][0];
            starty = coins[now][1];
        }
        move += abs(startx - mend[0]) + abs(starty - mend[1]);
        answer = min(answer, move);
        return;
    }
    for(int i=0; i<coin.size(); i++)
    {
        if(!visit[coin[i]])
        {
            perms.push_back(coin[i]);
            visit[coin[i]] = true;
            perm(cnt+1);
            perms.pop_back();
            visit[coin[i]] = false;
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    answer = 1000000000;
    cin >> n;
    
    char now;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> now;
            if('1' <= now && now <= '9')
            {
                coins[now-'0'].push_back(i);
                coins[now-'0'].push_back(j);
                coin.push_back(now-'0');
            }
            if(now == 'S')
            {
                mstart[0] = i;
                mstart[1] = j;
            }
            if(now == 'E')
            {
                mend[0] = i;
                mend[1] = j;
            }
        }
    }

    if(coins.size() < 3) cout << -1;
    else
    {
        perm(0);
        cout << answer;
    }

    return 0;
}