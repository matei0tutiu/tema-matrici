#include <iostream>
#include "../../helper.cpp"

using namespace std;

void c_313()
{
    size_t n;
    std::cin >> n;

    int **data = Utils::allocate_matrix<int>(n, n);
    Utils::GetMatrixFromConsole(data, n, n);

    long long result = 0;

    for (size_t i = 0; i < n; i++)
    {
        result += data[i][i] - data[i][n - i - 1];
    }

    std::cout << (result > 0 ? result : -result);

    Utils::delete_matrix<int>(data, n, n);
}

void _313()
{
    int n;
    std::cin >> n;

    // citeste numerele de la tastatura
    int matrice[20][20];
    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            cin >> matrice[r][c];

    int result = 0;

    // treci prin toate liniile
    for (int i = 0; i < n; i++)
        // pe linia i se afla exact un element al diagonalei principale si un element al celei secundare
        // adun la rezultat diferenta lor
        result += matrice[i][i] - matrice[i][n - 1 - i];

    // scriu rezultatul in functie de semnul sau
    if (result > 0)
        cout << result;
    else
        cout << -result;
}

int main()
{
    c_313();
    return 0;
}