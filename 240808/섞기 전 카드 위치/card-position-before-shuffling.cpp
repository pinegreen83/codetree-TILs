#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    
    vector<int> idxs(n+1);
    for(int i=1; i<=n; i++)
    {
        cin >> idxs[i];
    }

    vector<int> move(n+1);
    for(int i=1; i<=n; i++) move[i] = i;

    for(int t=0; t<3; t++)
    {
        int now;
        vector<int> temp(n+1);
        for(int i=1; i<=n; i++)
        {
            temp[idxs[i]] = move[i];
        }
        move = temp;
    }

    int num;
    vector<vector<int>> nums(n, vector<int>(2));
    for(int i=1; i<=n; i++)
    {
        nums[i-1][0] = move[i];
        cin >> nums[i-1][1];
    }

    sort(nums.begin(), nums.end());
    for(int i=0; i<n; i++)
    {
        cout << nums[i][1] << "\n";
    }

    return 0;
}