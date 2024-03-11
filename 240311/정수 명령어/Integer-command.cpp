#include <iostream>
#include <set>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int T, k;
    cin >> T;

    for(int t=0; t<T; t++)
    {
        set<int> s;
        cin >> k;
        for(int j=0; j<k; j++)
        {
            char a;
            int b;
            cin >> a >> b;
            if(a == 'I') s.insert(b);
            else
            {
                if(s.empty()) continue;
                if(b == 1)
                {
                    int big = *s.rbegin();
                    s.erase(big);
                }
                else
                {
                    int small = *s.begin();
                    s.erase(small);
                }
            }
        }
        if(s.empty()) cout << "EMPTY" << endl;
        else cout << *s.rbegin() << " " << *s.begin() << endl;
    }

    return 0;
}