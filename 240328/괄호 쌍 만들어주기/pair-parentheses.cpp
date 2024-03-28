#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string str;
    cin >> str;

    vector<int> right(str.size());
    for(int i=str.size()-2; i>=0; i--)
    {
        if(str[i] == ')' && str[i] == str[i+1])
        {
            right[i] = right[i+1]+1;
        }
        else right[i] = right[i+1];
    }

    long long ans = 0;
    for(int i=1; i<str.size(); i++)
    {
        if(str[i]=='(' && str[i] == str[i-1])
        {
            ans += right[i];
        }
    }
    cout << ans;

    return 0;
}