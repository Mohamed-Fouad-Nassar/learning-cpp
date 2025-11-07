# Functions

Functions are blocks of code which only runs when called, we can pass **data**, known as **parameters**, into a function. Functions are used to perform certain actions, and they are important for reusing code: Define the code once, and use it many times.

## Creating Function

C++ provides some pre-defined functions, such as `main()`, which is used to execute code (also called an **Entry Point** where the app starts). But we can also create our own functions to perform certain actions:

```cpp
void myFunction()  // declaration
{
  // code to be executed  // definition
}
```

- `void` => is a return type of this function (in this situation no return value).
- `myFunction` => is a name of this function.
- `{ ... }` => inside `{}` is the **body** of the function where code that defines what the function should do.

A C++ function consist of two parts:

- **Declaration**: the return type, the name of the function, and parameters (if any)
- **Definition**: the body of the function (code to be executed)

If we define the function after `main()` function and try to use it inside the `main()` function, this will give error. So we can separate the declaration and the definition of the function - for code optimization and also solve the previous error.

```cpp
void myFunction();  // Function declaration

int main()
{
  myFunction();  // call the function
  return 0;
}

// Function definition
void myFunction()
{
  cout << "I just got executed!";
}
```

## Calling Function

Declared functions are not executed immediately. They are "saved for later use", and will be executed later, when they are called. To call a function, write the `function's name` followed by `two parentheses ()` and a `semicolon ;`. Also we can call the function multiple times.

```cpp
int main()
{
  myFunction();   // calling the previous function
  return 0;
}
```

## Function with Parameters

Information can be passed to functions as a parameter. Parameters act as variables inside the function. Parameters are specified after the `function name`, inside `the parentheses ()`. You can add as many parameters as you want, just separate them with a `comma ,`.

```cpp
void functionName(data_type param_name, data_type param_name)
{
  // code to be executed
}

void myFunction(string fName)
{
  cout << fName << " Refsnes\n";
}
```

When a **parameter** is passed to the function, it is called an **argument**. when we working with **multiple parameters**, the function call must have the same number of arguments as there are parameters, and the arguments must be passed in the same order and same data types.

We can also use a default parameter value, by using the equals sign (`=`), this value will used if the user don't provide the argument to the function (also it make the **argument optional** called **optional parameter**).

```cpp
void myFunction(string country = "Norway")
{
  cout << country << "\n";
}

int main()
{
  myFunction();   // Norway
  myFunction("Egypt");   // Egypt
  return 0;
}
```

## Function Return Value

The `void` keyword indicates that the function should **not return a value**. If you want the function to return a value, you can use a **data type** (such as `int`, `string`, etc.) instead of `void`, and use the `return` keyword inside the function:

```cpp
int myFunction(int x)
{
  return 5 + x;
}

int main()
{
  cout << myFunction(3);  // Outputs 8 (5 + 3)

  // also we can store the value returned in a variable from the same type:
  int result = myFunction(5);
  cout << result;  // Outputs 10 (5 + 5)

  return 0;
}
```

## Pass Parameters By Reference

When we used normal variables to pass parameters to a function this called **Pass by Value**, we can also pass a **reference** to the function by using `&` before parameter name. This can be useful when you need to change the value of the argument itself:

```cpp
void swapByValue(int &num1, int &num2)
{
  int temp = num1;
  num2 = num1;
  num1 = temp;
}

void swapByReference(int num1, int num2)
{
  int temp = num1;
  num2 = num1;
  num1 = temp;
}

int main()
{
  int x = 10, y = 20;

  swapByValue(x, y); // the actual values will not change only the values inside the function body changed.
  cout << x << y; // 10   20

  swapByReference(x, y); // the actual values will change
  cout << x << y; // 20   10
  return 0;
}
```

## Pass Structure to a Function

We can also pass a structure to a function. This is useful when you want to work with grouped data inside a function or when we need to pass an object from class to this function:

```cpp
struct Car
{
  string brand;
  int year;
};

void myFunction(Car c)
{
  cout << "Brand: " << c.brand << ", Year: " << c.year << "\n";
}

int main()
{
  Car myCar = {"Toyota", 2020};   // "Brand: Toyota, Year: 2020"
  myFunction(myCar);
  return 0;
}
```

Since the structure is passed by value, the function gets a copy of the structure. This means that the original data is not changed. If We need to change the original object data, we can use **pass by reference** instead.

```cpp
void updateYear(Car& c)
{
  // code ...
}
```

## Function Overloading and Overriding

### **1- Function overloading:**

Function overloading allows multiple functions to have the **same name**, as long as their parameters are different in **type** or **number**, This lets you use the same function name for similar tasks.

```cpp
int myFunction(int x)
float myFunction(float x)
double myFunction(double x, double y)
```

Real example of function overloading:

```cpp
int sum(int x, int y)
{
  return x + y;
}

double sum(double x, double y)
{
  return x + y;
}

int sum(int  x, int y, int z)
{
  return x + y + z;
}

float sum(float  x, float y, float z)
{
  return x + y + z;
}

int main()
{
  cout << sum(10, 14);  // 24
  cout << sum(10, 20, 30);  // 60
  cout << sum(10.50, 20.75);  // 31.25
  cout << sum(10.50f, 20.75f);  // 31.25

  return 0;
}
```

### **2- Function Overriding:**

In **OOP** (inheritance, and polymorphism), Function overriding means a derived (child) class redefines a base (parent) class function that has the same **name**, **return type**, and **parameters** that is called **Function Signatures**.

The base class function should usually be declared as `virtual`.

```cpp
class Animal {
public:
  virtual void sound() {  // virtual allows overriding
    cout << "Animal makes a sound" << endl;
  }
};

class Dog : public Animal {
public:
  void sound() override {  // override is optional but recommended
    cout << "Dog barks" << endl;
  }
};

int main() {
  Animal a;
  a.sound();  // "Animal makes a sound"

  Dog d;
  d.sound();  // "Dog barks"
}
```

## Function Prototype

A function prototype is a declaration of a function that tells the compiler: function name, parameters (number, and types), and return type.

```cpp
int sum(int, int);  // we can add parameters names or not
```

We use it when we need to define functions after `main` function and use them inside `main`.

```cpp
int sum(int, int);

int main()
{
  add(10, 20); // ❌❌ Compiler Error: add not defined
  sum(10, 20); // 30
  return 0;
}

int add(int x, int y)
{
  return x + y;
}

int sum(int x, int y)
{
  return x + y;
}
```
