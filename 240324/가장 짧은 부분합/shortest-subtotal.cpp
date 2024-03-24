#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, s;
    cin >> n >> s;
    vector<int> nums(n);
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }

    int j = 0;
    int sum = 0;
    int answer = n+1;
    for(int i=0; i<n; i++)
    {
        while(j < n && sum < s)
        {
            sum += nums[j];
            j++;
        }
        if(sum < s) break;

        answer = min(answer, j-i);

        sum -= nums[i];
    }
    cout << (answer == n+1 ? -1 : answer);

    return 0;
}