#include <iostream>
#include "../../helper.cpp"
using namespace std;

void c_787()
{
    size_t n;
    std::cin >> n;

    unsigned long long **data = Utils::allocate_matrix<unsigned long long>(n, n);
    for (size_t r = 0; r < n; r++)
        for (size_t c = 0; c < n; c++)
            std::cin >> data[r][n - 1 - c];

    for (size_t r = 0; r < n; r++)
    {
        for (size_t c = 0; c < n; c++)
            std::cout << data[n - 1 - c][r] << ' ';
        std::cout << std::endl;
    }
    Utils::delete_matrix(data, n, n);
}

void _787()
{
    int n;
    cin >> n;
    unsigned long long data[100][100];
    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            cin >> data[r][n - 1 - c];
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
            cout << data[n - 1 - c][r] << ' ';
        cout << endl;
    }
}

int main()
{
    c_787();
    return 0;
}