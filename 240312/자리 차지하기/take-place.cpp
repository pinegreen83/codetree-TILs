#include <iostream>
#include <set>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m, a;
    cin >> n >> m;

    set<int> s;
    set<int>::iterator it;
    for(int i=0; i<n; i++)
    {
        cin >> a;
        it = s.lower_bound(a);
        if(a != *it)
        {
            s.insert(a);
        }
        else
        {
            if(*it == 1) break;
            while(*it > 0)
            {
                if(*it < a-1)
                {
                    s.insert(a-1);
                    break;
                }
                else a = *it;
                it--;
            }
        }
    }
    cout << s.size();

    return 0;
}