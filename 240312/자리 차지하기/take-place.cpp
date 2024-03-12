#include <iostream>
#include <set>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m, a;
    cin >> n >> m;
    set<int> s;
    set<int>::iterator it;

    bool bCanSeat = true;
    for(int i=0; i<n; i++)
    {
        if(!bCanSeat) break;
        cin >> a;
        it = s.lower_bound(a);
        if(a != *it) s.insert(a);
        else
        {
            while(it != s.begin())
            {
                it--;
                if(*it < a-1)
                {
                    a--;
                    break;
                }
                else a = *it;
            }
            if(a == 0) bCanSeat = false;
            else s.insert(a);
        }
    }
    cout << s.size();

    return 0;
}