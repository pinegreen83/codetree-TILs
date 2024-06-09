#include <iostream>
#include <vector>

using namespace std;

int n, l;
vector<int> nums;

bool check(bool isfloat, float left, float right)
{
    while(left >= 0 && right <= l)
    {
        if(isfloat)
        {
            if(nums[left-0.5] != nums[right+0.5]) return false;
        }
        else 
        {
            if(nums[left] != nums[right]) return false;
        }
        left--;
        right++;
    }
    return true;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> l;
    nums = vector<int>(l+1);
    nums[0] = 1;
    nums[l] = 1;
    for(int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        nums[a] = 1;
    }

    int ans = 0;
    bool chan = true;
    for(float f=0.5; f<=l-0.5; f+=0.5)
    {
        if(check(chan, f, f))ans++;
        chan = !chan;
    }
    cout << ans;

    return 0;
}