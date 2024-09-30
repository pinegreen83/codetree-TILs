#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    string str;
    vector<string> strs, ans;
    for(int i=0; i<n; i++) {
        cin >> str;
        strs.push_back(str);
    }

    char check;
    cin >> check;

    for(int i=0; i<n; i++) {
        if(strs[i][strs[i].size()-1] == check) ans.push_back(strs[i]);
    }

    cout << ans.size() << "\n";
    for(auto& a : ans) cout << a << "\n";

    return 0;
}