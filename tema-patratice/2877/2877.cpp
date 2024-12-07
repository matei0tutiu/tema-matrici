#include <iostream>
#include "../../helper.cpp"
using namespace std;

void c_2877()
{
    // TODO: algoritm de sortare mai bun

    size_t n;
    std::cin >> n;

    short **data = Utils::allocate_matrix<short>(n, n);
    Utils::GetMatrixFromConsole(data, n, n);

    for (size_t r = 0; r < n; r++)
        Utils::bubblesort(data[r], n);

    for (size_t c = 0; c < n; c++)
    {
        size_t swapCount = 1;

        for (size_t i = n - 1; swapCount > 0; i--)
        {
            swapCount = 0;
            for (size_t j = 0; j < i; j++)
                if (data[j][c] > data[j + 1][c])
                {
                    Utils::Interchange(data[j][c], data[j + 1][c]);
                    swapCount++;
                }
        }
    }

    Utils::PrintMatrix(data, n, n);
    Utils::delete_matrix(data, n, n);
}

void _2877()
{
    int n,
        data[100][100];
    // citim datele de intrare
    cin >> n;
    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            cin >> data[r][c];

    // sortam liniile matricei
    for (int r = 0; r < n; r++)
    {
        int swapCount = 1;

        for (int i = n - 1; swapCount > 0; i--)
        {
            swapCount = 0;
            for (int j = 0; j < i; j++)
                if (data[r][j] > data[r][j + 1])
                {
                    int temp = data[r][j];
                    data[r][j] = data[r][j + 1];
                    data[r][j + 1] = temp;
                    swapCount++;
                }
        }
    }

    // sortam coloanele matricei
    for (int c = 0; c < n; c++)
    {
        int swapCount = 1;
        for (int i = n - 1; swapCount > 0; i--)
        {
            swapCount = 0;
            for (int j = 0; j < i; j++)
                if (data[j][c] > data[j + 1][c])
                {
                    int temp = data[j][c];
                    data[j][c] = data[j + 1][c];
                    data[j + 1][c] = temp;
                    swapCount++;
                }
        }
    }

    // afisam matricea
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
            cout << data[r][c] << ' ';
        cout << '\n';
    }
}

int main()
{
    c_2877();
    return 0;
}