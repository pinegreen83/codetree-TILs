#include <iostream>
#include <set>

using namespace std;

int n;
string str;
set<string> ss;

void Backtrack(int cnt, string now) {
    if(cnt == n) {
        ss.insert(now);
        return;
    }

    if(str[cnt] == '1') {
        if(cnt < n) {
            char temp = 'A' + ((str[cnt] - '0') * 10 + (str[cnt+1] - '1'));
            Backtrack(cnt + 2, now + temp);
        }
    }
    else if(str[cnt] == '2') {
        if(cnt < n) {
            char temp = 'A' + ((str[cnt] - '0') * 10 + (str[cnt+1] - '1'));
            Backtrack(cnt + 2, now + temp);
        }
    }
    char temp = 'A' + str[cnt] - '1';
    Backtrack(cnt + 1, now + temp);
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> str;

    n = str.size();
    Backtrack(0, "");
    cout << ss.size() % 10007;

    return 0;
}