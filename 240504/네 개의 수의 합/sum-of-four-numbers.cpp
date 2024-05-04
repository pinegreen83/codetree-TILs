#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, ans = 0;
    cin >> n;
    unordered_set<int> uset[4];

    for(int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        uset[0].insert(a);
        if(uset[3].find(a) != uset[3].end()) ans++;

        for(int j=0; j<3; j++)
        {
            unordered_set<int>::iterator iter;
            unordered_set<int> now = uset[j];
            for(iter=now.begin(); iter!=now.end(); iter++)
            {
                uset[j+1].insert(*iter + a);
            }
        }
    }
    cout << ans;

    return 0;
}