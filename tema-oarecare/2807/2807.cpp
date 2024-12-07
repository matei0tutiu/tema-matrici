#include <iostream>
#include "../../helper.cpp"
using namespace std;

void c_2807()
{
    size_t rows, cols;
    std::cin >> rows >> cols;
    short **data = Utils::allocate_matrix<short>(rows, cols);
    Utils::GetMatrixFromConsole(data, rows, cols);

    size_t linieMinPrima = 0, linieMinUltima = 0;

    for (size_t r = 0; r < rows; r++)
    {
        if (data[r][0] < data[linieMinPrima][0])
            linieMinPrima = r;
        if (data[r][cols - 1] < data[linieMinUltima][cols - 1])
            linieMinUltima = r;
    }

    Utils::Interchange(data[linieMinPrima][0], data[linieMinUltima][cols - 1]);

    Utils::PrintMatrix(data, rows, cols);
    Utils::delete_matrix(data, rows, cols);
}

void _2807()
{
    int n, m;
    short data[50][50];

    // citim datele de intrare de la tastatura
    cin >> n >> m;
    for (int r = 0; r < n; r++)
        for (int c = 0; c < m; c++)
            cin >> data[r][c];

    // tin minte unde se afla elementele minime
    int linieMinPrima = 0, linieMinUltima = 0;

    for (int r = 0; r < n; r++)
    {
        // minimul prima coloana
        if (data[r][0] < data[linieMinPrima][0])
            linieMinPrima = r;
        // minimul ultima coloana
        if (data[r][m - 1] < data[linieMinUltima][m - 1])
            linieMinUltima = r;
    }

    // interschimb
    short temp = data[linieMinPrima][0];
    data[linieMinPrima][0] = data[linieMinUltima][m - 1];
    data[linieMinUltima][m - 1] = temp;

    // afisez matricea
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < m; c++)
            cout << data[r][c] << ' ';
        cout << endl;
    }
}

int main()
{
    c_2807();
    return 0;
}