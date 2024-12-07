#include <iostream>
#include "../../helper.cpp"
using namespace std;

void c_729()
{
    size_t n;
    std::cin >> n;

    int **data = Utils::allocate_matrix<int>(n, n);
    Utils::GetMatrixFromConsole(data, n, n);
    int frec[1001] = {0};

    for (size_t c = 0; c < n / 2; c++)
        for (size_t r = c + 1; r < n - 1 - c; r++)
            frec[data[r][c]]++;

    for (size_t i = 0; i < 1001; i++)
        if (frec[i])
            std::cout << i << ' ';

    Utils::delete_matrix(data, n, n);
}

void _729()
{
    int n;
    cin >> n;

    // se citesc elementele de la tastatura
    int data[200][200];
    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            cin >> data[r][c];

    // declaram un vector de frecventa
    int frec[1001] = {0};

    // se trece prin toate elementele de sub diagonala principala si deasupra diagonalei secundare
    for (int c = 0; c < n / 2; c++)
        for (int r = c + 1; r < n - 1 - c; r++)
            // crestem valoarea vectorului de frecventa pentru valoarea curenta
            frec[data[r][c]]++;

    // se afiseaza toate valorile care apar, in ordine crescatoare
    for (int i = 0; i < 1001; i++)
        if (frec[i])
            cout << i << ' ';
}

int main()
{
    c_729();
    return 0;
}