#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    vector<long long> square(n+1);
    square[0] = 1;
    square[1] = 2;
    square[2] = 7;
    int modval = 1000000007;

    for(int i=3; i<=n; i++)
    {
        square[i] = ((square[i-1] * 3) % modval + (square[i-2] - square[i-3]) % modval) % modval;
    }
    cout << square[n];

    return 0;
}