# Arrays

Fixed-size collection of data with same Data type stored sequentially in memory (**stack**). Arrays are used to store multiple values from the same type in a single variable, instead of declaring separate variables for each value.

### Declaration

To declare an array, define the variable type, specify the name of the array followed by square brackets and specify the number of elements it should store, also we can insert data inside it in a comma-separated list, inside curly braces:

```cpp
int numbers[4];  // 4 places in memory contains a rubbish values by default
int numbers2[] = {10, 20, 30}; // compiler will set array size to number of elements => 3
int numbers3[5] = {10, 20, 30}; // the rest of elements have value 0
int arr[]; // ❌❌ Compiler Error
```

array itself (numbers) is the address first element of array ALWAYS EVER, it is a constant address value.

```cpp
int myNums[3] = {10, 20, 30};
cout << myNums; // address of the first element in array
cout << myNums[0]; // 10
cout << &myNums[0]; // address of the first element in array
```

### Calculating the size of Array

To get the size of an array, we can use the `sizeof()` operator, this give us the size of hole array not the number elements:

```cpp
int myNumbers[5] = {10, 20, 30, 40, 50};
cout << sizeof(myNumbers);  // 5 elements * 4B = 20B
```

So to find out how many elements an array has, we have to divide the size of the array by the size of any element in the array:

```cpp
int myNumbers[5] = {10, 20, 30, 40, 50};
int getArrayLength = sizeof(myNumbers) / sizeof(myNumbers[0]);
cout << getArrayLength;  // 5
```

We can also use this value in loop condition to loop through the array elements:

```cpp
int myNumbers[5] = {10, 20, 30, 40, 50};
int arrLength = sizeof(myNumbers) / sizeof(myNumbers[0]);
for (int i = 0; i < arrLength; i++) {
  cout << myNumbers[i] << "\t"; // 10  // 20  // 30  // 40  // 50
}
```

### Access the Elements of an Array

We access an array element by referring to the index number inside square brackets `[]`. Array indexes start with 0: `[0]` is the first element. `[1]` is the second element, etc.

```cpp
int numbers[4] = {1, 3, 5, 7};
cout << numbers[0]; // Outputs 1
cout << numbers[1]; // Outputs 3
```

### Change an Array Element

To change the value of a specific element, refer to the index number:

```cpp
int numbers[4] = {1, 3, 5, 7};
numbers[0] = 9;
```

### Loop Through an Array

#### **1- for Loop:**

We can loop through the array elements with the `for` loop.

```cpp
// Create an array of numbers
int numbers[5] = {12, 14, 16, 18, 20};

// Loop through numbers
for (int i = 0; i < 5; i++) {
  cout << numbers[i] << "\t";   //  12   14   16   18   20
}
```

#### **2- foreach Loop:**

It used exclusively to loop through elements in an array.

```cpp
for (type variableName : arrayName) {
  // code block to be executed
}

int myNumbers[5] = {10, 20, 30, 40, 50};

for (int num : myNumbers) {
  cout << num << "\t";   // 10   20   30   40   50
}
```

---

## **Multi-Dimensional Arrays**

A multi-dimensional array is an array of arrays.

### Declaration

To declare a multi-dimensional array, define the variable type, specify the name of the array followed by square brackets which specify how many elements the main array has, followed by another set of square brackets which indicates how many elements the sub-arrays have:

```cpp
char letters[2][4];  // 2 arrays each one contain 4 elements
int arr[][]; // ❌❌ Compile Error
```

We can insert values with an array:

```cpp
char letters[2][4] = {
  { 'A', 'B', 'C', 'D' },
  { 'E', 'F', 'G', 'H' }
};
```

### Access Array Elements

To access an element of a multi-dimensional array, specify an index number in each of the array's dimensions.

```cpp
char letters[2][4] = {
  { 'A', 'B', 'C', 'D' },
  { 'E', 'F', 'G', 'H' }
};
cout << letters[0][2];  // first array, element number 3 => 'C'
```

### Loop Through Arrays

To loop through a multi-dimensional array, you need one loop for each of the array's dimensions.

```cpp
char letters[2][4] = {
  { 'A', 'B', 'C', 'D' },
  { 'E', 'F', 'G', 'H' }
};

for (int i = 0; i < 2; i++) {   // for outer array
  for (int j = 0; j < 4; j++) {   // for inner array elements
    cout << letters[i][j] << "\t";
  }
}
// output => 'A'  'B'  'C'  'D'  'E'  'F'  'G'  'H'
```

## Dynamic Allocation

We can specify the size of array dynamically but this **NOT STANDARD**:

```cpp
  int size;
  cout << "Enter array size: ";
  cin >> size;
  int arr[size];
```

The standard way to dynamically allocate array at runtime is called **Dynamic Allocation**:

Allocate specific value in runtime based on specific size, and deallocate wherever we want, this allocated value stored in **Heap**. We can allocate this value using keyword `new` and deallocate using keyword `delete`.

### Definition

```cpp
int* ptr = new int;   // 4B in heap dynamically allocate memory for one integer
int *arrPtr = new int[5];  // 5 * 4B => 20B in heap dynamically allocate memory for array of 5 integers
```

in this example, we define a pointer of type `int` to point at the first element in dynamically allocated memory of 5 elements of type `int`.

Also we can accept this size from user:

```cpp
int size;
cout << "Enter Size to allocate: ";
cin>> size;
char *cPtr = new char[size];
```

### Access the elements of dynamically allocated memory

We can access dynamically allocated elements by the pointer that is points to this space:

```cpp
*ptr = 10; // single element for first example

for (int i = 0; i < size; i++) // for second example array of characters
{
  cout << "Enter element number " << i + 1 << ": ";
  cin >> cPtr[i];
}
```

Also in arrays we can use another two ways but the previous way is the **best**:

```cpp
for (int i = 0; i < size; i++)
{
  // Way 1 No Problem with this way => move based on the pointer location but not change the pointer value
  cout << *(cPtr + i) << "\t";

  // Way 2 : change the pointer value itself (NOT RECOMMENDED)
  cout << *cPtr << "\t";
  cPtr++;
}
```

### Free Allocated Memory

After finishing the use of this data, We need to free the allocated memory to prevent **memory leaks** using `delete` keyword. Because this place will be protected in heap and any part of program can't access it until remove this protection.

```cpp
delete ptr;       // free memory for single element
delete[] cPtr;    // free memory for collection of elements (arrays)
```

### Dynamic Allocation for Array of pointers:

An **array of pointers** means each element of the array is a **pointer**.

```cpp
int ** ptrArr;
ptrArr = new int*[3];

ptrArr[0] = new int[4];
ptrArr[1] = new int[4];
ptrArr[2] = new int[4];

// now ptrArr => is a 2d array ptrArr[3][4] and we can access it with this way

delete[] ptrArr[0];
delete[] ptrArr[1];
delete[] ptrArr[2];
delete[] ptrArr;
```

### Pointer to dynamic allocation for struct:

```cpp
struct Employee
{
  int id;
  char name[12];
  int age;
};

int main()
{
  int empSize=3;
  Employee * empPtr= new Employee[empSize];
  // Employee * empPtr ==new== Employee empPtr[3]

  empPtr[0].id = 10;
  strcpy(empPtr[0].name, "Mohamed");
  empPtr[0].age = 24;
}
```
