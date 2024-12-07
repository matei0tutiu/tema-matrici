#include <iostream>
#include <fstream>

class Utils
{
public:
    template <typename T>
    static T **allocate_matrix(size_t rows, size_t cols)
    {
        T **res = new T *[rows];
        for (size_t r = 0; r < rows; r++)
            res[r] = new T[cols];
        return res;
    }

    template <typename T>
    static void delete_matrix(T **matrix, size_t rows, size_t cols)
    {
        for (size_t r = 0; r < rows; r++)
            delete[] matrix[r];
        delete[] matrix;
    }

    template <typename T>
    static void GetMatrixFromConsole(T **matrix, size_t rows, size_t cols)
    {
        for (size_t r = 0; r < rows; r++)
            for (size_t c = 0; c < cols; c++)
                std::cin >> matrix[r][c];
    }

    template <typename T>
    static void GetMatrixFromFile(T **matrix, size_t rows, size_t cols, std::ifstream &inputFile)
    {
        for (size_t r = 0; r < rows; r++)
            for (size_t c = 0; c < cols; c++)
                inputFile >> matrix[r][c];
    }

    template <typename T>
    static void GetPlaceholderMatrix(T **buffer, const size_t rows, const size_t cols)
    {
        for (size_t r = 0; r < rows; r++)
            for (size_t c = 0; c < cols; c++)
                buffer[r][c] = r * cols + c + 1;
    }

    template <typename T>
    static void FillVector(T *buffer, size_t size, const T value)
    {
        for (size_t i = 0; i < size; i++)
            buffer[i] = value;
    }

    template <typename T>
    static void FillMatrix(T **buffer, size_t rows, size_t cols, const T value)
    {
        for (size_t r = 0; r < rows; r++)
            for (size_t c = 0; c < cols; c++)
                buffer[r][c] = value;
    }

    template <typename T>
    static void PrintMatrix(T **matrix, size_t rows, size_t cols)
    {
        for (size_t r = 0; r < rows; r++)
        {
            for (size_t c = 0; c < cols; c++)
                std::cout << matrix[r][c] << ' ';
            std::cout << std::endl;
        }
    }

    template <typename T>
    static void PrintVector(T *vector, size_t size)
    {
        for (size_t i = 0; i < size; i++)
            std::cout << vector[i] << ' ';
        std::cout << std::endl;
    }

    template <typename T>
    static void Interchange(T &a, T &b)
    {
        a += b;
        b = a - b;
        a -= b;
    }

    template <typename T>
    static void ReadVectorFromConsole(T *buffer, size_t size)
    {
        for (size_t i = 0; i < size; i++)
            std::cin >> buffer[i];
    }

    template <typename T>
    static void ReadVectorFromFile(T *buffer, size_t size, std::ifstream &inputFileStream)
    {
        for (size_t i = 0; i < size; i++)
            inputFileStream >> buffer[i];
    }

    template <typename T>
    static T min(T *vector, size_t size)
    {
        T min = vector[0];
        for (size_t i = 1; i < size; i++)
            if (vector[i] < min)
                min = vector[i];
        return min;
    }

    template <typename T>
    static T max(T *vector, size_t size)
    {
        T max = vector[0];
        for (size_t i = 1; i < size; i++)
            if (vector[i] > max)
                max = vector[i];
        return max;
    }

    template <typename T>
    static void bubblesort(T *vector, size_t size, bool reverse = false)
    {
        size_t swapCount = 1;

        if (!reverse)
        {

            for (size_t i = size - 1; swapCount > 0; i--)
            {
                swapCount = 0;
                for (size_t j = 0; j < i; j++)
                    if (vector[j] > vector[j + 1])
                    {
                        Interchange(vector[j], vector[j + 1]);
                        swapCount++;
                    }
            }
        }
        else
        {
            for (size_t i = 0; swapCount > 0; i++)
            {
                swapCount = 0;
                for (size_t j = size - 1; j > i; j--)
                    if (vector[j] > vector[j - 1])
                    {
                        Interchange(vector[j], vector[j - 1]);
                        swapCount++;
                    }
            }
        }
    }
};
