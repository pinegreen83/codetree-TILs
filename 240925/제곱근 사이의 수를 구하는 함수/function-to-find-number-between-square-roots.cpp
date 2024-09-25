#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    double a, b;
    cin >> a >> b;

    double ra = sqrt(a);
    double rb = sqrt(b);
    cout << abs((int) ra - (int) rb);

    return 0;
}