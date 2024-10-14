#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    char check;
    cin >> n >> check;

    vector<string> ans;
    while(n--) {
        string now;
        cin >> now;
        if(now[3] == check) ans.push_back(now);
    }
    cout << ans.size() << "\n";
    for(auto& a : ans) cout << a << "\n";

    return 0;
}