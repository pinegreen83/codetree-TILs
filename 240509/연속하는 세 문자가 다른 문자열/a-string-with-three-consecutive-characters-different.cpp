#include <iostream>
#include <vector>

using namespace std;

int n, len = 0, ans = 0;
vector<int> nums, check, str;

void Comb(int cnt)
{
    // cout << cnt << "\n";
    if(cnt == len)
    {
        ans++;
        return;
    }
    for(int i=0; i<n; i++)
    {
        if(check[i] == nums[i]) continue;
        else
        {
            if(cnt != 0)
            {
                if(cnt == 1)
                {
                    if(str[0] == i) continue;
                    else 
                    {
                        str.push_back(i);
                        check[i]++;
                        Comb(cnt+1);
                        str.pop_back();
                        check[i]--;
                    }
                }
                else
                {
                    if(str[cnt-2] != i && str[cnt-1] != i)
                    {
                        str.push_back(i);
                        check[i]++;
                        Comb(cnt+1);
                        str.pop_back();
                        check[i]--;
                    }
                }
            }
            else 
            {
                str.push_back(i);
                check[i]++;
                Comb(cnt+1);
                str.pop_back();
                check[i]--;
            }
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    nums = vector<int>(n);
    check = vector<int>(n);
    for(int i=0; i<n; i++) 
    {
        cin >> nums[i];
        len += nums[i];
    }

    Comb(0);
    cout << ans;

    return 0;
}