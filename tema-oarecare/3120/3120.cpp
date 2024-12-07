#include <iostream>
#include "../../helper.cpp"
using namespace std;

void c_3120()
{
    size_t rows, cols;
    std::cin >> rows >> cols;

    short **data = Utils::allocate_matrix<short>(rows, cols);
    Utils::GetMatrixFromConsole(data, rows, cols);

    bool simetric = true;

    for (size_t r = 0; r < rows; r++)
        for (size_t c = 0; c < cols / 2; c++)
            simetric &= data[r][c] == data[r][cols - 1 - c];

    std::cout << (simetric ? "DA" : "NU");

    Utils::delete_matrix(data, rows, cols);
}

void _3120()
{
    int n, m, data[21][21];

    // citim datele de intrare
    cin >> n >> m;
    for (int r = 0; r < n; r++)
        for (int c = 0; c < m; c++)
            cin >> data[r][c];

    // presupunem ca matricea e simetrica
    int simetric = 1;

    for (int r = 0; r < n; r++)
        for (int c = 0; c < m / 2; c++)
            // daca exista cel putin un element care nu e simetric
            // fata de coloana din mijloc, simetric devine 0
            if (data[r][c] != data[r][m - 1 - c])
                simetric = 0;

    if (simetric == 1)
        cout << "DA";
    else
        cout << "NU";
}

int main()
{
    c_3120();
    return 0;
}