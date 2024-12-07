#include <iostream>
#include "../../helper.cpp"
using namespace std;

void c_786()
{
    size_t n;
    std::cin >> n;

    unsigned long long **data = Utils::allocate_matrix<unsigned long long>(n, n);
    Utils::GetMatrixFromConsole(data, n, n);

    for (size_t r = 0; r < n; r++)
    {
        for (size_t c = 0; c < n; c++)
            std::cout << data[c][r] << ' ';
        std::cout << std::endl;
    }
    Utils::delete_matrix(data, n, n);
}

void _786()
{
    int n;
    unsigned long long data[100][100];

    // citeste datele de intrare de la tastatura
    cin >> n;
    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            cin >> data[r][c];

    // trec prin toate elementele matricei
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
            cout << data[c][r] << ' '; // afisez elementul de pe coloana r si linia c
        cout << endl;
    }
}

int main()
{
    c_786();
    return 0;
}