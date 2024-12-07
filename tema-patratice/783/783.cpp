#include <iostream>
#include "../../helper.cpp"
using namespace std;

void c_783()
{
    size_t n;
    std::cin >> n;

    unsigned long long **data = Utils::allocate_matrix<unsigned long long>(n, n);
    Utils::GetMatrixFromConsole(data, n, n);

    unsigned long long sum = 0;

    for (size_t i = 1; i < n - 1; i++)
        sum += data[i][i - 1] + data[i][i + 1];

    sum += data[0][1] + data[n - 1][n - 2];

    std::cout << sum;

    Utils::delete_matrix(data, n, n);
}

void _783()
{
    int n;
    unsigned long long data[100][100], sum = 0;

    // citim datele de intrare
    cin >> n;
    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            cin >> data[r][c];

    // parcurgem prin elementele diagonalei principale, fara primul si ultimul
    for (int i = 1; i < n - 1; i++)
        // adaugam elementul din stanga si dreapta elementului de pe
        sum += data[i][i - 1] + data[i][i + 1];
    // adauagam elementele care lipsesc (din dreapta primului element al diag principale si din stanga ultimului element)
    sum += data[0][1] + data[n - 1][n - 2];

    // afisam rezultatul
    cout << sum;
}

int main()
{
    c_783();
    return 0;
}