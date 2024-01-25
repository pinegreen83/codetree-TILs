#include <iostream>

int main() {
    // 여기에 코드를 작성해주세요.
    int n;

    std::cin >> n;

    if(n >= 3000)
    {
        std::cout << "book";
    }
    else if(n >= 1000)
    {
        std::cout << "mask";
    }
    else
    {
        std::cout << "no";
    }

    return 0;
}