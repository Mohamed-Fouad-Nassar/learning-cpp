#include <iostream>
using namespace std;

#define SIZE 10

int main()
{
  int arr[SIZE] = {5, 2, 8, -1, 4, 7, -6, 9, 0, 3};
  int min, max, q = 4;

  // Find min and max
  min = max = arr[0];
  for (int i = 1; i < SIZE; i++)
  {
    if (arr[i] < min)
      min = arr[i];
    if (arr[i] > max)
      max = arr[i];
  }
  cout << "Min: " << min << ", Max: " << max << endl;
  cout << "-------------------" << endl;

  // Sort array
  for (int i = 0; i < SIZE - 1; i++)
  {
    for (int j = i + 1; j < SIZE; j++)
    {
      if (arr[i] > arr[j])
      {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }

  cout << "Sorted Array: ";
  for (int i = 0; i < SIZE; i++)
    cout << arr[i] << "\t";
  cout << "\n-------------------" << endl;

  // Search for q
  bool isFounded = false;
  for (int i = 0; i < SIZE; i++)
  {
    if (arr[i] == q)
    {
      isFounded = true;
      cout << "Number " << q << " found at index " << i << endl;
      // break; // for first occurrence only
    }
  }
  if (!isFounded)
    cout << "Number " << q << " not found in the array." << endl;

  return 0;
}