#include <iostream>
#include <vector>

using namespace std;

int n, k, ans = 0;
vector<int> same, diff;
vector<char> comb, type = {'A', 'B', 'C'};

void backtrack(int cnt)
{
    if(cnt == n+1)
    {
        ans++;
        return;
    }
    if(same[cnt] != 0 || diff[cnt] != 0)
    {
        if(same[cnt] != 0) 
        {
            comb[cnt] = comb[same[cnt]];
            backtrack(cnt+1);
        }
        else if(diff[cnt] != 0)
        {
            for(int i=0; i<3; i++)
            {
                if(comb[diff[cnt]] == type[i]) continue;
                comb[cnt] = type[i];
                backtrack(cnt+1);
            }
        }
    }
    else
    {
        for(int i=0; i<3; i++)
        {
            comb[cnt] = type[i];
            backtrack(cnt+1);
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> k;
    same = vector<int>(n+1);
    diff = vector<int>(n+1);
    comb = vector<char>(n+1);
    for(int i=0; i<k; i++)
    {
        char c;
        int a, b;
        cin >> c >> a >> b;
        if(c == 'S') a > b ? same[a] = b : same[b] = a;
        else a > b ? diff[a] = b : diff[b] = a;
    }

    backtrack(1);
    cout << ans;

    return 0;
}