# C++ Constructor Initialization

## Member Initialization Lists

In C++, constructors can use a special syntax called a "member initialization list" to initialize class members before the constructor body executes.

### Basic Syntax

```cpp
class MyClass {
private:
  int x_;
  std::string name_;
  
public:
  // Constructor with member initialization list
  MyClass(int x, const std::string& name) : x_{x}, name_{name} {
    // Constructor body - executes after initialization
  }
};
```

The initialization list follows the constructor parameter list, starts with a colon (`:`), and consists of comma-separated initializers for class members.

## Why Use Initialization Lists?

### 1. Performance Benefits

Member initialization lists directly initialize objects rather than first default-initializing them and then assigning values:

```cpp
// More efficient - direct initialization
MyClass::MyClass(int x) : x_{x} {}

// Less efficient - default initialization followed by assignment
MyClass::MyClass(int x) {
  x_ = x;  // Assignment, not initialization
}
```

For complex types like `std::string`, this can avoid unnecessary operations.

### 2. Required for Certain Types

Initialization lists are the only way to initialize:
- `const` members
- Reference members
- Members without default constructors
- Base classes with non-default constructors

```cpp
class Example {
private:
  const int id_;           // Must use initialization list
  std::string& reference_; // Must use initialization list
  
public:
  Example(int id, std::string& ref) : id_{id}, reference_{ref} {}
};
```

### 3. Initialization Order

Members are initialized in the order they are declared in the class, not the order in the initialization list:

```cpp
class OrderExample {
private:
  int first_;   // Initialized first
  int second_;  // Initialized second
  
public:
  // Despite the order in this list, first_ is still initialized before second_
  OrderExample() : second_{42}, first_{second_ + 1} {}
};
```

This can lead to subtle bugs if you depend on initialization order in the list.

## Modern C++ Initialization Styles

### Parentheses vs. Braces

C++11 introduced uniform initialization with braces:

```cpp
// Traditional parentheses initialization
MyClass::MyClass(int x) : x_(x) {}

// Modern brace initialization
MyClass::MyClass(int x) : x_{x} {}
```

Brace initialization has several advantages:
- Prevents narrowing conversions
- Works in more contexts
- More consistent syntax

### Default Member Initializers

C++11 also allows initializing members directly in the class definition:

```cpp
class DefaultInit {
private:
  int count_{0};             // Default member initializer
  std::string name_{"Unknown"};
  
public:
  // These defaults are used if not overridden in the initialization list
  DefaultInit() {}
  
  // This overrides the default for name_ but uses the default for count_
  DefaultInit(const std::string& name) : name_{name} {}
};
```

## Best Practices

1. **Initialize all members** in the initialization list or with default member initializers
2. **Use brace initialization** `{}` for consistency and safety
3. **Be aware of initialization order** (declaration order, not list order)
4. **Keep initialization lists readable** with consistent formatting
5. **Use default member initializers** for values that are commonly the same across constructors

## Example: Complete Class with Modern Initialization

```cpp
class Person {
private:
  std::string name_{};
  int age_{0};
  bool employed_{false};
  std::vector<std::string> skills_{};
  
public:
  // Default constructor uses all the default member initializers
  Person() = default;
  
  // Partial constructor overrides some defaults
  Person(const std::string& name) : name_{name} {}
  
  // Full constructor overrides all defaults
  Person(const std::string& name, int age, bool employed)
      : name_{name},
        age_{age},
        employed_{employed} {}
};
```
