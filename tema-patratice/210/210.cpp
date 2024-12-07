#include <iostream>
#include <fstream>
#include "../../helper.cpp"
using namespace std;

void c_210()
{
    size_t n;
    std::ifstream ifile("chenar.in");
    std::ofstream ofile("chenar.out");

    ifile >> n;

    int **data = Utils::allocate_matrix<int>(n, n);
    Utils::GetMatrixFromFile(data, n, n, ifile);

    for (size_t i = 0; i < n - 1; i++)
        ofile << data[0][i] << ' ';

    for (size_t i = 0; i < n - 1; i++)
        ofile << data[i][n - 1] << ' ';

    for (size_t i = n - 1; i > 0; i--)
        ofile << data[n - 1][i] << ' ';

    for (size_t i = n - 1; i > 0; i--)
        ofile << data[i][0] << ' ';

    Utils::delete_matrix(data, n, n);
    ifile.close();
    ofile.close();
}

void _210()
{
    int n, data[23][23];

    ifstream ifile("chenar.in");
    ofstream ofile("chenar.out");

    // citim valorile din fisier
    ifile >> n;
    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            ifile >> data[r][c];

    // prima linie
    for (int i = 0; i < n - 1; i++)
        ofile << data[0][i] << ' ';
    // ultima coloana
    for (int i = 0; i < n - 1; i++)
        ofile << data[i][n - 1] << ' ';
    // ultima linie
    for (int i = n - 1; i > 0; i--)
        ofile << data[n - 1][i] << ' ';
    // prima coloana
    for (int i = n - 1; i > 0; i--)
        ofile << data[i][0] << ' ';

    // inchidem fisierul
    ofile.close();
    ifile.close();
}

int main()
{
    c_210();
    return 0;
}