# Conditions

Also called decision-making statements, They let your program make choices based on whether something is `true` or `false`.

## **`if`, `if...else`, and `if...else if...else` Statements**

### 1. **`if`** statement:

Executes a block only if the **condition** is `true`.

`if` condition with check specific value is not recommended, use `switch` instead.

```cpp
if (condition)
{
  // some code to execute if condition is true...
}

// Example
if (20 > 18) {
  cout << "20 is greater than 18"; // "20 is greater than 18"
}
```

### 2. **`else`** statement:

We use the else statement to specify a block of code to be executed if the **condition** is `false`.

```cpp
if (condition) {
  // block of code to be executed if the condition is true
} else {
  // block of code to be executed if the condition is false
}

// Example
int time = 20;
if (time < 18) {
  cout << "Good day.";
} else {
  cout << "Good evening.";
}
// Outputs "Good evening."
```

### 3. **`else if`** statement:

We use the `else if` statement to specify a new **condition** if the first **condition** is `false`.

```cpp
if (condition1) {
  // block of code to be executed if the condition1 is true
} else if (condition2) {
  // block of code to be executed if the condition1 is false, and condition2 is true
} else {
  // block of code to be executed if condition1, and condition2 are false
}

// Example
int time = 22;
if (time < 10) {
  cout << "Good morning.";
} else if (time < 20) {
  cout << "Good day.";
} else {
  cout << "Good evening.";
}
// Outputs "Good evening."
```

### 4. Nested `if` statement:

We can also place an `if` statement inside another `if`. This is called a nested `if` statement. A nested `if` lets you check for a condition only if another condition is already true.

```cpp
if (condition1) {
  // code to run if condition1 is true
  if (condition2) {
    // code to run if both condition1 and condition2 are true
  }
}
```

### 5. Short-Hand `if...else` statement (**Ternary Operator**):

The ternary operator returns a value based on a condition: if the condition is `true`, it returns the first value; otherwise, it returns the second value. It can be used to replace multiple lines of code with a single line, and is often used to replace simple `if...else` statements:

```cpp
variable = (condition) ? expressionTrue : expressionFalse;

// Example
int time = 20;

// if statement
if (time < 18) {
  cout << "Good day.";
} else {
  cout << "Good evening.";
}

// ternary operator
string result = (time < 18) ? "Good day." : "Good evening.";
cout << result; // "Good evening."

// We can also use the ternary operator directly inside the cout statement:
cout << ((time < 18) ? "Good day." : "Good evening.");
```

---

## **`Switch` Statements**

We use the `switch` statement to select one of many code blocks to be executed.

- The `switch` expression is evaluated once.
- The value of the expression is compared with the values of each `case`.
- If there is a match, the associated block of code is executed.
- `switch` is available with int, char **ONLY**,

```cpp
switch(expression) {
  case x:
    // code block
    break;
  case y:
    // code block
    break;
  default:
    // code block
}
```

- The `break` and `default` keywords are optional.

- `break` keyword breaks out of the switch block, also stop the execution of more code and case testing inside the block, forget `break` will cause a **fall through** another case if this case not the last one.

- `default` keyword used to specify some code to run if there is no case match.
