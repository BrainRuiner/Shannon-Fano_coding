#include <iostream>
#include "utils/quickSort.hpp"

void print(int* arr, int size)
{
  for (int i = 0; i < size; ++i)
  {
    std::cout << arr[i] << ' ';
  }
  std::cout << '\n';
}

int main()
{
  int arr[10] = { 6,3,8,2,8,1,7,3,6,0 };
  print(arr, 10);
  utils::quickSort(arr, 10, [](int a, int b)
    {
      return a < b;
    });
  print(arr, 10);
  return 0;
}
