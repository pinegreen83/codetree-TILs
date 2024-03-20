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
        while(j < n && sum+nums[j] < s)
        {
            sum += nums[j];
            j++;
        }

        answer = min(answer, j-i+1);

        sum -= nums[i];
    }
    cout << answer;

    return 0;
}