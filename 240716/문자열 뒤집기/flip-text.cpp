#include <iostream>
#include <string>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string str;
    cin >> str;

    int one = 0, zero = 0;
    char before;
    for(int i=0; i<str.size(); i++)
    {
        if(before != str[i])
        {
            if(str[i] == '1') 
            {
                one++;
            }
            else
            {
                zero++;
            }
        }
        before = str[i];
    }
    cout << (one < zero ? one : zero);

    return 0;
}