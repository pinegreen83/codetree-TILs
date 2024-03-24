#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string str;
    int k;
    cin >> str >> k;

    int size = str.size();
    int j = 0, ans = 0;
    vector<int> chars(26);
    unordered_set<char> uset;
    for(int i=0; i<size; i++)
    {
        while(j < size)
        {
            if(uset.size() == k)
            {
                if(uset.find(str[j]) == uset.end()) break;
            }
            uset.insert(str[j]);
            chars[str[j]-'a']++;
            j++;
        }

        ans = max(ans, j-i);

        chars[str[i]-'a']--;
        if(chars[str[i]-'a'] == 0) uset.erase(str[i]);
    }
    cout << ans;

    return 0;
}