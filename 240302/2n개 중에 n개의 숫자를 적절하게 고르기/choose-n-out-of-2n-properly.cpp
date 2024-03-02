#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n, sum;
int answer = INT_MAX;
vector<int> nums;

void numdiv(int cnt, int start, int s)
{
    if(cnt == n)
    {
        answer = min(answer, abs((sum-s)-s));
        return;
    }
    for(int i=start+1; i<n*2; i++)
    {
        numdiv(cnt+1, i, s+nums[i]);
        numdiv(cnt, i, s);
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    nums = vector<int>(n*2 + 1);
    sum = 0;
    for(int i=1; i<=n*2; i++)
    {
        cin >> nums[i];
        sum += nums[i];
    }

    numdiv(0, 0, 0);
    cout << answer;

    return 0;
}