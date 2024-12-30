#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, t;
    cin >> n >> t;
    
    vector<pair<string, int>> words(n);
    for(int i=0; i<n; i++) {
        cin >> words[i].first;
        words[i].second = i+1;
    }

    sort(words.begin(), words.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.first < b.first;
    });

    while(t--) {
        int k;
        string str;
        cin >> k >> str;

        auto iter = lower_bound(words.begin(), words.end(), make_pair(str, 0), [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.first < b.first;
        });
        vector<int> temp;

        while(iter != words.end() && iter->first.substr(0, str.size()) == str) {
            temp.push_back(iter->second);
            ++iter;
        }

        if(temp.size() < k) cout << "-1\n";
        else cout << temp[k-1] << "\n";
    }

    return 0;
}