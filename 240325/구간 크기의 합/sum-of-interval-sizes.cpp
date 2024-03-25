#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<pair<int, int>> point;
    for(int i=0; i<n; i++)
    {
        int a, b;
        cin >> a >> b;
        point.push_back(make_pair(a, 1));
        point.push_back(make_pair(b, -1));
    }

    sort(point.begin(), point.end());
    int start = 0, end = 0, ans = 0, lines = 0;
    for(int i=0; i<n*2; i++)
    {
        int a, b;
        tie(a, b) = point[i];
        if(lines == 0) if(b == 1) start = a;
        lines += b;
        if(lines == 0)
        {
            if(b == -1)
            {
                end = a;
                ans += end - start;
            }
        }
    }
    cout << ans;

    return 0;
}