#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, t;
    cin >> n >> t;
    
    vector<string> words(n);
    map<string, vector<pair<string, int>>> mm;
    for(int i=0; i<n; i++) {
        cin >> words[i];

        string word = "";
        for(char c : words[i]) {
            word += c;
            mm[word].emplace_back(words[i], i);
        }
    }

    for(auto& m : mm) {
        sort(m.second.begin(), m.second.end());
    }

    while(t--) {
        int k;
        string str;
        cin >> k >> str;

        if(mm.find(str) == mm.end() || mm[str].size() < k) {
            cout << "-1\n";
        }
        else cout << mm[str][k-1].second + 1 << "\n";
    }

    return 0;
}