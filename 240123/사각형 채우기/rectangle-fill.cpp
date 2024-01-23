#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    vector<int> square(n+1);
    square[1] = 1;
    square[2] = 2;
    for(int i=3; i<= n; i++)
    {
        square[i] = (square[i-1] + square[i-2]) % 10007;
    }
    cout << square[n];

    return 0;
}