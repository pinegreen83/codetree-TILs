#include <iostream>
#include <string>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string a, b;
    cin >> a >> b;

    if(a.size() > b.size())
    {
        cout << b << " " << b.size();
    }
    else if(a.size() < b.size())
    {
        cout << a << " " << a.size();
    }
    else cout << "equal";

    return 0;
}