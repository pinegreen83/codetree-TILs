#include <iostream>
#include <string>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    string mid = "moo", sum = "moo";

    while(sum.size() < n)
    {
        mid += 'o';
        string temp = sum + mid + sum;
        sum = temp;
    }
    cout << sum[n-1];

    return 0;
}