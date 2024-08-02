#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, l;
    cin >> n >> l;
    vector<int> lines(n);
    for(int i=0; i<n; i++) cin >> lines[i];

    sort(lines.begin(), lines.end());

    float start = lines[0] - 0.5;
    float next = start + l;

    int ans = 1;
    for(int i=0; i<n; i++)
    {
        if(start <= lines[i] && lines[i] <= next) continue;
        else
        {
            start = lines[i] - 0.5;
            next = start + l;
            ans++;
        }
    }
    cout << ans;

    return 0;
}