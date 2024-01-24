#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    int t;
    cin >> n >> t;
    vector<int> belt(n*2);

    for(int i=0; i<n*2; i++)
    {
        cin >> belt[i];
    }

    int time = t % (n * 2);

    for(int i=0; i<t; i++)
    {
        int temp = belt[0];
        for(int j=1; j<2*n; j++)
        {
            int now = belt[j];
            belt[j] = temp;
            temp = now;
        }
        belt[0] = temp;
    }

    for(int i=0; i<2; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << belt[n*i + j] << " ";
        }
        cout << endl;
    }

    return 0;
}