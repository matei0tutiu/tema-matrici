#include <iostream>
#include <fstream>
#include "../../helper.cpp"
using namespace std;

size_t FillRing(short **matrix, size_t startingRow, size_t startingCol, size_t ringSize, short *buffer, size_t bufferOffset)
{
    size_t row = startingRow;
    size_t col = startingCol;
    size_t bufferIndex = bufferOffset;

    for (size_t i = 0; i < ringSize - 1; i++)
        matrix[row++][col] = buffer[bufferIndex++];
    for (size_t i = 0; i < ringSize - 1; i++)
        matrix[row][col++] = buffer[bufferIndex++];
    for (size_t i = 0; i < ringSize - 1; i++)
        matrix[row--][col] = buffer[bufferIndex++];
    for (size_t i = 0; i < ringSize - 1; i++)
        matrix[row][col--] = buffer[bufferIndex++];

    return bufferIndex;
}

size_t FindSquareRoot(const size_t &x)
{
    size_t low = 1, high = 101, guess = 50;
    while (guess * guess != x)
    {
        if (guess * guess < x)
            low = guess;
        else
            high = guess;
        guess = (low + high) / 2;
    }
    return guess;
}

void c_1008()
{
    size_t n;
    std::ifstream ifile("spirala1.in");
    ifile >> n;
    size_t size = FindSquareRoot(n);

    short *buffer = new short[n];

    for (size_t i = 0; i < n; i++)
        ifile >> buffer[i];

    short **result = Utils::allocate_matrix<short>(size, size);
    Utils::FillMatrix<short>(result, size, size, 0);

    size_t offset = 0;

    for (size_t i = 0; i < size / 2; i++)
        offset = FillRing(result, i, i, size - 2 * i, buffer, offset);

    if (size % 2)
        result[size / 2][size / 2] = buffer[n - 1];

    std::ofstream ofile("spirala1.out");

    for (size_t r = 0; r < size; r++)
    {
        for (size_t c = 0; c < size; c++)
            ofile << result[r][c] << ' ';
        ofile << '\n';
    }

    ofile.close();
    Utils::delete_matrix(result, size, size);
    delete[] buffer;
    ifile.close();
}

void _1008()
{
    int n;
    short buffer[10000];
    short data[100][100];
    ifstream ifile("spirala1.in");
    ofstream ofile("spirala1.out");

    // citim din fisier datele intr-un vector
    ifile >> n;
    for (int i = 0; i < n; i++)
        ifile >> buffer[i];

    /*
        pentru a rezolva problema, construim matrice in 'inele'
        de ex, matricea de mai jos are trei inele:

        a b c d e
        f g h i j
        k l m n o
        p q r s t
        u v w x y

        inelul 1: a f k p u v w x y t o j e d c b
        inelul 2: g l q r s n i h
        inelul 3: m

        pentru un inel dat, denumim indicele elementului corespunzator de pe diagonala principala 'offset'
        pornind de la elementul matrice[offset][offset], construim matricea

    */

    // trebuie sa gasim numarul de linii si coloane ( radacina patrata a lui n)
    int low = 1, high = 101, guess = 50;
    while (guess * guess != n)
    {
        if (guess * guess < n)
            low = guess;
        else
            high = guess;
        guess = (low + high) / 2;
    }

    int size = guess;
    int offset = 0;
    // parcurgem elemenetele de pe diagonala principala pana la jumatate
    for (int i = 0; i < size / 2; i++)
    {
        // construim matricea cate un inel pe rand
        int row = i;
        int col = i;

        for (int j = 0; j < size - 2 * i - 1; j++)
            data[row++][col] = buffer[offset++];
        for (int j = 0; j < size - 2 * i - 1; j++)
            data[row][col++] = buffer[offset++];
        for (int j = 0; j < size - 2 * i - 1; j++)
            data[row--][col] = buffer[offset++];
        for (int j = 0; j < size - 2 * i - 1; j++)
            data[row][col--] = buffer[offset++];
    }

    // daca nr de linii este impar, trebuie adaugat elementul din mijlocului
    if (size % 2)
        data[size / 2][size / 2] = buffer[n - 1];

    // scriem matricea in fisier
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
            ofile << data[r][c] << ' ';
        ofile << '\n';
    }

    ifile.close();
    ofile.close();
}

int main()
{
    c_1008();
    return 0;
}