#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, num, sum = 0;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> num;
        sum += num;
    }

    float div = (float) sum / n;
    printf("%.1f\n", div);
    if(div < 70) printf("fail");

    return 0;
}