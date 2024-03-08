#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    unordered_set<int> uset;
    for(int i=0; i<n; i++)
    {
        string a;
        int b;
        cin >> a >> b;
        if(a == "find")
        {
            if(uset.find(b) == uset.end()) cout << "false" << endl;
            else cout << "true" << endl;
        }
        else if(a == "add")
        {
            uset.insert(b);
        }
        else if(a == "remove")
        {
            uset.erase(b);
        }
    }

    return 0;
}