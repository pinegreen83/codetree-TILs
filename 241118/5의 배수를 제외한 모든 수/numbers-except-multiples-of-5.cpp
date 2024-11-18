#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int x, y;
    cin >> x >> y;

    if(x > y) {
        int temp = x;
        x = y;
        y = temp;
    }

    int cnt = 0;
    int sum = 0;
    for(int i=x; i<=y; i++) {
        if(i % 5 == 0) continue;
        cnt++;
        sum += i;
    }

    printf("%d %.1f", sum, (float) sum / cnt);

    return 0;
}