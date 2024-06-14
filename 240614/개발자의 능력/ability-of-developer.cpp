#include <iostream>
#include <algorithm>

using namespace std;

int ans = 12'000'000;
int nums[12], teams[4] = {0, 0, 0, 0}, team_count[4] = {0, 0, 0, 0};
bool visited[12];

void backtrack(int cnt)
{
    if(cnt == 12)
    {
        int maxteam = *max_element(teams, teams+4);
        int minteam = *min_element(teams, teams+4);
        ans = min(ans, maxteam-minteam);
        return;
    }

    for(int i=0; i<4; i++)
    {
        if(team_count[i] < 3) 
        {
            teams[i] += nums[cnt];
            team_count[i]++;
            
            backtrack(cnt + 1);
            
            teams[i] -= nums[cnt];
            team_count[i]--;
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    for(int i=0; i<12; i++) cin >> nums[i];
    backtrack(0);
    cout << ans;

    return 0;
}