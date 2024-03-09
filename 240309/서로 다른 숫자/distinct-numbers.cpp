#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    unordered_set<int> uset;
    for(int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        uset.insert(a);
    }

    cout << uset.size();

    return 0;
}