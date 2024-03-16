#include <iostream>
#include <set>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    set<pair<int, int>> s;
    for(int i=0; i<n; i++)
    {
        int p, l;
        cin >> p >> l;
        s.insert(make_pair(l, p));
    }

    int m;
    cin >> m;

    for(int i=0; i<m; i++)
    {
        string str;
        cin >> str;
        if(str == "rc")
        {
            int x;
            cin >> x;
            if(x == 1)
            {
                set<pair<int, int>>::iterator it=s.end();
                it--;
                cout << it->second << endl;
            }
            else if(x == -1)
            {
                cout << s.begin()->second << endl;
            }
        }
        else if(str == "ad")
        {
            int p, l;
            cin >> p >> l;
            s.insert(make_pair(l, p));
        }
        else if(str == "sv")
        {
            int p, l;
            cin >> p >> l;
            s.erase(make_pair(l, p));
        }
    }

    return 0;
}