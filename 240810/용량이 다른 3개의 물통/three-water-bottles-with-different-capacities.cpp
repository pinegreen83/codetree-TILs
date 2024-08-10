#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int waters[3][2];

    for(int i=0; i<3; i++) cin >> waters[i][0] >> waters[i][1];

    for(int i=0; i<100; i++) 
    {
        int now = i % 3;
        int next = (i+1) % 3;
        int total = waters[now][1] + waters[next][1];
        if(total > waters[next][0])
        {
            waters[now][1] = total - waters[next][0];
            waters[next][1] = waters[next][0];
        }
        else 
        {
            waters[now][1] = 0;
            waters[next][1] = total;
        }
    }
    cout << waters[0][1] << "\n" << waters[1][1] << "\n" << waters[2][1];

    return 0;
}