# C++ BASICS

## Syntax

```cpp
#include <iostream>
using namespace std;

int main() {
cout << "Hello World!";
return 0;
}
```

`#include <iostream>` is a **header file library** that lets us work with input and output objects, such as `cout` (used in line 5). Header files add functionality to C++ programs.

`using namespace std` means that we can use names for objects and variables from the standard library.

`int main()` called a **function** (also in C++ programs called **Entry Point** where the program start execute from it). Any code inside its curly brackets `{}` will be executed, `int` type of value returned by this function so we `return 0;` in the end of the program, and `main` is the name of this function.

Every C++ statement ends with a semicolon `;`, and also C++ is case-sensitive language, ex: `cout` not `Cout`, and keywords in C++ is lower case.

## Spaces and lines in C++ (**Escape Sequence**)

In strings that statements between `""`, we can add this characters to add spaces or lines:

- `\n` creates a new line in output. also we can use `endl` rather than `\n`.
- `\t` creates a horizontal tab
- `\"` Inserts a double quote character
- `\\` Inserts a backslash character (\\)

## Comments

`//` Single-line comments start with two forward slashes, any text after them until the end of line will ignored by the compiler (will not executed).

`/*  */` Multi-line comments start with `/*` and ends with `*/`, any text between them will ignored by the compiler (will not executed).

```cpp
// single line comment
cout << "Hello World!"; // another single line comment

/*
  multi-line comments
  1- comment one
  2- comment two
*/
cout << "Hello World!";
```

## Output (Print data in console)

`cout` (pronounced "see-out") is an object used together with the insertion operator (`<<`) to output/print **text** with `""` surround it, **single character** with `''`, and **number** without them.

```cpp
cout << "Hello World!";
cout << 'q';
cout << 10;
cout << 2 + 10;
```

## Input

`cin` is an object used together with the insertion operator (`>>`) to get the user input from keyboard (the value must be a printed value).

```cpp
int x;
cout << "Type a number: "; // Type a number and press enter
cin >> x; // Get user input from the keyboard
cout << "Your number is: " << x; // Display the input value
```

We can use a functions from <conio.h> to get inputs from user:

- `getch()` used as `cin >>` to get any printed value from user.
- `getche()` used to get any printed or non printed value from user. (No need to click enter after it).

## #define preprocessor

It used to create macro data before compile time, used to create constant values or expression[macro] under specific name and we can use it whatever we want.

```cpp
#include<iostream>
#define SIZE 5
#define SIZE_2 3];
using namespace std;

int main()
{
  int arr1[SIZE]; // same => int arr1[5];
  int arr2[SIZE_2 // same => int arr2[3];

  return 0;
}
```

## Casting

Convert value from data type to another data type. Latest C, and C++ Versions, this will be done Implicitly (compiler will do it itself).

### Types of casting:

1. **Implicit Casting (Automatic Type Conversion):**

   The compiler automatically converts one data type to another when it’s safe to do so.

   ```cpp
   int a = 10;
   double b = a;  // implicit conversion (int → double)
   ```

   **RULES:**

   - Smaller → larger type (e.g., `int` → `float`, `float` → `double`)
   - No data loss (ideally)
   - Happens without explicit syntax

2. **Explicit Casting (Manual Conversion):**

   We explicitly tell the compiler to convert one type to another using casting syntax.

   ```cpp
   double result = (double)5 / 2;  // 2.5
   ```

   Without the cast, `5 / 2` would perform integer division and result in `2`.

## Namespaces in c++

`namespace` is a logically grouping for one or more datatype with specific name to achieve performance and identity. for example `std` namespace in C++ contains functions like `cin`, `cout`, `endl`, ...etc.

We can include the namespace by `std::cout` in each time we need to access one of the namespace functions or `using namespace std;` in the top of c++ file.

```cpp
#include<iostream>
using namespace std;  // first way and recommended
int main()
{
  int age;
  std::cout<<"enter age"<<std::endl; // second way
  cin>>age;
  cout<<"age="<<age<<endl;
  return 0;
}
```

Also we can create our `namespace` as the following:

```cpp
namespace BookRead
{
  struct Book
  {
    isbn;
    authorName;
  };
}

namespace BookTicket
{
  struct Book
  {
    ticketNo;
    passengerName;
  };
}

using namespace BookTicket;

int main()
{
  BookRead::Book br1; // br1 => isbn, authorName
  Book br2; // br2 => ticketNo, passengerName
}
```

## References in C++

Alias name for another variable in memory. It does not create a new variable in memory — it only gives a new label to the same memory location.

```cpp
int x = 10;
int& y = x;   // y is a reference (alias) to x

cout << &x; // ex: 0x20
cout << &y; // the same as &x => 0x20
```

Both `x` and `y` refer to the same address → same memory location.

We must initialize a reference when you declare it — otherwise, it’s a compile-time error:

```cpp
int& z; // Compiler error => reference must be initialized
```

Pass by reference is the best way to access the value of variable when we need to change the actual value of variable using functions for example.

```cpp
void SwapV(int x ,int y) // pass by value
{
    int tmp = x;
    x = y;
    y = tmp;
}

void SwapA(int* x ,int* y) // pass pointer to value
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void SwapR(int& x ,int& y) // pass by reference
{
    int tmp = x;
    x = y;
    y = tmp;
}

int main()
{
    int a = 10, b = 20;
    SwapV(a, b);   // the values not change
    SwapA(&a, &b);   // values will swapped
    SwapR(a, b);   // values will swapped
    return 0;
}
```

## Access Modifiers

Access modifiers define who can access the members (variables or functions) of a class or struct. They help you encapsulate data — protecting it from unwanted access or modification.

1. **Private**:
   Access variables and function inside a class/struct ONLY.

2. **Protected**:
   Like Private but access by child classes used with inheritance.

3. **Public**:
   Access variables and functions inside and outside class/struct.
