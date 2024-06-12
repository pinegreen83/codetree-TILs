#include <iostream>
#include <vector>

using namespace std;

int n, k, ans = 0;
vector<vector<int>> same, diff;
vector<char> comb, type = {'A', 'B', 'C'};

void backtrack(int cnt)
{
    if(cnt == n+1)
    {
        ans++;
        return;
    }
    for(int i=0; i<3; i++)
    {
        comb[cnt] = type[i];
        bool fine = true;
        if(same[cnt].size() != 0)
        {
            for(int j=0; j<same[cnt].size(); j++)
            {
                if(comb[same[cnt][j]] != ' ')
                {
                    if(comb[cnt] != comb[same[cnt][j]]) fine = false;
                }
            }
        }
        if(diff[cnt].size() != 0)
        {
            for(int j=0; j<diff[cnt].size(); j++)
            {
                if(comb[cnt] == comb[diff[cnt][j]]) fine = false;
            }
        }
        if(fine) backtrack(cnt+1);
        comb[cnt+1] = ' ';
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> k;
    same = vector<vector<int>>(n+1);
    diff = vector<vector<int>>(n+1);
    comb = vector<char>(n+1, ' ');
    for(int i=0; i<k; i++)
    {
        char c;
        int a, b;
        cin >> c >> a >> b;
        if(c == 'S')
        {
            same[a].push_back(b);
            same[b].push_back(a);
        }
        else
        {
            diff[a].push_back(b);
            diff[b].push_back(a);
        }
    }

    // for(int i=1; i<=n; i++)
    // {
    //     cout << i << " : ";
    //     for(auto s : same[i]) cout << s << " ";
    //     cout << "\n";
    // }

    // for(int i=1; i<=n; i++)
    // {
    //     cout << i << " : ";
    //     for(auto s : diff[i]) cout << s << " ";
    //     cout << "\n";
    // }

    backtrack(1);
    cout << ans;

    return 0;
}