#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string str;
    cin >> str;

    string first[8] = {"0", "1", "10", "11", "100", "101", "110", "111"};
    string notFirst[8] = {"000", "001", "010", "011", "100", "101", "110", "111"};
    for(int i=0; i<str.size(); i++) {
        if(i == 0) cout << first[str[i]-'0'];
        else cout << notFirst[str[i]-'0'];
    }

    return 0;
}