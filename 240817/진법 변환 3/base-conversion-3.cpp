#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string str;
    cin >> str;

    int num = 0, now = 1;
    for(int i=str.size()-1; i>=0; i--) {
        num += (str[i] - '0') * now;
        now *= 8;
    }

    string temp = "";
    while(num > 0) {
        temp += (num % 2) + '0';
        num /= 2;
    }

    for(int i=temp.size()-1; i>=0; i--) cout << temp[i];

    return 0;
}