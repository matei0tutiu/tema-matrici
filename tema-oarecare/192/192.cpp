#include <fstream>
#include "../../helper.cpp"
using namespace std;

void c_192()
{
    ifstream ifile("sumcolmax.in");
    ofstream ofile("sumcolmax.out");
    size_t rows, cols;
    ifile >> rows >> cols;

    short **data = Utils::allocate_matrix<short>(rows, cols);
    Utils::GetMatrixFromFile(data, rows, cols, ifile);

    size_t maxIndex = 0;
    short maxSum = -32768;

    for (size_t c = 0; c < cols; c++)
    {
        short currentSum = 0;
        for (size_t r = 0; r < rows; r++)
            currentSum += data[r][c];
        if (currentSum > maxSum)
        {
            maxSum = currentSum;
            maxIndex = c;
        }
    }

    for (size_t r = 0; r < rows; r++)
        ofile << data[r][maxIndex] << ' ';

    Utils::delete_matrix(data, rows, cols);
    ofile.close();
    ifile.close();
}

void _192()
{
    ifstream ifile("sumcolmax.in");
    ofstream ofile("sumcolmax.out");
    int n, m;
    short data[25][25];

    // citim din fisier
    ifile >> n >> m;
    for (int r = 0; r < n; r++)
        for (int c = 0; c < m; c++)
            ifile >> data[r][c];

    // declaram sumaMaxima si indiceMaxim
    int indiceMaxim = 0;
    short sumaMaxima = 0;

    // la inceput, suma maxima e suma primei coloane
    for (int r = 0; r < n; r++)
        sumaMaxima += data[r][indiceMaxim];

    // trecem prin toate coloanele matricei
    for (int c = 1; c < m; c++)
    {
        // calculam suma coloanei curente
        short currentSum = 0;
        for (int r = 0; r < n; r++)
            currentSum += data[r][c];
        // daca suma curenta e strict mai mare decat suma maxima
        // sumaMaxima devine suma curenta, iar indiceMaxim devine c
        if (currentSum > sumaMaxima)
        {
            sumaMaxima = currentSum;
            indiceMaxim = c;
        }
    }

    // scriem elementele coloanei cu suma maxima in fisier
    for (int r = 0; r < n; r++)
        ofile << data[r][indiceMaxim] << ' ';

    ofile.close();
    ifile.close();
}

int main()
{
    c_192();
    return 0;
}