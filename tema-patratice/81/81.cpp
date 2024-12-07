#include <iostream>
#include "../../helper.cpp"
using namespace std;

void c_81()
{
    size_t n, counter = 0;

    std::cin >> n;

    int **data = Utils::allocate_matrix<int>(n + 2, n + 2);
    Utils::FillMatrix(data, n + 2, n + 2, 0);

    for (size_t r = 1; r <= n; r++)
        for (size_t c = 1; c <= n; c++)
            std::cin >> data[r][c];

    for (size_t r = 1; r <= n; r++)
        for (size_t c = 1; c <= n; c++)
            if (data[r][c] > data[r + 1][c] &&
                data[r][c] > data[r - 1][c] &&
                data[r][c] > data[r][c + 1] &&
                data[r][c] > data[r][c - 1])
                counter++;

    std::cout << counter;

    Utils::delete_matrix(data, n + 2, n + 2);
}

void _81()
{
    // declaram un contor, si o matrice cu o margine de un element (22 x 22 in loc de 20 x 20 )
    int n, counter = 0, data[22][22] = {{0}};

    // citim datele de intrare de la tastatura
    cin >> n;
    for (int row = 1; row <= n; row++)
        for (int column = 1; column <= n; column++)
            cin >> data[row][column];

    // trecem prin toate valorile matricei
    for (int row = 1; row <= n; row++)
        for (int column = 1; column <= n; column++)
            if (data[row][column] > data[row + 1][column] && data[row][column] > data[row - 1][column] &&
                data[row][column] > data[row][column + 1] && data[row][column] > data[row][column - 1])
                // daca valoarea curenta e mai mare decat toate in jurul ei, crestem valoarea contorului
                counter++;
    // afisam valoarea conorului
    cout << counter;
}

int main()
{
    c_81();
    return 0;
}