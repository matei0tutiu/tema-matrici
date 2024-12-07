#include <iostream>
#include "../../helper.cpp"
using namespace std;

void c_784()
{
    size_t n;
    std::cin >> n;

    int **data = Utils::allocate_matrix<int>(n, n);
    Utils::GetMatrixFromConsole(data, n, n);
    int *sumRows = new int[n];
    int *sumCols = new int[n];

    for (size_t i = 0; i < n; i++)
    {
        sumRows[i] = 0;
        sumCols[i] = 0;
    }

    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n; j++)
        {
            sumRows[i] += data[i][j];
            sumCols[i] += data[j][i];
        }

    unsigned long long counter = 0;

    for (size_t r = 0; r < n; r++)
        for (size_t c = 0; c < n; c++)
            if (sumRows[r] == sumCols[c])
                counter++;

    std::cout << counter;

    delete[] sumRows;
    delete[] sumCols;
    Utils::delete_matrix(data, n, n);
}

void _784()
{
    // declaram cate un vector pentru sumele liniilor si sumele coloanelor
    int n, data[100][100], sumeleLiniilor[100] = {0}, sumeleColoanelor[100] = {0};
    // citim datele de intrare
    cin >> n;
    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            cin >> data[r][c];
    // adunam liniile si coloanele in vectori
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            sumeleLiniilor[i] += data[i][j];
            sumeleColoanelor[i] += data[j][i];
        }

    // declaram un contor
    unsigned long long counter = 0;

    // trecem prin toate elementele matricei
    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            if (sumeleLiniilor[r] == sumeleColoanelor[c])
                // crestem contorul daca suma liniei si suma coloanei sunt egale
                counter++;

    // afisam rezultatul
    cout << counter;
}

int main()
{
    c_784();
    return 0;
}