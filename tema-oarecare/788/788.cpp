#include <iostream>
#include "../../helper.cpp"
using namespace std;

bool isPrime(int x)
{
    if (x == 1 || x == 0)
        return false;

    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;

    return true;
}

void c_788()
{

    size_t rows, cols;

    std::cin >> rows >> cols;
    int **data = Utils::allocate_matrix<int>(rows, cols);
    Utils::GetMatrixFromConsole(data, rows, cols);

    // trec prin toate randurile matricei
    for (size_t r = 0; r < rows; r++)
    {
        if (isPrime(data[r][0]))
        {

            for (size_t c = 0; c < cols; c++)
                std::cout << data[r][cols - 1 - c] << ' ';
        }
        else
        {
            for (size_t c = 0; c < cols; c++)
                std::cout << data[r][c] << ' ';
        }
        std::cout << std::endl;
    }

    Utils::delete_matrix(data, rows, cols);
}

void _788()
{
    int n, m,
        data[100][100];
    // citim datele de intrare de la tastatura
    cin >> n >> m;
    for (int r = 0; r < n; r++)
        for (int c = 0; c < m; c++)
            cin >> data[r][c];

    // trec prin toate randurile matricei
    for (int r = 0; r < n; r++)
    {
        // verific daca primul element al randului e prim
        int prim = 1;

        // daca gasesc un divizor, numarul nu e prim
        for (int i = 2; i * i <= data[r][0]; i++)
            if (data[r][0] % i == 0)
                prim = 0;

        // 0 si 1 cazuri speciale
        if (data[r][0] == 1 || data[r][0] == 0)
            prim = 0;

        if (prim == 1)
        {
            // daca e prim, scriu randul in ordine inversa
            for (int c = 0; c < m; c++)
                cout << data[r][m - 1 - c] << ' ';
        }
        else
        {
            // daca nu e prim, scriu randul in ordine normala
            for (int c = 0; c < m; c++)
                cout << data[r][c] << ' ';
        }
        // trec la randul urmator
        cout << endl;
    }
}

int main()
{
    c_788();
    return 0;
}