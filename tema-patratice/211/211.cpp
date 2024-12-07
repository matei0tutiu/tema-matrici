#include <iostream>
#include <fstream>
#include "../../helper.cpp"
using namespace std;

void c_211()
{
    size_t n;
    std::ifstream ifile("spirala.in");
    std::ofstream ofile("spirala.out");
    ifile >> n;

    int **data = Utils::allocate_matrix<int>(n, n);
    Utils::GetMatrixFromFile(data, n, n, ifile);

    for (size_t offset = 0; offset < (n / 2) + 1; offset++)
    {
        for (size_t i = offset; i < n - 1 - offset; i++)
            ofile << data[offset][i] << ' ';
        for (size_t i = offset; i < n - 1 - offset; i++)
            ofile << data[i][n - offset - 1] << ' ';
        for (size_t i = n - offset - 1; i > offset; i--)
            ofile << data[n - offset - 1][i] << ' ';
        for (size_t i = n - offset - 1; i > offset; i--)
            ofile << data[i][offset] << ' ';
    }

    if (n % 2 == 1)
        ofile << data[n / 2][n / 2];

    Utils::delete_matrix<int>(data, n, n);
    ofile.close();
    ifile.close();
}

void _211()
{
    int n, data[23][23];

    ifstream ifile("spirala.in");
    ofstream ofile("spirala.out");

    // citim datele de intrare
    ifile >> n;
    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            ifile >> data[r][c];

    // parcurgem diagonala principala, pana la jumatate
    for (int offset = 0; offset < (n / 2) + 1; offset++)
    {
        // scriem in fisier toate elementele de pe inelul corespunzator
        for (int i = offset; i < n - 1 - offset; i++)
            ofile << data[offset][i] << ' '; // prima linie
        for (int i = offset; i < n - 1 - offset; i++)
            ofile << data[i][n - offset - 1] << ' '; // ultima coloana
        for (int i = n - offset - 1; i > offset; i--)
            ofile << data[n - offset - 1][i] << ' '; // ultima linie
        for (int i = n - offset - 1; i > offset; i--)
            ofile << data[i][offset] << ' '; // prima coloana
    }

    // daca n este impar, trebuie scrisa valoarea din centru
    if (n % 2 == 1)
        ofile << data[n / 2][n / 2];

    // inchidem fisierul
    ofile.close();
    ifile.close();
}

int main()
{
    c_211();

    return 0;
}