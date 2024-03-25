#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, k, start = 0, last = -1;
    cin >> n >> k;
    vector<tuple<int, int, int>> point;
    for(int i=0; i<n; i++)
    {
        int a;
        char b;
        cin >> a >> b;
        if(b == 'L')
        {
            last = start;
            start = last - a;
            point.push_back(make_tuple(start, 1, i));
            point.push_back(make_tuple(last, -1, i));
        }
        else
        {
            last = start + a;
            point.push_back(make_tuple(start, 1, i));
            point.push_back(make_tuple(last, -1, i));
            start = last;
        }
    }

    int ans = 0;
    sort(point.begin(), point.end());
    unordered_set<int> uset;
    for(auto p : point)
    {
        int a, b, c;
        tie(a, b, c) = p;

        if(b == 1)
        {
            uset.insert(c);
            if((int) uset.size() >= k) start = a;
        }
        else
        {
            if((int) uset.size() == k)
            {
                ans += a - start;
            }
            uset.erase(c);
        }
    }
    cout << ans;

    return 0;
}