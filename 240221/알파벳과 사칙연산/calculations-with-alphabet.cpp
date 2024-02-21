#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

int answer;
string calc;
vector<int> comb;
unordered_map<char, int> umap;

void perm(int cnt)
{
    if(cnt == umap.size())
    {
        int start = comb[umap[calc[0]]];
        char oper = '0';
        for(int i=1; i<calc.size(); i++)
        {
            if('a' <= calc[i] && calc[i] <= 'f')
            {
                int temp = comb[umap[calc[i]]];
                switch(oper)
                {
                    case '+':
                        start = start + temp;
                        break;
                    case '-':
                        start = start - temp;
                        break;
                    case '*':
                        start = start * temp;
                        break;
                }
            }
            else
            {
                oper = calc[i];
            }
        }
        answer = max(answer, start);
        return;
    }
    for(int i=1; i<=4; i++)
    {
        comb.push_back(i);
        perm(cnt+1);
        comb.pop_back();
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> calc;
    answer = INT_MIN;

    vector<int> temp(6);
    for(int i=0; i<calc.size(); i++) if('a' <= calc[i] && calc[i] <= 'f') temp[calc[i] - 'a']++;

    int num = 0;
    for(int i=0; i<6; i++) if(temp[i]) umap['a'+i] = num++;

    unordered_map<char, int>::iterator iter;

    perm(0);
    cout << answer;

    return 0;
}