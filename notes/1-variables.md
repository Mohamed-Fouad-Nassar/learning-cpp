# Variables

Variables are containers for storing data values, there are different types of variables (defined with different keywords) **_will talk about them later_**

## Declaring (Creating) Variables:

To create a variable, specify the type and assign it a value:

```cpp
data_type variable_name = value;
```

For example o create a variable that should store a number use data type called `int`, named `number` with value `12`:

```cpp
int number = 12;
```

We can also declare a variable without assigning the value, and assign the value later:

```cpp
int number;
number = 12;
```

Also we can change this value later but without declaring the variable again:

```cpp
int number = 12;
number = 15; // now number has the value of 15 not 12
```

We can also declare multiple variables from the same type by the same two ways separated by `,`:

```cpp
int num1 = 12, num2, num3 = 15;
num2 = 13;
```

We can also declare some variable with the same value:

```cpp
int num1, num2, num3;
num1 = num2 = num3 = 10;
// OR
int num1 = num2 = num3 = 10
```

## Identifiers Rules:

Variables must be identified with **unique** names. Identifiers can be **short names** (like x and y) or **more descriptive names** (age, sum, totalVolume).

1. Names can contain letters, digits and underscores
2. Names must begin with a letter or an underscore (\_)
3. Names are case-sensitive (myVar and myvar are different variables)
4. Names cannot contain whitespaces or special characters like !, #, %, etc.
5. Reserved words (like C++ keywords, such as int) cannot be used as names

It is recommended to use descriptive names in order to create understandable and maintainable code

## Constants:

When we do not want others (or ourselves) to change existing variable values, use the `const` keyword (this will declare the variable as "constant", which means unchangeable and read-only):

```cpp
const int myNum = 15;  // myNum will always be 15
myNum = 10;  // error: assignment of read-only variable myNum
```

Also can define a constant value using `#define` keyword in the top of C++ file.

```cpp
#define constantNameInUpperCase value
```

In this situation, we **must** assign the value to the constant in the declaration line because we **will not able to** access this value to change it later.

## Variables Scope:

Variables are only accessible inside the region they are created. This is called scope.

1. **Local Scope:**
   A variable created inside a (function or block-scope like loop or condition) belongs to the local scope of that (function or block-scope), and can only be used inside that (function or block-scope):

```cpp
Example
void myFunction() {
  // Local variable that belongs to myFunction
  int x = 5;
  cout << x;
}

int main() {
  myFunction();
  cout << x; // ❌❌ Error undefined variable x
  return 0;
}
```

A local variable stored in **Stack**, and cannot be used outside the (function or block-scope) it belongs to. so, if we want to access it outside this will throw an error, and the Life time of it ended at the end of this scope.

2. **Global Scope:**
   A variable created outside of any (function or block-scope), is called a global variable and belongs to the global scope.
   Global variables stored in **Data Segment (BSS)** and it are available from within any scope, global and local, and the Life time of it ended at the end of program:

```cpp
// Global variable x
int x = 5;

void myFunction() {
  cout << x << "\n"; // ✔️✔️ value of x: 5
}

int main() {
  myFunction();
  cout << x; // ✔️✔️ value of x: 5
  return 0;
}
```

3. **Static Variables:**
   A variable declared once, and only once in memory regardless how many time of calling the function. and always declared with default value ex: (`int` ==> `0`), stored at **Data Segment (BSS)**, and the Life time of it ended at the end of program, it also a local variable with keyword `static` before it:

```cpp
void myFunction()
{
  static int x;  // Executed once at the first call of the function with default value 0
  x++; // 1
  cout << x << endl;
}

int main()
{
  myFunction();  // 1
  myFunction();  // 2
}
```

## Naming Variables

If we operate with the same variable name inside and outside of a function, C++ will treat them as two separate variables. One available in the global scope (outside the function) and one available in the local scope (inside the function):

```cpp
// Global variable x
int x = 5;

void myFunction() {
  // Local variable with the same name as the global variable (x)
  int x = 22;
  cout << x << "\n"; // 22 => Refers to the local variable x
}

int main() {
  myFunction();

  cout << x; // 5 => Refers to the global variable x
  return 0;
}
```

However, we should avoid using the same variable name for both globally and locally variables as it can lead to errors and confusion. Also we should be careful with global variables, since they can be accessed and modified from any function.

## Access the address of variable in memory:

We can access the address of the variable in memory by `&` operator:

```cpp
char ch = 'M';
cout << "value of x is " << x << endl;
cout << "address of x is " << &x;
```

This value is a constant and read-only, created by the operating system (OS).
