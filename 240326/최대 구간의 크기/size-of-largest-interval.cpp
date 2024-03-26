#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<pair<int, int>> points;
    for(int i=0; i<n; i++)
    {
        int a, b;
        cin >> a >> b;
        points.push_back(make_pair(a, 1));
        points.push_back(make_pair(b, -1));
    }

    sort(points.begin(), points.end());

    int start = 0, end = 0, ans = 0, cnt = 0;
    for(int i=0; i<n*2; i++)
    {
        int a, b;
        tie(a, b) = points[i];
        if(b == 1)
        {
            if(cnt == 0) start = a;
        }
        else
        {
            if(cnt == 1) 
            {
                end = a;
                ans = max(ans, end-start);
            }
        }
        cnt += b;
    }
    cout << ans;

    return 0;
}