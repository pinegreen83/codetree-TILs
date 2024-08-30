#include <iostream>
#include <deque>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string str;
    cin >> str;

    deque<char> left, right;
    for(auto ch : str) {
        if(ch == '-') {
            if(!left.empty()) left.pop_back();
        }
        else if(ch == '<') {
            if(!left.empty()) {
                right.push_front(left.back());
                left.pop_back();
            }
        }
        else if(ch == '>') {
            if(!right.empty()) {
                left.push_back(right.front());
                right.pop_front();
            }
        }
        else {
            left.push_back(ch);
        }
    }

    for(auto c : left) cout << c;
    for(auto c : right) cout << c;

    return 0;
}