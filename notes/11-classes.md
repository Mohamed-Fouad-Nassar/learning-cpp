# Classes

`class` is most like `struct`, both contains:

- data members (variables)
- member functions (methods)
- constructors, and destructors
- inheritance
- access specifiers (public, private, protected)

The only real difference is the default access level:

- class => private
- struct => public

## Definition

We use `class` keyword after it, the class name and must be uppercase first letter then curly braces `{}` and semicolon `;`, inside curly braces we define all Properties (Attributes) and methods:

```cpp
class ClassName
{
  // properties
  // methods
};

class Car
{
  public:   // access modifier
    int modelNum, price;   // attributes
    string plateNum, color;   // attributes

    void printInfo() // method, we can also define a method with parameters.
    {
      cout << "The car with plate number: " << plateNum << ", and model number: " << modelNum << ", with color: " << color << "selling at: " << price << endl;
    }
};

int main()
{
  Car c1;   // creating object from class Car
  c1.modelNum = 1289324;
  c1.color = "red";
  c1.printInfo();
  return 0;
}
```

## Constructor

A constructor is a **special method** that is automatically called when an object of a class is created. To create a constructor, use the same name as the class, followed by parentheses `()`:

```cpp
class Car
{
  public:
    Car()
    {
      cout << "Object created successfully!";
    }
}
```

This default constructor will generated gy operating system (OS), if there is no such constructor exists.

**Rules od writing constructor explicitly**:

- has same name of class
- has no return type nor void
- can be overloaded
- must be public ->private[design patterns] (can't define object from it outside the class itself)

We can also define a constructor with parameters that is called **Constructor Overloading**, this parameters send with object creation from this class in `()`:

```cpp
class Car
{
  public:
    int modelNum, price;
    string plateNum, color;

    Car(string _plateNum, int _price)
    {
      price = _price;
      plateNum = _plateNum;
      cout << "Object with parameters created successfully!";
    }
}

int main()
{
  Car c1("29300234", 200000);   // creating object from class Car
  return 0;
}
```

This parameters can be useful for setting initial values for attributes.

**Advantage of Using Constructor overloading**:

- To give flexibility when creating objects
- To set default or custom values
- To reduce repetitive code

## Friend Function

A friend function is not a member of the class, but it is allowed to access the class's private data:

```cpp
class Employee {
  private:
    int salary;

  public:
    Employee(int s) {
      salary = s;
    }

    // Declare friend function
    friend void displaySalary(Employee emp);
};

void displaySalary(Employee emp) {
  cout << "Salary: " << emp.salary;
}

int main() {
  Employee myEmp(50000);
  displaySalary(myEmp);
  return 0;
}
```

## Destructor

A destructor is a **special member function** in a class that is automatically called when an object is destroyed — that is, when it goes out of scope or is deleted. It’s mainly used to:

- Clean up before the object is removed from memory
- Release resources (like memory, files, database, or network connections)

**Rules od writing constructor explicitly**:

- has same name of class but starts with `~`
- has no return type nor void
- cannot be overloaded (only no parameters copy)
- must be public

```cpp
class Car
{
  public:
    ~Car()
    {
      cout << "Object removed successfully!";
    }
}
```

## Real Life Example of class:

```cpp
class User
{
  // private attributes
  int id, salary;
  string username, password;

  // public methods
  public:
    User() // default constructor
    {
      cout << "Default User Constructor";
    }
    User(int _id, string _u, string _p)  // constructor overloading with 3 parameters
    {
      id = _id;
      username = _u;
      password = _p;
      cout << "Constructor overloading with 3 parameters";
    }
    ~User()
    {
      cout << "User Destructor";
    }

    int getId() { return id; } // called getter function.
    int getSalary() { return salary; }
    string getUsername() { return username; }

    void setSalary(int _salary) { salary = _salary; } // called setter function
    void setPassword(int _password) { password = _password; }

    void print()
    {
      cout << "id: " << id << endl;
      cout << "username: " << username << endl;
      cout << "Salary: " << salary << "LE" << endl;
    }
};

int main()
{
  User userOne; // define object with default constructor
  User userTwo(2, "moNassar", "123456");  // define object with 3 parameters constructor

  cout << userTwo.id;  // ❌❌ compiler error => private inaccessible variable
  cout << userTwo.getId();  // get user id
  cout << userTwo.setSalary(10000);  // set user salary

  return 0;
}
```

This example contain some of OOP concepts, we will talk about them later in details.
