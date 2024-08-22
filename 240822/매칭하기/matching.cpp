#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, ans = 0;
    cin >> n;

    string str;
    for(int i=0; i<n; i++) {
        cin >> str;
        vector<char> stack;

        for(int j=0; j<str.size(); j++) {
            if(stack.empty() || stack.back() != str[j]) {
                stack.push_back(str[j]);
            }
            else if(stack.back() == str[j]) {
                stack.pop_back();
            }
        }

        if(stack.empty()) ans++;
    }
    cout << ans;

    return 0;
}