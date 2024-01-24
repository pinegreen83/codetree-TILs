#include <iostream>
#include <vector>

using namespace std;
int K;
int N;
vector<int> combs(8);

void comb(int idx)
{
    if(idx == N)
    {
        for(int i=0; i<idx; i++)
        {
            cout << combs[i] << " ";
        }
        cout << endl;
        return;
    }
    for(int i=1; i<=K; i++)
    {
        combs[idx] = i;
        bool isThree = false;
        int now = combs[0];
        int cnt = 1;
        for(int j=1; j<=idx; j++)
        {
            if(now == combs[j]) cnt++;
            else 
            {
                now = combs[j];
                cnt = 1;
            }
            if(cnt == 3) isThree = true;
        }

        if(isThree)
        {
            continue;
        }
        else
        {
            comb(idx+1);
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> K >> N;

    comb(0);

    return 0;
}