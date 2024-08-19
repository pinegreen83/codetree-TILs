#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string str;
    cin >> str;

    int ans = 1;
    vector<char> stack;

    for(int i=0; i<str.size(); i++) {
        if(str[i] == '(' || str[i] == '[') {
            stack.push_back(str[i]);
        }
        else if(str[i] == ')') {
            if(stack.back() == '(') stack.pop_back();
            else {
                ans = 0;
                break;
            }
        }
        else if(str[i] == ']') {
            if(stack.back() == '[') stack.pop_back();
            else {
                ans = 0;
                break;
            }
        }
    }
    cout << ans;

    return 0;
}