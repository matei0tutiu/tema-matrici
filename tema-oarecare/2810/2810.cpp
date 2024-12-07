#include <iostream>
#include <fstream>
#include "../../helper.cpp"
using namespace std;

void c_2810()
{
    size_t size;

    std::cin >> size;
    float **data = Utils::allocate_matrix<float>(size, size);
    Utils::GetMatrixFromConsole(data, size, size);

    float *averages = new float[size];

    for (size_t c = 0; c < size; c++)
    {
        averages[c] = 0;
        for (size_t r = 0; r < size; r++)
            averages[c] += data[r][c];
        averages[c] /= size;
    }

    for (size_t r = 0; r < size / 2; r++)
    {
        for (size_t c = 0; c < size; c++)
            std::cout << data[r][c] << ' ';
        std::cout << '\n';
    }

    for (size_t i = 0; i < size; i++)
        std::cout << averages[i] << ' ';
    std::cout << '\n';

    for (size_t r = size / 2; r < size; r++)
    {
        for (size_t c = 0; c < size; c++)
            std::cout << data[r][c] << ' ';
        std::cout << '\n';
    }

    delete[] averages;
    Utils::delete_matrix(data, size, size);
}

void _2810()
{
    int n;
    float data[50][50], medii[50];

    // citim datele de intrare
    cin >> n;
    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            cin >> data[r][c];

    // calculam media aritmetica a fiecarei coloane
    for (int c = 0; c < n; c++)
    {
        medii[c] = 0;
        for (int r = 0; r < n; r++)
            medii[c] = medii[c] + data[r][c];
        medii[c] = medii[c] / n;
    }

    // afisam prima jumatate a matricii
    for (int r = 0; r < n / 2; r++)
    {
        for (int c = 0; c < n; c++)
            cout << data[r][c] << ' ';
        cout << '\n';
    }

    // afisam mediile calculate
    for (int i = 0; i < n; i++)
        cout << medii[i] << ' ';
    cout << '\n';

    // afisam a doua jumatate a matricii
    for (int r = n / 2; r < n; r++)
    {
        for (int c = 0; c < n; c++)
            cout << data[r][c] << ' ';
        cout << '\n';
    }
}

int main()
{
    c_2810();
    return 0;
}