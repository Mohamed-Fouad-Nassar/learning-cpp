# Operators

Operators are used to perform operations on variables and values.

C++ divides the operators into the following groups:

## 1. Arithmetic Operators

Arithmetic operators are used to perform common mathematical operations.

1. `+` (Addition) => Adds together two values.
2. `-` (Subtraction) => Subtracts one value from another.
3. `*` (Multiplication) => Multiplies two values.
4. `/` (Division) => Divides one value by another.
5. `%` (Modulus) => Returns the division remainder.
6. `++` (Increment) [Unary Operator] => Increases the value of a variable by 1.
7. `--` (Decrement) [Unary Operator] => Decreases the value of a variable by 1.

**NOTE:** When dividing two integers in C++, the result will also be an integer. For example, `10` / `3` gives `3`. If you want a decimal result, use `float` or `double` values, like `10.0` / `3` gives `3.33...`.

```cpp
int x = 10;
int y = 3;
cout << (x / y) << "\n";   // Integer division, result is 3

double a = 10.0;
double b = 3.0;
cout << (a / b) << "\n";   // Decimal division, result is 3.333...
```

### Incrementing and Decrementing:

Incrementing and decrementing are very common in programming, especially when working with counters, loops, and arrays (which you will learn more about in later chapters).

The `++` operator increases a value by `1`, while the `--` operator decreases a value by `1`:

```cpp
int x = 5;

cout << ++x << "\n"; // PREFIX-increment (increase, then print) => 6
cout << --x << "\n"; // PREFIX-decrement (decrease, then print)=> 5

cout << x++ << "\n"; // POSTFIX-increment (print, then increase) => 5
cout << x-- << "\n"; // POSTFIX-decrement (print, then decrease) => 5
```

## 2. Assignment Operators

Assignment operators are used to assign values to variables.

1. (`=`) => assign operator `int x = 10;`.
2. (`+=`) => add and assign operator `x += 10` as same as `x = x + 10`.
3. (`-=`) => subtract and assign operator `x -= 10` as same as `x = x - 10`.
4. (`*=`) => multiple and assign operator `x *= 10` as same as `x = x * 10`.
5. (`/=`) => division and assign operator `x /= 10` as same as `x = x / 10`.
6. (`%=`) => modulus and assign operator `x %= 10` as same as `x = x % 10`.

```cpp
int x = 10;
cout << x << endl; // 10

x += 10;
cout << x << endl; // 20

x -= 5;
cout << x << endl; // 15

x *= 2;
cout << x << endl; // 30

x /= 5;
cout << x << endl; // 6

x %= 3;
cout << x << endl; // 0
```

Compound operators (like: `+=`, `-=`, ...etc) make code shorter and easier to read, especially when updating the same variable many times.

## 3. Comparison Operators

Comparison operators are used to compare two values (or variables). This is important in programming, because it helps us to find answers and make decisions. The return value of a comparison is either `1` or `0`, which means `true` (1) or `false` (0). These values are known as Boolean values.

1. `==` (equal to) => return `true` if left side equals right side.
2. `<=` (less than or equal) => return `true` if left side less than or equals right side.
3. `>=` (greater than or equal) => return `true` if left side greater than or equals right side.
4. `!=` (not equal) => return `true` if left side not equals right side
5. `<` (less than) => return `true` if left side less than right side.
6. `>` (greater than) => return `true` if left side greater than right side.

```cpp
int age = 18;

cout << (age >= 18) << "\n"; // 1 (true), old enough to vote
cout << (age < 18) << "\n";  // 0 (false), not old enough
```

## 4. Logical Operators

As with comparison operators, you can also test for `true` (1) or `false` (0) values with logical operators. Logical operators are used to determine the logic between variables or values:

1. `&&` (Logical and) => returns `true` if both statements are `true`.
2. `||` (Logical or) => returns `true` if at least one of both statements is `true`.
3. `!` (Logical not) => reverse the result, returns `false` if the result is `true`.

```cpp
int a = 10, b = 20;

cout << (a > 5 && b > 15) << endl;    // true
cout << (a > 15 || b > 15) << endl;   // true
cout << !(a > 5) << endl;             // false
```

---

# Operator Precedence

When a calculation contains more than one operator, C++ follows order of operations rules to decide which part to calculate first. Here are some common operators in C++, from highest to lowest priority:

1. `()` - Parentheses
2. `*`, `/`, `%` - Multiplication, Division, Modulus
3. `+`, `-` - Addition, Subtraction
4. `>`, `<`, `>=`, `<=` - Comparison
5. `==`, `!=` - Equality
6. `&&` - Logical AND
7. `||` - Logical OR
8. `=` - Assignment
