#include <iostream>
#include "../../helper.cpp"

using namespace std;

void c_782()
{
    size_t n;
    std::cin >> n;

    int **data = Utils::allocate_matrix<int>(n, n);
    Utils::GetMatrixFromConsole(data, n, n);

    int frec[1001] = {0};

    for (size_t r = n / 2; r < n; r++)
        for (size_t c = r - 1; c > n - r - 1; c--)
            frec[data[r][c]]++;

    for (size_t i = 0; i < 1001; i++)
        if (frec[i] > 1)
            std::cout << i << ' ';

    Utils::delete_matrix(data, n, n);
}

void _782()
{
    int n, data[200][200];

    // citim datele de intrare de la tastatura
    cin >> n;
    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            cin >> data[r][c];

    // declaram un vector de frecventa
    int frec[1001] = {0};

    // trec prin regiunea ceruta si numar de cate ori apare fiecare valoare
    for (int r = n / 2; r < n; r++)
        for (int c = r - 1; c > n - r - 1; c--)
            frec[data[r][c]]++;

    // afisez toate numerele care apar cel putin odata
    for (int i = 0; i < 1001; i++)
        if (frec[i] > 1)
            cout << i << ' ';
}

int main()
{
    c_782();
    return 0;
}