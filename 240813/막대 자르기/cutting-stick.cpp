#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string str;
    cin >> str;

    vector<int> stack;
    vector<bool> cut(str.size(), false);
    vector<pair<int, int>> sticks;
    for(int i=0; i<str.size(); i++) 
    {
        if(str[i] == '(') stack.push_back(i);
        else 
        {
            if(stack.back() != i-1) sticks.push_back({stack.back(), i});
            else cut[i] = true;
            stack.pop_back();
        }
    }

    int ans = 0;
    for(int i=0; i<sticks.size(); i++)
    {
        int a = sticks[i].first;
        int b = sticks[i].second;
        int cnt = 0;
        for(int j=a; j<=b; j++)
        {
            if(cut[j]) cnt++;
        }
        ans += cnt+1;
    }
    cout << ans;

    return 0;
}