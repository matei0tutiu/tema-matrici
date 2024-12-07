#include <iostream>
#include "../../helper.cpp"
using namespace std;

void c_619()
{
    size_t rows, cols;
    std::cin >> rows >> cols;

    short **data = Utils::allocate_matrix<short>(rows, cols);
    Utils::GetMatrixFromConsole(data, rows, cols);

    for (size_t r = 0; r < rows; r++)
        Utils::bubblesort(data[r], cols);

    Utils::PrintMatrix(data, rows, cols);
    Utils::delete_matrix(data, rows, cols);
}

void _619()
{
    int n, m;
    short data[100][100];

    // citim datele
    cin >> n >> m;
    for (int r = 0; r < n; r++)
        for (int c = 0; c < m; c++)
            cin >> data[r][c];

    // sortam fiecare linie cu metoda bubblesort
    for (int r = 0; r < n; r++)
    {
        int swapCount = 1;

        for (int i = m - 1; swapCount > 0; i--)
        {
            swapCount = 0;
            for (int j = 0; j < i; j++)
                if (data[r][j] > data[r][j + 1])
                {
                    short temp = data[r][j];
                    data[r][j] = data[r][j + 1];
                    data[r][j + 1] = temp;
                    swapCount++;
                }
        }
    }

    // afisam matricea
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < m; c++)
            cout << data[r][c] << ' ';
        cout << '\n';
    }
}

int main()
{
    c_619();
    return 0;
}