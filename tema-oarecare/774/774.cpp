#include <iostream>
#include "../../helper.cpp"
using namespace std;

bool isPrime(int x)
{
    bool result = true;

    for (int i = 2; i * i <= x; i++)
        result &= (x % i != 0);

    return result;
}

void c_774()
{
    size_t rows, cols;

    std::cin >> rows >> cols;
    int **data = Utils::allocate_matrix<int>(rows, cols);
    Utils::GetMatrixFromConsole(data, rows, cols);

    for (size_t r = 0; r < rows; r++)
        if (!isPrime(data[r][0]))
            Utils::PrintVector(data[r], cols);

    Utils::delete_matrix(data, rows, cols);
}

void _774()
{

    int n, m,
        data[100][100];

    // citim datele de la tastatura
    cin >> n >> m;
    for (int r = 0; r < n; r++)
        for (int c = 0; c < m; c++)
            cin >> data[r][c];

    // trecem prin toate liniile matricei
    for (int r = 0; r < n; r++)
    {
        // verificam daca primul element al linei e prim
        int prim = 1;

        for (int i = 2; i * i <= data[r][0]; i++)
            if (data[r][0] % i == 0)
                prim = 0;

        // daca nu e prim, afisam linia
        if (prim == 0)
        {
            for (int c = 0; c < m; c++)
                cout << data[r][c] << ' ';
            cout << '\n';
        }
    }
}

int main()
{
    _774();
    return 0;
}