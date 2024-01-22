#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    vector<int> fibo(n);
    fibo[0] = 1;
    fibo[1] = 1;
    for(int i=2; i<n; i++)
    {
        fibo[i] = fibo[i-2] + fibo[i-1];
    }

    cout << fibo[n-1];

    return 0;
}