#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    int answer = 1;
    for(int i=2; i<=n; i++)
    {
       answer = (answer * i) % 1000000007;
    }

    answer = ((answer+1) * n) % 1000000007;
    answer += 1;
    if(n == 1) cout << 2;
    else cout << answer;

    return 0;
}