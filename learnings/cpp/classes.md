# C++ Classes and Object-Oriented Programming

## Class Basics

### Header Files (.hpp/.h)
- Define the interface/contract of the class
- Contain class declarations, member function declarations, and inline functions
- Should include include guards or `#pragma once` to prevent multiple inclusion

### Implementation Files (.cpp)
- Contain the implementation of member functions declared in the header
- Include the corresponding header file
- Don't need include guards

## Class Components

### Access Specifiers
- `public`: Accessible from anywhere
- `private`: Accessible only from within the class
- `protected`: Accessible from within the class and derived classes

### Member Functions
- Methods that operate on class data
- Can be declared in the class and defined outside using `ClassName::methodName`
- Can be marked `const` to indicate they don't modify class state

### Constructors
- Special functions called when objects are created
- Same name as the class
- No return type
- Can be overloaded for different initialization patterns
- Default constructor takes no arguments

### Destructors
- Called when objects are destroyed
- Prefixed with `~` (e.g., `~ClassName()`)
- Used for cleanup (freeing resources)
- Should be virtual if the class is meant to be inherited from

## Memory Management

### Rule of Three/Five
- If a class needs a custom destructor, copy constructor, or copy assignment operator, it likely needs all three
- Modern C++ extends this to five with move constructor and move assignment operator

### RAII (Resource Acquisition Is Initialization)
- Resources should be acquired in constructors
- Resources should be released in destructors
- Ensures proper cleanup even when exceptions occur

## Best Practices

### Encapsulation
- Keep data members private
- Provide public methods to access/modify data when necessary
- Validate inputs in setter methods

### Const Correctness
- Mark methods that don't modify object state as `const`
- Use `const` parameters when not modifying arguments
- Use `const` references to avoid copying large objects

### Header Organization
- Include guards at the top
- System includes first, then project includes
- Clear, logical ordering of class members
- Consistent style for better readability
