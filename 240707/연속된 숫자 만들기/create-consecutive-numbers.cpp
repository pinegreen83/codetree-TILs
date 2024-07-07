#include <iostream>
#include <algorithm>

using namespace std;

int line[3];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> line[0] >> line[1] >> line[2];

    sort(line, line+3);

    int diffab = line[1] - line[0] - 1;
    int diffbc = line[2] - line[1] - 1;

    int maxdiff = max(diffab, diffbc);
    int mindiff = min(diffab, diffbc);
    if(0 == mindiff || mindiff > 2) mindiff = 2;
    cout << mindiff << '\n' << maxdiff;

    return 0;
}