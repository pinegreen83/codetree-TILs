#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<int> stair(n+1, 0);

    stair[2] = 1;
    stair[3] = 1;

    for(int i=4; i<=n; i++)
    {
        stair[i] = stair[i-2] + stair[i-3];
    }
    cout << stair[n];

    return 0;
}