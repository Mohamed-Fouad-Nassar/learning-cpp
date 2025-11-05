# Data Types

As explained in the **Variables** chapter, a variable in C++ must be a specified **data type**, in C++ we have many data types:

## Numeric Types

### 1. **`int`** :

We use `int` when you need to store a whole number **without decimals**, like 35 or 1000.

`int` has size of `2` or `4` bytes.

```cpp
int num = 20;
```

#### C++ provides several modifiers to control the range and memory use of integers:

1. **`short` or `short int`**:
   Same of `int` but with less range, and also less size only `2` bytes.

2. **`long` or `long int`**:
   Same of `int` but with more range, and also more size only `4` or `8` bytes.

3. **unsigned**:
   Put it before any modifier of int to remove all negative values, and duplicate the positive range.

### 2. **`float`**:

We use `float` when you need a **floating point number** (with decimals), like 9.99 or 3.14515.

`float` has size of `4` bytes, Stores fractional numbers, containing one or more decimals. Sufficient for storing 6-7 decimal digits.

```cpp
float num = 5.75;
```

### 3. **`double`**:

We can also use `double` when you need a **floating point number** (with decimals), like 9.99 or 3.14515.

`double` has size of `8` bytes, Stores fractional numbers, containing one or more decimals. Sufficient for storing 15 decimal digits.

```cpp
double num = 5.75;
```

#### **`float`** vs. **`double`**:

The **precision** of a floating point value indicates how many digits the value can have after the decimal point. The **precision** of `float` is only six or seven decimal digits, while `double` variables have a precision of about 15 digits. Therefore it is safer to use `double` for most calculations.

### 4. **`long double`**:

Same as `double`, but with more size `12` or `16` bytes. also more range 18–19 decimal digits.

---

## Boolean Types

A boolean data type is declared with the `bool` keyword and can only take the values `true` or `false`., and when the value is returned, `true` = `1` and `false` = `0`.

`bool` has size of `1` byte.

```cpp
bool isTrue = true;
bool isFalse = false;
cout << isCodingFun;  // Outputs 1 (returned value of true)
cout << isFishTasty;  // Outputs 0 (returned value of false)
```

---

## Character Types

The `char` data type is used to store a single character. The character must be surrounded by single quotes, like 'A' or 'c':

`char` has size of `1` bytes\.

```cpp
char myGrade = 'B';
```

This characters translated into numbers according to [ASCII Table ↗](https://www.ascii-code.com/).

---

## String Types

The `string` type is used to store a sequence of characters (text). This is **NOT** a built-in type, but it behaves like one in its most basic usage. String values must be surrounded by double quotes `""`.

To use strings, you must include an additional header file in the source code, the <string> library:

```cpp
#include <string> // Include the string library in the top file

int main () {
  string greeting = "Hello";
}
```

If we need to use the basic concept of strings without any string libraries we can create a string with array of characters that ends with a null character (`'\0'`) that is called **null terminator**:

```cpp
char fName[10] = {'A', 'h', 'm', 'e', 'd', '\0'};
char lName[10] = "Nassar";
```

### string.h library

- `gets(array of characters)` Reads an entire line (including spaces) from standard input into a character array until Enter (`\n`) is pressed.

- `puts(array of characters)` Prints a character array (string) to standard output followed by a newline (`\n`).

  `strcpy(Larrayofcharacters, Rarrayofcharacters)` Copies the content of the right array (Rarrayofcharacters) into the left array (Larrayofcharacters), including the null terminator '`\0`'.

- `strcat(Larrayofcharacters,Rarrayofcharacters)` Appends the content of the right array to the end of the left array. The left array must have enough space for both strings.

- `strcmp(Larrayofcharacters,Rarrayofcharacters)` Compares two strings case-sensitively using ASCII values.
  Returns:

  - `0` → strings are equal
  - `<0` → left < right
  - `>0` → left > right

- `strcmpi(Larrayofcharacters,Rarrayofcharacters)` Compares two strings case-insensitively (ignores uppercase/lowercase differences).

- `strlen(Larrayofcharacters)` Returns the length of the string (number of characters before the `'\0'` terminator).

- `atoi(Larrayofcharacters)` Converts a numeric string (e.g. `"123"`) to an `int`.

- `atof(Larrayofcharacters)` Converts a numeric string with decimals (e.g. `"12.34"`) to a `double`.

## Automatic detection by C++ compiler

The `auto` keyword automatically detects the type of a variable based on the value you assign to it. It helps you write cleaner code and avoid repeating types, especially for long or complex types.

`auto` only works when you assign a value at the same time (You can't declare `auto x;` without assigning a value)

Once the type is chosen, it stays the same.

```cpp
auto x = 5; // x is automatically treated as int
auto y = 5.99f; // y is automatically treated as float
auto z = 9.98; // z is automatically treated as double

x = 9.98 // ❌❌ Error => can't assign a double to an int
```

---

## Struct in C++

Structs (also called Structures) are a way to group several related variables into one place. Each variable in the structure is known as a member of the structure. Structure can contain many different data types: int, string, bool, etc, and declared in global scope.

### Definition

We use the `struct` keyword then structure name, and declare each of its members inside curly braces `{}`.

```cpp
struct MyStructure{ // Structure declaration and Structure variable
  int myNum;        // Member (int variable)
  string myString;  // Member (string variable)
};
```

- First letter must be uppercase, beside it must be singular.
- Data inside => First Letter must be lowercase or start with underscore `_`.
- We can calculate the size of struct by adding the sizes of all members.

### Access Structure Members

To access members of a structure, use the dot syntax (`.`):

```cpp
// Create a structure variable called MyStructure
struct MyStructure {
  int myNum;
  string myString;
};

// Assign values to members of MyStructure
MyStructure.myNum = 1;
MyStructure.myString = "Hello World!";

// Print members of MyStructure
cout << MyStructure.myNum << "\n";  // 1
cout << MyStructure.myString << "\n";  // "Hello World!"
```
