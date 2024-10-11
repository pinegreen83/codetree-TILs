#include <iostream>
#include <map>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string now;    
    map<string, int> m;

    while(cin >> now) {
        m[now]++;
    }

    for(auto& c : m) {
        cout << c.first << " ";
    }

    return 0;
}