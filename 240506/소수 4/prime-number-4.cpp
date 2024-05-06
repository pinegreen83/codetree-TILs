#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, k, cnt = 0;
    cin >> n >> k;

    vector<int> nums(n+1);
    for(int i=2; i<=n; i++)
    {
        if(cnt == k) break;
        if(nums[i] == 0)
        {
            nums[i] = 1;
            cnt++;
            if(cnt == k)
            {
                cout << i;
                break;
            }
            for(int j=i+i; j<=n; j+=i)
            {
                if(nums[j] == 0)
                {
                    nums[j] = 1;
                    cnt++;
                    if(cnt == k)
                    {
                        cout << j;
                        break;
                    }
                }
            }
        }
    }

    return 0;
}