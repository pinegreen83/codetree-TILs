#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, maxtime;
    cin >> n;
    vector<vector<int>> nums(n, vector<int>(2));
    for(int i=0; i<n; i++)
    {
        int a, b;
        cin >> a >> b;
        nums[i][0] = b;
        nums[i][1] = a;
        maxtime = max(maxtime, b);
    }

    int ans = 0, size = n-1;
    priority_queue<int> pq;
    sort(nums.begin(), nums.end());

    for(int i=maxtime; i>=1; i--)
    {
        while(size >= 0 && nums[size][0] == i)
        {
            pq.push(nums[size][1]);
            size--;
        }

        if(!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans;


    return 0;
}