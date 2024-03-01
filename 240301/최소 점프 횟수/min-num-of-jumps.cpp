#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n, answer;
vector<int> nums;

void comb(int idx, int cnt)
{
    if(idx >= n-1)
    {
        answer = min(answer, cnt);
        return;
    }
    for(int i=1; i<=nums[idx]; i++)
    {
        comb(idx+i, cnt+1);
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    answer = INT_MAX;
    nums = vector<int>(n);
    for(int i=0; i<n; i++)
        cin >> nums[i];

    comb(0, 0);

    cout << (answer != INT_MAX ? answer : -1);

    return 0;
}