#include <iostream>
#include "../../helper.cpp"
using namespace std;

void c_779()
{

    size_t rows, cols;
    std::cin >> rows >> cols;

    int **data = Utils::allocate_matrix<int>(rows + 2, cols + 2);
    for (size_t c = 0; c <= cols + 1; c++)
    {
        data[0][c] = 0;
        data[rows + 1][c] = 0;
    }

    for (size_t r = 1; r <= rows; r++)
    {
        data[r][0] = 0;
        data[r][cols + 1] = 0;
    }

    for (size_t r = 1; r <= rows; r++)
        for (size_t c = 1; c <= cols; c++)
            cin >> data[r][c];

    size_t counter = 0;

    for (size_t r = 1; r <= rows; r++)
    {

        for (size_t c = 1; c <= cols; c++)
            if (
                data[r + 1][c] % 2 == 0 &&
                data[r - 1][c] % 2 == 0 &&
                data[r][c + 1] % 2 == 0 &&
                data[r][c - 1] % 2 == 0)
                counter++;
    }

    std::cout << counter;
    Utils::delete_matrix(data, rows + 2, cols + 2);
}

void _779()
{
    // creez o matrice cu o margine de elemente care respecta conditia
    int n, m, data[102][102] = {{0}};

    // citesc datele de la tastatura
    cin >> n >> m;
    for (int r = 1; r <= n; r++)
        for (int c = 1; c <= m; c++)
            cin >> data[r][c];

    int contor = 0;
    // trec prin toate elementele matricei
    for (int r = 1; r <= n; r++)
        for (int c = 1; c <= m; c++)
            // daca toti vecinii sunt pari, adaug 1 la contor
            if (
                data[r + 1][c] % 2 == 0 &&
                data[r - 1][c] % 2 == 0 &&
                data[r][c + 1] % 2 == 0 &&
                data[r][c - 1] % 2 == 0)
                contor++;

    cout << contor;
}

int main()
{
    c_779();
    return 0;
}