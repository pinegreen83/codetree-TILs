#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    int before = -10;
    for(int i=n-1; i>=0; i--)
    {
        int now = nums[i];
        if(now == -1)
        {
            if(before > 0) nums[i] = before-1;
        }
        before = now;
    }

    bool canbreakout = true;
    int block = 0, canblock = 0, cnt = 0, minus1 = 0;
    if(nums[0] > 0) canbreakout = false;
    else
    {
        for(int i=0; i<n; i++)
        {
            if(nums[i] == -1) 
            {
                minus1++;
                cnt++;
            }
            else 
            {
                if(nums[i] == 0) 
                {
                    block++;
                    if(cnt != 0)
                    {
                        canblock++;
                        cnt = 0;
                    }
                }
                else
                {
                    if(nums[i] != nums[i-1]+1)
                    {
                        canbreakout = false;
                        break;
                    }
                }
            }
        }
    }

    if(canbreakout) cout << block+canblock << " " << block+minus1;
    else cout << -1;

    return 0;
}