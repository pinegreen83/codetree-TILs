#include <iostream>
#include <string>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string a, b;
    cin >> a >> b;

    string anum = "";
    for(int i=0; i<a.size(); i++) {
        if('0' <= a[i] && a[i] <= '9') anum += a[i];
    }

    string bnum = "";
    for(int i=0; i<b.size(); i++) {
        if('0' <= b[i] && b[i] <= '9') bnum += b[i];
    }

    int ansa = stoi(anum);
    int ansb = stoi(bnum);
    cout << ansa + ansb;

    return 0;
}