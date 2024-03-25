#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<tuple<int, int, int>> point;
    for(int i=0; i<n; i++)
    {
        int a, b;
        cin >> a >> b;
        point.push_back(make_tuple(a, 1, i));
        point.push_back(make_tuple(b, -1, i));
    }
    sort(point.begin(), point.end());

    int ans = 0;
    unordered_set<int> uset;
    for(int i=0; i<n*2; i++)
    {
        int x, y, z;
        tie(x, y, z) = point[i];

        if(y == 1)
        {
            uset.insert(z);
            ans = max(ans, (int) uset.size());
        }
        else
        {
            uset.erase(z);
        }
    }
    cout << ans;

    return 0;
}