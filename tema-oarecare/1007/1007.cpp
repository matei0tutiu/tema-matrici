#include <fstream>
#include "../../helper.cpp"
using namespace std;

void c_1007()
{
    std::ifstream ifile("matrice7.in");
    std::ofstream ofile("matrice7.out");

    size_t rows, cols;
    ifile >> rows >> cols;
    unsigned long long **data = Utils::allocate_matrix<unsigned long long>(rows, cols);
    Utils::GetMatrixFromFile(data, rows, cols, ifile);

    unsigned long long *mins = new unsigned long long[cols];
    unsigned long long max = 0;

    for (size_t c = 0; c < cols; c++)
    {
        mins[c] = (unsigned long long)(-1);

        for (size_t r = 0; r < rows; r++)
        {
            if (data[r][c] > max)
                max = data[r][c];
            if (data[r][c] < mins[c])
                mins[c] = data[r][c];
        }
    }

    for (size_t r = 0; r < rows; r++)
    {
        for (size_t c = 0; c < cols; c++)
            if (data[r][c] != max)
                ofile << data[r][c] << ' ';
            else
                ofile << mins[c] << ' ';
        ofile << '\n';
    }

    delete[] mins;
    Utils::delete_matrix(data, rows, cols);
    ifile.close();
    ofile.close();
}

void _1007()
{

    ifstream ifile("matrice7.in");
    ofstream ofile("matrice7.out");
    int n, m;
    unsigned long long data[100][100];

    // citim datele de intrare
    ifile >> n >> m;
    for (int r = 0; r < n; r++)
        for (int c = 0; c < m; c++)
            ifile >> data[r][c];

    // declar un vector pentru valorile minime ale coloanelor
    unsigned long long mins[100];
    unsigned long long max = 0;

    // calculam maximul matricei, si valorile minime ale coloanelor
    for (int c = 0; c < m; c++)
    {
        // momentan, valoarea minima este prima de pe coloana
        mins[c] = data[0][c];
        for (int r = 0; r < n; r++)
        {
            // maximul matricei
            if (data[r][c] > max)
                max = data[r][c];
            // minimul coloanei
            if (data[r][c] < mins[c])
                mins[c] = data[r][c];
        }
    }

    // trecem prin elementele matricei
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < m; c++)
            // daca elementul este egal cu maximul, scrie minimul coloanei
            // daca nu, scrie elementul
            if (data[r][c] == max)
                ofile << mins[c] << ' ';
            else
                ofile << data[r][c] << ' ';
        // final de rand
        ofile << '\n';
    }

    // inchidem fisierele
    ifile.close();
    ofile.close();
}

int main()
{
    c_1007();
    return 0;
}