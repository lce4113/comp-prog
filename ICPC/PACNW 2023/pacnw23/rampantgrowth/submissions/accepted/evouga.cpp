#include <iostream>

constexpr int64_t p = 998244353;

int main()
{
    int64_t r, c;
    std::cin >> r >> c;
    int64_t answer = r;
    for(int i=0; i<c-1; i++)
    {
        answer = (answer * (r-1)) % p;
    }
    std::cout << answer << std::endl;
}
