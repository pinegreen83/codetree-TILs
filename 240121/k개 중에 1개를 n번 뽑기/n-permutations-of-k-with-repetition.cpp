#include <iostream>
#include <vector>

using namespace std;
int K, N;
vector<int> perm;

void permutation(int cnt)
{
    if(cnt == N)
    {
        for(int i : perm)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    for(int i=1; i<=K; i++)
    {
        perm.push_back(i);
        permutation(cnt+1);
        perm.pop_back();
    }
}

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> K >> N;
    permutation(0);

    return 0;
}