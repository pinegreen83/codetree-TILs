#include <iostream>

int main() {
    // 여기에 코드를 작성해주세요.
    int a, b;

    std:: cin >> a >> b;

    if(a > b)
    {
        std::cout << a*b;
    }
    else
    {
        std::cout << b/a;
    }

    return 0;
}