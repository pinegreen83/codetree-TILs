#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<int> xs(n), ys(n);
    for(int i=0; i<n; i++) cin >> xs[i] >> ys[i];

    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());

    int midx = xs[n/2], midy = ys[n/2];

    long long sumx = 0, sumy = 0;
    for(int i=0; i<n; i++)
    {
        sumx += abs(xs[i] - midx);
        sumy += abs(ys[i] - midy);
    }
    cout << sumx + sumy;

    return 0;
}