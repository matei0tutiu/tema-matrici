#include <iostream>
#include "../../helper.cpp"
using namespace std;

void c_2825()
{
    size_t rows, cols;
    std::cin >> rows >> cols;

    short **data = Utils::allocate_matrix<short>(rows, cols),
          x;
    Utils::GetMatrixFromConsole(data, rows, cols);
    std::cin >> x;

    for (size_t r = 0; r < rows; r++)
        if (data[r][0] == x || data[r][cols - 1] == x)
        {
            std::cout << "DA";
            return;
        }

    for (size_t c = 1; c < cols - 1; c++)
        if (data[0][c] == x || data[rows - 1][c] == x)
        {
            std::cout << "DA";
            return;
        }

    std::cout << "NU";

    Utils::delete_matrix(data, rows, cols);
}

void _2825()
{
    int n, m, data[100][100], x;

    // citim datele de intrare
    cin >> n >> m;
    for (int r = 0; r < n; r++)
        for (int c = 0; c < m; c++)
            cin >> data[r][c];
    cin >> x;

    int amScris = 0;

    // trecem prin toate liniile matricei
    for (int r = 0; r < n && amScris == 0; r++)
        // daca elementul de pe linia r si prima sau ultima coloana
        // e egal cu x, scriem "DA" si nu mai facem nimic altceva
        if (data[r][0] == x || data[r][m - 1] == x)
        {
            cout << "DA";
            amScris = 1;
        }
    // trecem prin coloanele matricei pe care nu le-am verificat
    for (int c = 1; c < m - 1 && amScris == 0; c++)
        // daca elementul de pe coloana c si prima sau ultima linie
        // este egal cu x, scriem "DA", apoi nu mai facem nimic
        if (data[0][c] == x || data[n - 1][c] == x)
        {
            cout << "DA";
            amScris = 1;
        }

    // daca nu am scris nimic pana acum, elementul X nu apare pe
    // conturul tabloului, deci scriem "NU"
    if (amScris == 0)
        cout << "NU";
}

int main()
{
    c_2825();
    return 0;
}