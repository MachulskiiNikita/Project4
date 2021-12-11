#include <cstddef>
#include <iostream>
template < typename T, typename C>
void quicksorting ( T * array, C F, int begin, int end)
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
            std::swap(array[i] , array[j]);
            i++;
            j--;
        }
    }
    if (j > begin)
        quicksorting(array, F, begin, j);
    if (i < end)
        quicksorting(array, F, i, end);
}

template < typename T, typename C>
void quicksort(T* array, C F, std::size_t size)
{
    quicksorting(array, F, 0, size - 1);
}

template < typename T, std::size_t N, typename C>
void quicksort(T ( &array) [N], C F)
{
    quicksorting(array, F, 0, N - 1);
}



int main()
{
    int array[6] = { 1 , 6, 4, 3, 7 ,2 };
    quicksort(array, [](int x, int y) {return x <= y; });
    for (auto i : array)
    {
        std::cout << i << ' ';
    }
    return 0;
}