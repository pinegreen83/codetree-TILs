#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<int> stair(n+1);

    stair[2] = 1;
    stair[3] = 1;
    stair[4] = 2;

    for(int i=5; i<=n; i++)
    {
        stair[i] = min(stair[i-2], stair[i-3]) + 1;
    }
    cout << stair[n];

    return 0;
}