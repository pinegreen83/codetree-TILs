#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string str;
    cin >> str;

    bool ee = false, ea = false;
    for(int i=0; i<str.size()-1; i++) {
        if(str[i] == 'e') {
            if(str[i+1] == 'e') ee = true;
            if(str[i+1] == 'a') ea = true;
        }
    }
    cout << (ee ? "YES" : "NO") << " " << (ea ? "YES" : "NO");

    return 0;
}