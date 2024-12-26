#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    int alps[26] = {};
    for(int i=0; i<n; i++) {
        char now;
        cin >> now;
        if('a' <= now && now <= 'z') {
            alps[now - 'a']++;
        }
        else break;
    }
    
    for(int i=0; i<26; i++) {
        if(alps[i] > 0) {
            char now = 'a' + i;
            cout << now << " : " << alps[i] << "\n";
        }
    }

    return 0;
}