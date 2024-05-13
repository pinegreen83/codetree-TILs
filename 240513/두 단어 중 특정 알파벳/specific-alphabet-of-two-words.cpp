#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    vector<int> counts(26);
    for(int i=0; i<n; i++)
    {
        string a, b;
        cin >> a >> b;

        vector<int> alpa(26);
        for(int j=0; j<a.size(); j++)
        {
            alpa[a[j] - 'a']++;
        }
        vector<int> alpb(26);
        for(int j=0; j<b.size(); j++)
        {
            alpb[b[j] - 'a']++;
        }

        for(int j=0; j<26; j++)
        {
            if(alpa[j] > alpb[j]) counts[j] += alpa[j];
            else counts[j] += alpb[j];
        }
    }
    for(int i=0; i<26; i++) cout << counts[i] << '\n';

    return 0;
}