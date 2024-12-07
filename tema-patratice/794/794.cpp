#include <iostream>
#include <fstream>
#include "../../helper.cpp"

using namespace std;

void PrintDiagFromCol(unsigned long long **data, size_t startingCol, const bool upToDown)
{
    if (upToDown)
    {
        for (size_t i = 0; i <= startingCol; i++)
            std::cout << data[i][startingCol - i] << ' ';
    }
    else
    {
        for (size_t i = startingCol + 1; i > 0; i--)
            std::cout << data[i - 1][startingCol - i + 1] << ' ';
    }
}

void PrintDiagFromRow(unsigned long long **data, size_t size, size_t startingRow, const bool upToDown)
{
    if (upToDown)
    {
        for (size_t i = 0; i < size - startingRow; i++)
            std::cout << data[startingRow + i][size - 1 - i] << ' ';
    }
    else
    {

        for (size_t i = size - startingRow; i > 0; i--)
            std::cout << data[startingRow + i - 1][size - i] << ' ';
    }
}

void c_794()
{
    size_t n;
    std::cin >> n;

    unsigned long long **data = Utils::allocate_matrix<unsigned long long>(n, n);
    Utils::GetMatrixFromConsole(data, n, n);

    for (size_t startingCol = 0; startingCol < n; startingCol++)
        PrintDiagFromCol(data, startingCol, startingCol % 2 == 0);

    for (size_t startingRow = 1; startingRow < n; startingRow++)
        PrintDiagFromRow(data, n, startingRow, (n - startingRow) % 2);

    Utils::delete_matrix(data, n, n);
}

void _794()
{

    int n;
    unsigned long long data[25][25];
    // citim datele de intrare de la tastatura
    cin >> n;
    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            cin >> data[r][c];

    /*
        a b c d
        e f g h
        i j k l
        m n o p

        ideea este sa parcurem matricea pe diagonale paralele cu ce secundara
        trebuie afisate diagonalele, una de sus in jos, cealalta de jos in sus


    */

    // afisam toate diagonalele de deasupra inclusiv cea secundara
    for (int startingCol = 0; startingCol < n; startingCol++)
        // alternativ, schimbam ordinea in care se afiseaza fiecare diagonala
        if (startingCol % 2 == 0)
            for (int i = 0; i <= startingCol; i++)
                std::cout << data[i][startingCol - i] << ' ';
        else
            for (int i = startingCol + 1; i > 0; i--)
                std::cout << data[i - 1][startingCol - i + 1] << ' ';

    // pornim de la diagonala de sub cea secundara si
    for (int startingRow = 1; startingRow < n; startingRow++)
        // alternativ, schimbab ordinea in care se afiseaza diagonalele
        if ((n - startingRow) % 2)
            for (int i = 0; i < n - startingRow; i++)
                std::cout << data[startingRow + i][n - 1 - i] << ' ';
        else
            for (int i = n - startingRow; i > 0; i--)
                std::cout << data[startingRow + i - 1][n - i] << ' ';
}

int main()
{
    c_794();
    return 0;
}