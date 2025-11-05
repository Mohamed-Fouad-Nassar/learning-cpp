# Loops

Loops let your program repeat actions automatically, saving time and avoiding repetition in your code. It is a control structure that repeats a block of code as long as a certain condition is true.

## 1. **`for` Statement**

```cpp
for (initialization; condition; update) {
    // code to execute
}
```

- initialization, executed one time before the execution of the code block.
- condition, for executing the code block.
- update, executed every time after the code block has been executed.

```cpp
for (int i = 0; i < 5; i++) {
  cout << i << "\t";    // 0    1    2    3    4
}
```

### Nested Loops

It is also possible to place a loop inside another loop. This is called a nested loop. The "inner loop" will be executed one time for each iteration of the "outer loop":

```cpp
// Outer loop
for (int i = 1; i <= 2; ++i) {
  cout << "Outer: " << i << "\n"; // Executes 2 times

  // Inner loop
  for (int j = 1; j <= 3; ++j) {
    cout << " Inner: " << j << "\n"; // Executes 6 times (2 * 3)
  }
}
```

Nested loops are useful when working with tables, matrices, or multi-dimensional data structures.

---

## 2. **`foreach` Statement**

There is also a "for-each loop" (also known as ranged-based for loop), which is used to loop through elements in an array (or other data structures):

```cpp
for (type variableName : arrayName) {
  // code block to be executed
}

// Example
int myNumbers[5] = {10, 20, 30, 40, 50};
for (int num : myNumbers) {
  cout << num << "\t";     // 10    20    30    40    50
}
```

---

## 3. **`while` Statement**

The while loop loops through a block of code as long as a specified condition is `true`:

```cpp
while (condition) {
  // code block to be executed
}

// Example
int i = 0;
while (i < 5) {
  cout << i << "\t";     // 0    1    2    3    4
  i++; // if we forget this, we will fall through an infinite loop.
}
```

---

## 4. **`do...while` Statement**

The `do...while` loop is a variant of the `while` loop. This loop **will execute the code block once, before checking if the condition is `true`**. Then it will repeat the loop as long as the condition is `true`.

```cpp
do {
  // code block to be executed
}
while (condition);

// Example
int i = 0;
do {
  cout << i << "\t";     // 0    1    2    3    4
  i++;
}
while (i < 5);
```

The semicolon `;` after the while condition is **required**!

---

## **Break and Continue in loops and conditions:**

- We can use `break;` statement to jump out of a loop under a certain condition:

  ```cpp
  for (int i = 0; i < 10; i++) {
    if (i == 4) {
      break;
    }
    cout << i << "\n";    // 0   1   2   3    the loops stopped when i = 4
  }
  ```

- We can use `continue` statement to **Break** or **Skip** one iteration (in the loop), if a specified condition occurs, and continues with the next iteration in the loop.

  ```cpp
  for (int i = 0; i < 10; i++) {
    if (i == 4) {
      continue;
    }
    cout << i << "\n";    // 0   1   2   3   5   6   7   8   9   (skip i = 4)
  }
  ```
