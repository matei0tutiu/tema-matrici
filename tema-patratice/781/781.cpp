#include <iostream>
#include "../../helper.cpp"

using namespace std;

void c_781()
{
    size_t n;
    std::cin >> n;

    int **data = Utils::allocate_matrix<int>(n, n);
    Utils::GetMatrixFromConsole(data, n, n);

    long vec[4] = {0};

    // NORD
    for (size_t r = 0; r < n / 2; r++)
        for (size_t c = r + 1; c < n - r - 1; c++)
            vec[0] += data[r][c];

    // SUD

    for (size_t r = n - 1; r > n / 2; r--)
        for (size_t c = r - 1; c > n - r - 1; c--)
            vec[1] += data[r][c];

    // EST

    for (size_t c = 0; c < n / 2; c++)
        for (size_t r = c + 1; r < n - c - 1; r++)
            vec[2] += data[r][c];

    // VEST

    for (size_t c = n - 1; c > n / 2; c--)
        for (size_t r = c - 1; r > n - c - 1; r--)
            vec[3] += data[r][c];

    Utils::bubblesort(vec, 4);

    for (int i = 0; i < 4; i++)
        std::cout << vec[i] << ' ';

    Utils::delete_matrix(data, n, n);
}

void _781()
{

    int n;
    cin >> n;

    // citim matricea de la tastatura
    int data[100][100];
    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            cin >> data[r][c];

    // declaram un vector cu 4 valori, una pentru fiecare zona a matricei
    long vec[4];

    // calculam suma pentru NORD in vec[0]
    for (int r = 0; r < n / 2; r++)
        for (int c = r + 1; c < n - r - 1; c++)
            vec[0] += data[r][c];

    // calculam suma pentru SUD in vec[1]
    for (int r = n - 1; r > n / 2; r--)
        for (int c = r - 1; c > n - r - 1; c--)
            vec[1] += data[r][c];

    // calculam suma pentr EST in vec[2]
    for (int c = 0; c < n / 2; c++)
        for (int r = c + 1; r < n - c - 1; r++)
            vec[2] += data[r][c];

    // calculam suma pentru VEST in vec[3]
    for (int c = n - 1; c > n / 2; c--)
        for (int r = c - 1; r > n - c - 1; r--)
            vec[3] += data[r][c];

    // folosim BUBBLE SORT pentru a sorta vectorul (destul de eficienta pentru un vector scurt, cum este cazul aici )
    int swapCount = 1;

    for (int iterations = 0; swapCount > 0; iterations++)
    {
        swapCount = 0;
        for (int i = 0; i < 3 - iterations; i++)
            if (vec[i] > vec[i + 1])
            {
                int temp = vec[i];
                vec[i] = vec[i + 1];
                vec[i + 1] = temp;
                swapCount++;
            }
    }

    // afisam vectorul ordonat crescator
    for (int i = 0; i < 4; i++)
        cout << vec[i] << ' ';
}

int main()
{
    c_781();
    return 0;
}