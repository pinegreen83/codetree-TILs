#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m, a, i, x;
    cin >> n >> m;

    vector<int> arrs(n+1, 0);
    while(m--)
    {
        cin >> a >> i;
        switch(a)
        {
            case 1:
                cin >> x;
                arrs[i] |= (1 << (x-1));
                break;
            case 2:
                cin >> x;
                arrs[i] &= ~(1 << (x - 1));
                break;
            case 3:
                arrs[i] <<= 1;
                arrs[i] &= ((1 << 20) - 1);
                break;
            case 4:
                arrs[i] >>= 1;
                break;
        }
    }

    unordered_set<int> uset;
    for(int i=1; i<=n; i++) {
        uset.insert(arrs[i]);
    }
    cout << uset.size();

    return 0;
}