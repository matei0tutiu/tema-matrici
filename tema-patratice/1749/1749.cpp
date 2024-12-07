#include <iostream>
#include "../../helper.cpp"
using namespace std;

void c_1749()
{
    size_t n, z;
    std::cin >> n >> z;

    long long **data = Utils::allocate_matrix<long long>(n, n);
    Utils::GetMatrixFromConsole(data, n, n);

    long long sum = 0;

    switch (z)
    {
    case 1:
        // Zona 1
        for (size_t r = 0; r < n / 2; r++)
            for (size_t c = r + 1; c < n - 1 - r; c++)
                sum += data[r][c];
        break;
    case 2:
        // Zona 2
        for (size_t c = n - 1; c > n / 2; c--)
            for (size_t r = n - c; r < c; r++)
                sum += data[r][c];
        break;
    case 3:
        // Zona 3
        for (size_t r = n - 1; r > n / 2; r--)
            for (size_t c = n - r; c < r; c++)
                sum += data[r][c];
        break;
    case 4:
        // Zona 4
        for (size_t c = 0; c < n / 2; c++)
            for (size_t r = c + 1; r < n - 1 - c; r++)
                sum += data[r][c];
        break;
    }
    std::cout << sum;

    Utils::delete_matrix(data, n, n);
}

void _1749()
{
    int n, z;
    long long data[200][200], sum = 0;

    // citim datele de intrare
    cin >> n >> z;
    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            cin >> data[r][c];
    // in functie de zona, se aduna diferite elemente ale matricei
    if (z == 1)
        for (int r = 0; r < n / 2; r++)
            for (int c = r + 1; c < n - 1 - r; c++)
                sum += data[r][c];
    else if (z == 2)
        for (int c = n - 1; c > n / 2; c--)
            for (int r = n - c; r < c; r++)
                sum += data[r][c];
    else if (z == 3)
        for (int r = n - 1; r > n / 2; r--)
            for (int c = n - r; c < r; c++)
                sum += data[r][c];
    else if (z == 4)
        for (int c = 0; c < n / 2; c++)
            for (int r = c + 1; r < n - 1 - c; r++)
                sum += data[r][c];

    cout << sum;
}

int main()
{
    c_1749();
    return 0;
}