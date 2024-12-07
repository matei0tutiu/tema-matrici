#include <iostream>
#include "../../helper.cpp"
using namespace std;

void c_780()
{
    size_t n;
    std::cin >> n;

    unsigned long long **data = Utils::allocate_matrix<unsigned long long>(n, n);
    Utils::GetMatrixFromConsole(data, n, n);
    unsigned long long jos = 0, sus = 0, temp = 0;

    for (size_t r = 0; r < n - 1; r++)
        for (size_t c = r + 1; c < n; c++)
            sus += data[r][c];

    for (size_t r = 1; r < n; r++)
        for (size_t c = 0; c < r; c++)
            jos += data[r][c];

    while (sus)
    {
        temp = jos % sus;
        jos = sus;
        sus = temp;
    }

    std::cout << jos;

    Utils::delete_matrix(data, n, n);
}

void _780()
{
    int n;
    cin >> n;

    // citim matricea de la tastatura
    unsigned long long data[20][20];
    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            cin >> data[r][c];

    // declaram variabile pentru sumele pe care le tinem minte, si o variabila temp pentru calcularea cmmdc
    unsigned long long jos = 0, sus = 0, temp = 0;

    // adunam toate elementele de deasupra diagonalei principale
    for (int r = 0; r < n - 1; r++)
        for (int c = r + 1; c < n; c++)
            sus += data[r][c];

    // adunam toate elementele de sub diagonala secundata
    for (int r = 1; r < n; r++)
        for (int c = 0; c < r; c++)
            jos += data[r][c];

    // calculam cmmdc ( rezultatul ramane in {jos} )
    while (sus)
    {
        temp = jos % sus;
        jos = sus;
        sus = temp;
    }

    // scriem rezultatul
    cout << jos;
}

int main()
{
    c_780();
    return 0;
}