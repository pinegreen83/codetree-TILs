#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

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
        int a, b, d;
        tie(a, b, d) = point[i];

        if(b == 1)
        {
            if((int) uset.size() == 0)
            {
                ans++;
            }
            uset.insert(d);
        }
        else
        {
            uset.erase(d);
        }
    }
    cout << ans;

    return 0;
}