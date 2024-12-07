#include <fstream>
#include "../../helper.cpp"
using namespace std;

void c_191()
{
    ifstream ifile("maxmat.in");
    ofstream ofile("maxmat.out");

    size_t rows, cols;
    ifile >> rows >> cols;

    short **data = Utils::allocate_matrix<short>(rows, cols);
    Utils::GetMatrixFromFile(data, rows, cols, ifile);

    size_t *maxIndex = new size_t[rows];
    Utils::FillVector<size_t>(maxIndex, rows, (size_t)0);

    for (size_t r = 0; r < rows; r++)
        for (size_t c = 0; c < cols; c++)
            if (data[r][c] > data[r][maxIndex[r]])
                maxIndex[r] = c;

    for (size_t r = 0; r < rows - 1; r++)
        ofile << data[r][maxIndex[r]] << ' ' << maxIndex[r] + 1 << '\n';

    ofile << data[rows - 1][maxIndex[rows - 1]] << ' '
          << maxIndex[rows - 1] + 1;

    delete[] maxIndex;
    Utils::delete_matrix(data, rows, cols);
    ofile.close();
    ifile.close();
}

void _191()
{
    ifstream ifile("maxmat.in");
    ofstream ofile("maxmat.out");

    int n, m;
    short data[26][26];
    // declar un vector care va contine indicele elementuli max al fiecarei linii
    int maxIndex[26];

    // fiecare element al vectorului maxIndex trebuie sa fie 1 la inceput

    for (int i = 0; i < 26; i++)
        maxIndex[i] = 1;

    // citesc datele de intrare din fisier
    ifile >> n >> m;
    for (int r = 1; r <= n; r++)
        for (int c = 1; c <= m; c++)
            ifile >> data[r][c];

    // trec prin toate elementele matricei
    for (int r = 1; r <= n; r++)
        for (int c = 1; c <= m; c++)
            // daca elementul curent e mai mare decat maximul liniei, acesta devine noul maxim
            if (data[r][c] > data[r][maxIndex[r]])
                maxIndex[r] = c;
    // pentru fiecare linie, scriu elementul maxim si indicele acestuia
    for (int r = 1; r < n; r++)
        ofile << data[r][maxIndex[r]] << ' '
              << maxIndex[r] << '\n';

    ofile << data[n][maxIndex[n]] << ' ' << maxIndex[n];

    ofile.close();
    ifile.close();
}

int main()
{

    c_191();
    return 0;
}