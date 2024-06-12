#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, k, ans = 0;
vector<set<int>> same, diff;
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
            for(auto s : same[cnt])
            {
                if(comb[s] != ' ')
                {
                    if(comb[cnt] != comb[s]) fine = false;
                }
            }
        }
        if(diff[cnt].size() != 0)
        {
            for(auto d : diff[cnt])
            {
                if(comb[cnt] == comb[d]) fine = false;
            }
        }
        if(fine) backtrack(cnt+1);
        comb[cnt+1] = ' ';
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> k;
    same = vector<set<int>>(n+1);
    diff = vector<set<int>>(n+1);
    comb = vector<char>(n+1, ' ');
    for(int i=0; i<k; i++)
    {
        char c;
        int a, b;
        cin >> c >> a >> b;
        if(c == 'S')
        {
            same[a].insert(b);
            same[b].insert(a);
        }
        else
        {
            diff[a].insert(b);
            diff[b].insert(a);
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