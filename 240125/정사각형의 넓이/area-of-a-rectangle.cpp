#include <iostream>

int main() {
    // 여기에 코드를 작성해주세요.

    int n;
    std::cin >> n;

    std::cout << n*n;

    if(n < 5)
    {
        std::cout << std::endl << "tiny";
    }

    return 0;
}