#include <fstream>
#include "../../helper.cpp"
#include <iomanip>
using namespace std;

void c_234()
{
    size_t n;
    std::ifstream ifile("medpoz.in");
    std::ofstream ofile("medpoz.out");

    ifile >> n;

    int **data = Utils::allocate_matrix<int>(n, n);

    Utils::GetMatrixFromFile(data, n, n, ifile);

    int sum = 0, counter = 0;

    for (size_t r = 0; r < n; r++)
        for (size_t c = 0; c < r; c++)
            if (data[r][c] > 0)
            {
                sum += data[r][c];
                counter++;
            }
    ofile << std::fixed << std::setprecision(3) << (float)sum / counter;

    ifile.close();
    ofile.close();
    Utils::delete_matrix<int>(data, n, n);
}

void _234()
{
    //! trebuie adaugat "#include <iomanip>" la inceputul fisierului
    int n, data[20][20];
    ifstream ifile("medpoz.in");
    ofstream ofile("medpoz.out");

    // citim valorile matricei
    ifile >> n;
    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            ifile >> data[r][c];

    int sum = 0, counter = 0;
    // adaugam numerele pozitive la suma si numaram in contor cate sunt
    for (int r = 0; r < n; r++)
        for (int c = 0; c < r; c++)
            if (data[r][c] > 0)
            {
                sum += data[r][c];
                counter++;
            }

    // scriem in fisier media lor (suma / contor), cu o precizie de 3 decimale
    ofile << fixed << setprecision(3) << (float)sum / counter;

    // inchidem fisierul
    ifile.close();
    ofile.close();
}

int main()
{
    c_234();
    return 0;
}