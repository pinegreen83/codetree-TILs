#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, a, b;
    cin >> n >> a >> b;

    vector<pair<int, int>> points;
    points.push_back(make_pair(1, 0));
    points.push_back(make_pair(1'000'000'000, 0));
    for(int i=0; i<n; i++)
    {
        string info;
        int num;
        cin >> info >> num;
        if(info == "S") points.push_back(make_pair(num, 1));
        else points.push_back(make_pair(num, 0));
    }
    sort(points.begin(), points.end());

    int ans = 0;
    for(int i=0; i<n+1; i++)
    {
        pair<int, int> now = points[i];
        pair<int, int> next = points[i+1];
        
        int start = now.first;
        int end = next.first;
        int mid = (start + end) / 2;

        if(now.second == 1)
        {
            int s = max(a, start+1);
            int e = min(b, mid);
            if(e >= s) ans += e - s + 1;
        }
        if(next.second == 1)
        {
            int s = max(a, mid+1);
            int e = min(b, end);
            if(e >= s) ans += e - s + 1;
            if(now.second == 0 && a <= mid && mid <= b && (start%2 == end%2)) ans++;
        }
    }
    cout << ans;

    return 0;
}