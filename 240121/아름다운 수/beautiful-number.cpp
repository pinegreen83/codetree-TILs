#include <iostream>
#include <vector>

using namespace std;

int n;
int answer;
vector<int> perm;

bool check()
{
    int now = perm[0];
    int cnt = 1;
    for(int i=1; i<n; i++)
    {
        if(perm[i] != now)
        {
            if(now > cnt) return false;
            else
            {
                now = perm[i];
                cnt = 1;
            }
        }
        else
        {
            if(now > cnt)
            {
                cnt++;
            }
            else if(now == cnt)
            {
                cnt = 1;
            }
            else
            {
                return false;
            }
        }
    }
    if(now != cnt) return false;
    return true;
}

void permutation(int cnt)
{
    if(cnt == n)
    {
        if(check()) 
        {
            answer++;
        }
        return;
    }
    for(int i=1; i<=4; i++)
    {
        perm.push_back(i);
        permutation(cnt+1);
        perm.pop_back();
    }
    return;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    answer = 0;
    permutation(0);

    cout << answer;

    return 0;
}