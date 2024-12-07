#include <iostream>
#include "../../helper.cpp"
using namespace std;

void c_3124()
{
    size_t n;
    std::cin >> n;

    unsigned long long
        sum = 0,
        sumDiagPrincipal = 0,
        sumDiagSecundar = 0,
        **data = Utils::allocate_matrix<unsigned long long>(n, n);
    bool result = true;

    for (size_t r = 0; r < n; r++)
        for (size_t c = 0; c < n; c++)
        {
            std::cin >> data[r][c];
            if (data[r][c] > n * n || data[r][c] == 0)
                result = false;
        }

    for (size_t i = 0; i < n; i++)
        sum += data[i][0];

    for (size_t i = 0; i < n; i++)
    {
        sumDiagPrincipal += data[i][i];
        sumDiagSecundar += data[i][n - 1 - i];
        unsigned long long
            sumRow = 0,
            sumCol = 0;
        for (size_t j = 0; j < n; j++)
        {
            sumRow += data[i][j];
            sumCol += data[j][i];
        }

        result &= sumRow == sum;
        result &= sumCol == sum;
    }

    result &= sumDiagPrincipal == sum;
    result &= sumDiagSecundar == sum;

    std::cout << (result ? "true" : "false");

    Utils::delete_matrix(data, n, n);
}

void _3124()
{
    int n;
    cin >> n;

    unsigned long long
        sum = 0,
        sumDiagPrincipal = 0,
        sumDiagSecundar = 0,
        data[500][500];
    int result = 1;

    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
        {
            cin >> data[r][c];
            if (data[r][c] > n * n || data[r][c] == 0)
                result = 0;
        }

    for (int i = 0; i < n; i++)
        sum += data[i][0];

    for (int i = 0; i < n; i++)
    {
        sumDiagPrincipal += data[i][i];
        sumDiagSecundar += data[i][n - 1 - i];
        unsigned long long
            sumRow = 0,
            sumCol = 0;
        for (int j = 0; j < n; j++)
        {
            sumRow += data[i][j];
            sumCol += data[j][i];
        }

        if (sumRow != sum || sumCol != sum)
            result *= 0;
    }

    if (sumDiagPrincipal != sum || sumDiagSecundar != sum)
        result = 0;

    if (result == 0)
        cout << "false";
    else
        cout << "true";
}

int main()
{
    c_3124();
    return 0;
}