#include <iostream>
using namespace std;

int main()
{
  char choice;

  do
  {
    char op;
    cout << "Enter operator (+, -, *, /, %): ";
    cin >> op;

    int num1, num2;
    cout << "Enter two operands: ";
    cin >> num1 >> num2;

    while (op == '/' && num2 == 0)
    {
      cout << "Enter divisor (non-zero): ";
      cin >> num2;
    }

    switch (op)
    {
    case '+':
      cout << "Result: " << (num1 + num2) << endl;
      break;
    case '-':
      cout << "Result: " << (num1 - num2) << endl;
      break;
    case '*':
      cout << "Result: " << (num1 * num2) << endl;
      break;
    case '/':
      cout << "Result: " << (num1 / num2) << endl;
      break;
    case '%':
      cout << "Result: " << (num1 % num2) << endl;
      break;
    default:
      cout << "Error: Invalid operator!" << endl;
      break;
    }

    cout << "Do you want to perform another calculation? (y/n): ";
    cin >> choice;
  } while (choice == 'y' || choice == 'Y');

  return 0;
}