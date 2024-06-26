#include <iostream>

using namespace std;

int map[3][3];

int main() {
    // 여기에 코드를 작성해주세요.
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++) cin >> map[i][j];
    }

    for(int i=0; i<3; i++)
    {
        float avg = 0;
        for(int j=0; j<3; j++) avg += map[i][j];
        printf("%.1f ", avg/3);
    }
    cout << "\n";

    float ans = 0;
    for(int i=0; i<3; i++)
    {
        float avg = 0;
        for(int j=0; j<3; j++) 
        {
            avg += map[j][i];
            ans += map[i][j];
        }
        printf("%.1f ", avg/3);
    }
    cout << "\n";
    printf("%.1f", ans/9);

    return 0;
}