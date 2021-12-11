#include <cstddef>
#include <iostream>
template < typename T>
void quicksorting ( T * array, bool F(T, T), int begin, int end)
{
    int i = begin;
    int j = end;
    int middle_element = array[(i + j) / 2];
    int temp;

    while (i <= j)
    {
        while (F(array[i], middle_element))
            i++;
        while (F(array[j], middle_element))
            j--;
        if (i <= j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    if (j > begin)
        quicksorting(array, F, begin, j);
    if (i < end)
        quicksorting(array, F, i, end);
}

template < typename T>
void quicksort(T* array, bool F(T, T), std::size_t size)
{
    quicksorting(array, F, 0, size - 1);
}

template < typename T, std::size_t N>
void quicksort(T ( &array) [N], bool F(T, T))
{
    quicksorting(array, F, 0, N - 1);
}

bool f(int x, int y)
{return x <= y; }

int main()
{
    int array[6] = { 1 , 6, 4, 3, 7 ,2 };
    quicksort(array, f);
    for (auto i : array)
    {
        std::cout << i << ' ';
    }
    return 0;
}