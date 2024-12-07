#include <iostream>
#include "../../helper.cpp"
using namespace std;

void c_772()
{
    size_t rows, cols;
    std::cin >> rows >> cols;

    size_t size = rows * cols;
    int *data = new int[size];
    Utils::ReadVectorFromConsole(data, size);

    int *values = new int[size];
    size_t *frec = new size_t[size];
    size_t index = 0;

    for (size_t i = 0; i < size; i++)
    {
        bool found = false;
        for (size_t j = 0; j < index; j++)
            if (data[i] == values[j])
            {
                found = true;
                frec[j]++;
            }

        if (!found)
        {
            values[index] = data[i];
            frec[index] = 1;
            index++;
        }
    }

    size_t max = Utils::max(frec, index);

    size_t contor = 0;

    for (size_t i = 0; i < index; i++)
        if (frec[i] == max)
            frec[contor++] = values[i];

    Utils::bubblesort(frec, contor);
    Utils::PrintVector(frec, contor);

    delete[] values;
    delete[] frec;
    delete[] data;
}
void _772()
{
    /*
        declaram doi vectori
        pentru un indice i, valori[i] va reprezenta valoarea unui
        element din matrice, iar frec[i] numarul sau de aparitii

        marimeFrec este marimea vectorilor valori si frec
    */
    int n, m, dimensiune, marimeFrec = 0, contor = 0,
                          data[100 * 100],
                          frec[100 * 100],
                          valori[100 * 100];

    // citim datele de intrare intr-un vector
    cin >> n >> m;
    dimensiune = n * m;
    for (int i = 0; i < dimensiune; i++)
        cin >> data[i];

    // trec prin toate elementele vectorului 'data'
    for (int i = 0; i < dimensiune; i++)
    {
        /*
            caut elementul curent in vectorul 'valori'
            daca il gasesc cresc valoarea lui 'frec' la acelasi indice
            daca NU il gasesc, il adaug in 'valori' si setez 'frec' la 1
        */

        int gasit = 0;

        for (int j = 0; j < marimeFrec; j++)
            if (data[i] == valori[j])
            {
                gasit = 1;
                frec[j]++;
            }

        if (gasit == 0)
        {
            valori[marimeFrec] = data[i];
            frec[marimeFrec] = 1;
            marimeFrec++;
        }
    }

    // gasesc valoarea maxima a lui frec
    int max = 0;

    for (int i = 0; i < marimeFrec; i++)
        if (frec[i] > max)
            max = frec[i];

    // trec prin toate valorile lui 'frec'
    for (int i = 0; i < marimeFrec; i++)
        if (frec[i] == max)
        {
            /*
             daca elementul i apare de max ori, il adaug la
             inceputul vectorului 'data' si cresc contorul
            * OBS: vectorul data se refoloseste, pentru a evita
            * alocarea unui nou vector
            * de aici inainte, marimea lui 'data' va fi 'contor', nu 'dimensiune'
            */
            data[contor] = valori[i];
            contor++;
        }

    // folosind metoda bubblesort, elementele din vectorul 'data'
    int swapCount = 1;

    for (int i = contor - 1; swapCount > 0; i--)
    {
        swapCount = 0;
        for (int j = 0; j < i; j++)
            if (data[j] > data[j + 1])
            {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
                swapCount++;
            }
    }

    // afisez vectorul 'data'
    for (int i = 0; i < contor; i++)
        cout << data[i] << ' ';
}

int main()
{
    _772();
    return 0;
}