# Pointers

A pointer is a variable that stores the **memory address** of another variable. So instead of holding a value (like 10), it holds the location in memory where that value is stored.

## Declaration

```cpp
dataType* pointerName;
```

We can write `int *p;` or `int* p;` — both are valid. The default value of pointer is `NULL`.

```cpp
int x = 10;     // normal variable
int* ptr = &x;    // pointer variable storing the address of x
char* cPtr;    // NULL

char c;
cPtr = c;     // ❌❌ this is the value of x but pointer carry address
cPtr = &c;    // pointer carry the address of variable c in memory

cout << ptr;    // address of the elements pointer point at (address of x => &x).
cout << &ptr;   // address of pointer itself (where this pointer in memory).
cout << *ptr;   // the value of element that pointer points at (value of x).

*ptr = 100;   // access variable x place and change its value
cout << x;  // 100
```

## size of pointer

It is different based on application size:

- codeblocks 17.12 32Bit 4B
- codeblocks 23.12 64Bit 8B

## Arithmetic Operators with Pointers

We can perform arithmetic operations on pointers to move through arrays.

```cpp
int arr[3] = {10, 20, 30};
int* p = arr;  // arr == &arr[0]

cout << *ptr;       // 10
cout << *(ptr + 1); // 20
cout << *(ptr + 2); // 30
```

Each `ptr + 1` moves the pointer by one element size, not by `1` byte.

## Pointers with Arrays

An array name acts like a **pointer** to its first element. so when a pointer points to array the pointer acts like the array itself so we can access elements by indexer of array with pointer

```cpp
int nums[3] = {5, 10, 15};
int* ptr = nums;

cout << ptr[0];     // 5
cout << ptr[1];     // 10
cout << *(ptr + 2); // 15
```

We can also use `ptr++` or `++ptr` to move the pointer but this change the actual location that pointer points to it so we need to reset the pointer using `ptr = arr;`.

## Pointer to Pointer

can also have a pointer that stores the address of another pointer.

```cpp
int x = 10;
int* ptr = &x;
int** ptrToPtr = &ptr;

cout << **ptrToPtr;  // Output: 10
```

## Pointer to Struct

```cpp
struct Person {
  string name;
  int age;
};

Person p1 = { "Mohamed", 21 };
Person* ptr = &p1;   // pointer to struct
```

### To access members of struct, we have a 2 methods:

#### 1. Method One: Using `(*ptr).member`:

```cpp
cout << (*ptr).name;  // "Mohamed"
cout << (*ptr).age;   // 21
```

#### 2. Method Two: Using `ptr->member` (Arrow Operator):

```cpp
cout << ptr->name;  // "Mohamed"
cout << ptr->age;   // 21
```

## Pass By Pointer (form of Reference)

You pass the address of a variable to the function. The function can then access and modify the original variable using the pointer.

```cpp
void changeValue(int* ptr) {
  *ptr = 50;  // dereference pointer to change original value
}

int main() {
  int x = 10;
  changeValue(&x);  // pass address of x
  cout << x;        // Output: 50
}
```

## Pass Array to Function By Pointers

We can declare a pointer of the same data type of the array that is function accept as a parameter, and the size of array as the second parameter. And when we have a pointer points to array, the pointer will act like an array.

```cpp
void printArray(int arr[], int size) // Non-Standard Way 1
void printArray(int arr[5]) // Non-Standard Way 2

void printArray(int *arrPtr, int arrLength) // Standard Way
{
  for(int i = 0; i < arrLength; i++)
    cout << arrPtr[i] << "\t";
}

int main ()
{
  int arr[5] = {1, 2, 3, 4, 5};
  printArray(arr, 5);    // 1   2   3   4   5
}
```

Also We can pass 2D array by the same way but using a nested for loop to print all elements of the array.
