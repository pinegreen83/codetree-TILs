#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    vector<int> numbers(n);
    vector<int> dp;

    for(int i=0; i<n; i++)
    {
        cin >> numbers[i];
    }

    dp.push_back(numbers[0]);
    
    int answer = 1;

    for(int i=1; i<n; i++)
    {
        while(dp.back() >= numbers[i])
        {
            dp.pop_back();
        }
        dp.push_back(numbers[i]);
        int size = dp.size();
        answer = max(answer, size);
    }

    cout << answer;

    return 0;
}