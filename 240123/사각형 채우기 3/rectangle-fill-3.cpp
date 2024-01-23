#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    int answer = 2;
    for(int i=2; i<=n; i++)
    {
        answer = (answer + (answer) * 2 + 1) % 1000000007;
    }

    cout << answer;

    return 0;
}