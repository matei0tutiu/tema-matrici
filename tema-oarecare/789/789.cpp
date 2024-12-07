#include <iostream>
#include "../../helper.cpp"
using namespace std;

void c_789()
{

    size_t rows, cols;
    std::cin >> rows >> cols;
    size_t size = rows * cols;

    int *data = new int[size];
    Utils::ReadVectorFromConsole(data, size);

    int *valid = new int[size];
    size_t index = 0, counter = 0;

    for (size_t i = 0; i < size; i++)
    {
        counter = 1;
        for (size_t j = i + 1; j < size; j++)
            if (data[j] == data[i] && counter < 2)
                counter++;
        if (counter >= 2)
            valid[index++] = data[i];
    }

    if (index == 0)
    {
        std::cout << "IMPOSIBIL";
        return;
    }

    int max = valid[0];

    for (size_t i = 0; i < index; i++)
        if (valid[i] > max)
            max = valid[i];

    std::cout << max;

    delete[] valid;
    delete[] data;
}

void _789()
{
    // declar un al doilea vector, unde voi tine minte toate
    // elementele care apar de cel putin doua ori
    int n, m, data[100 * 100], valid[100 * 100], index = 0;

    // citesc datele de intrare
    cin >> n >> m;
    int dimensiune = n * m;
    for (int i = 0; i < dimensiune; i++)
        cin >> data[i];

    // trec prin toate elementele
    for (int i = 0; i < dimensiune; i++)
    {
        // am gasit elementul cel putin odata, la data[i]
        int contor = 1;

        // trecem prin toate elementele de dupa i
        for (int j = i + 1; j < dimensiune; j++)
            // daca mai gasim odata elementul, crestem contorul
            if (data[j] == data[i])
                contor++;

        // daca contorul e mai mare sau egal cu 2, adaugam
        // elemntul in al doilea vector
        if (contor >= 2)
            valid[index++] = data[i];
    }
    // daca index = 0, nici un element nu se repeta
    if (index == 0)
        cout << "IMPOSIBIL";
    else
    {

        // daca index != 0, gasesc maximul celui de-al doilea vector
        int max = valid[0];

        for (int i = 1; i < index; i++)
            if (valid[i] > max)
                max = valid[i];
        // afisez raspunsul
        cout << max;
    }
}

int main()
{
    c_789();
    return 0;
}
