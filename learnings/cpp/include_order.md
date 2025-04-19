# C++ Include Order Conventions

In C++, the order of `#include` statements follows a specific convention that differs from other languages like JavaScript/TypeScript. This document explains the standard practice and its rationale.

## Standard C++ Include Order

The typical order for include statements in C++ is:

1. **Related header file** (the `.h` file corresponding to this `.cpp`)
2. **C system headers** (e.g., `<unistd.h>`, `<sys/types.h>`)
3. **C++ standard library headers** (e.g., `<iostream>`, `<vector>`)
4. **Other library headers** (third-party libraries)
5. **Project headers** (your own code)

### Example

```cpp
// First, include the corresponding header
#include "my_class.h"

// C system headers
#include <sys/types.h>
#include <unistd.h>

// C++ standard library headers
#include <iostream>
#include <string>
#include <vector>

// Third-party library headers
#include <boost/algorithm/string.hpp>
#include <fmt/format.h>

// Project headers
#include "project/another_class.h"
#include "project/utilities.h"
```

## Rationale

This ordering convention serves several important purposes:

1. **Self-containment check**: Placing the related header first ensures it includes everything it needs. If the header is missing any dependencies, you'll get compiler errors.

2. **Dependency clarity**: The specific-to-general ordering (your header → system → libraries → project) helps catch missing dependencies and prevents headers from accidentally relying on includes from other headers.

3. **Compilation efficiency**: System headers often contain special handling and precompiled versions, so including them earlier can improve compilation performance.

4. **Consistency**: A standard ordering makes it easier to scan and understand include sections across a large codebase.

## Comparison with JavaScript/TypeScript

This differs from JavaScript/TypeScript conventions, where the typical order is:

1. Third-party imports (e.g., React, Lodash)
2. Local/project imports

```javascript
// Third-party imports
import React from 'react';
import { useState } from 'react';
import _ from 'lodash';

// Local imports
import { MyComponent } from './components';
import { useMyHook } from './hooks';
```

## Best Practice

Follow the established convention for the language you're working in. For C++, this means following the order described above, which is used by major style guides including Google's and Amazon's C++ style guides.
