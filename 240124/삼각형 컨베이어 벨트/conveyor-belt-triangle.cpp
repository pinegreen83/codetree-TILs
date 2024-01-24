#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    int t;
    cin >> n >> t;
    vector<int> belt(n*3);

    for(int i=0; i<n*3; i++)
    {
        cin >> belt[i];
    }

    int time = t % (n * 3);
    for(int i=0; i<time; i++)
    {
        int temp = belt[0];
        for(int j=1; j<belt.size(); j++)
        {
            int now = belt[j];
            belt[j] = temp;
            temp = now;
        }
        belt[0] = temp;
    }
    
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << belt[n*i + j] << " ";
        }
        cout << endl;
    }

    return 0;
}