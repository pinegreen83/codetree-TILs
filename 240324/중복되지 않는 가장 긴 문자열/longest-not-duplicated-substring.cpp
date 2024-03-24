#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string str;
    cin >> str;

    unordered_set<string> uset;
    vector<int> nums(26);
    int j=0, ans = 0;
    for(int i=0; i<str.size(); i++)
    {
        while(j < str.size() && nums[str[j]-'a'] == 0)
        {
            nums[str[j]-'a']++;
            j++;
        }

        ans = max(ans, j-i);
        nums[str[i]-'a']--;
    }
    cout << ans;

    return 0;
}