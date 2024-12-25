#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string str;
    
    set<string> ss;
    vector<string> ans;
    while(getline(cin, str))
    {
        if(str == "end") break;

        string temp;
        for(auto c : str) {
            if(c == ' ') {
                if(ss.find(temp) == ss.end()) {
                    ss.insert(temp);
                    ans.push_back(temp);
                }
                temp = "";
            }
            else temp += c;
        }

        if(ss.find(temp) == ss.end()) {
            ss.insert(temp);
            ans.push_back(temp);
        }

        for(auto an : ans) cout << an << " ";
        cout << "\n";
    }

    return 0;
}