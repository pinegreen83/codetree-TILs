#include <iostream>
#include <set>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    set<int> s;

    string a;
    int b;
    for(int i=0; i<n; i++)
    {
        cin >> a;
        if(a == "add")
        {
            cin >> b;
            s.insert(b);
        }
        else if(a == "remove")
        {
            cin >> b;
            s.erase(b);
        }
        else if(a == "find")
        {
            cin >> b;
            if(s.find(b) == s.end()) cout << "false"<< endl;
            else cout << "true" << endl;
        }
        else if(a == "lower_bound")
        {
            cin >> b;
            if(s.lower_bound(b) != s.end()) cout << *s.lower_bound(b) << endl;
            else cout << "None" << endl;
        }
        else if(a == "upper_bound")
        {
            cin >> b;
            if(s.upper_bound(b) != s.end()) cout << *s.upper_bound(b) << endl;
            else cout << "None" << endl;
        }
        else if(a == "largest")
        {
            if(s.empty()) cout << "None" << endl;
            else cout << *s.rbegin() << endl;
        }
        else if(a == "smallest")
        {
            if(s.empty()) cout << "None" << endl;
            else cout << *s.begin() << endl;
        }
    }

    return 0;
}