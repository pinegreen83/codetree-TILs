#include <iostream>
#include <vector>

using namespace std;
int n, answer;
vector<int> comb;
vector<bool> visit;
vector<vector<int>> map;

void perm(int cnt)
{
    if(cnt == n)
    {
        int now = 0;
        for(int i=0; i<n; i++)
        {
            now += map[i][comb[i]];
        }
        answer = max(answer, now);
        return;
    }
    for(int i=0; i<n; i++)
    {
        if(!visit[i])
        {
            comb.push_back(i);
            visit[i] = true;
            perm(cnt+1);
            comb.pop_back();
            visit[i] = false;
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    visit = vector<bool>(n);
    map = vector<vector<int>>(n, vector<int>(n));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> map[i][j];
        }
    }
    
    perm(0);
    cout << answer;

    return 0;
}