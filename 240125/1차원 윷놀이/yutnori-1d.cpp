#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, m, k;
int answer = 0;
vector<int> moves(100);
vector<int> turn;

void perm(int idx)
{
    if(idx == n)
    {
        vector<int> pawn(k, 1);
        int temp = 0;

        for(int i=0; i<idx; i++)
        {
            pawn[turn[i]] += moves[i];
        }

        for(auto i : pawn)
        {
            if(i >= m) temp++;
        }

        answer = max(answer, temp);

        return;
    }
    for(int i=0; i<k; i++)
    {
        turn.push_back(i);
        perm(idx+1);
        turn.pop_back();
    }
}

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n >> m >> k;

    for(int i=0; i<n; i++)
    {
        cin >> moves[i];
    }

    perm(0);

    cout << answer;

    return 0;
}