# cst_ptr

A small custom C++ smart pointer implementation built to explore **RAII, ownership, move semantics, and resource management**.

`cst_ptr` is a lightweight, exclusive-ownership smart pointer inspired by `std::unique_ptr`. It manages a dynamically allocated object and automatically releases its memory when the pointer goes out of scope.

## Features

- **RAII** – Automatically deallocates owned memory when destroyed.
- **Exclusive Ownership** – Copy construction and copy assignment are disabled to prevent multiple owners.
- **Move Semantics** – Supports move construction and move assignment to transfer ownership.
- **Pointer Operators** – Implements `*`, `->`, and explicit `bool` conversion.
- **Ownership Management** – Provides `release()`, `reset()`, and `get()`.
- **Templates** – Supports different object types through templates.
- **No Dependencies** – Uses standard C++ functionality.

## Usage

```cpp
#include <iostream>
#include "custptr.h"

int main() {
    cst_ptr<int> ptr(new int(42));

    std::cout << *ptr << '\n';

    if (ptr) {
        std::cout << "Pointer is valid\n";
    }

    ptr.reset(new int(100));

    std::cout << *ptr << '\n';

    return 0;
}
```

## Available Operations

| Operation | Description |
|---|---|
| `cst_ptr()` | Creates an empty pointer. |
| `cst_ptr(T* d)` | Takes ownership of a raw pointer. |
| `~cst_ptr()` | Releases owned memory. |
| `operator*()` | Dereferences the managed object. |
| `operator->()` | Accesses members of the managed object. |
| `operator bool()` | Checks whether the pointer owns an object. |
| `release()` | Releases ownership and returns the raw pointer. |
| `reset()` | Deletes the current object and becomes empty. |
| `reset(T* new_data)` | Replaces the managed object. |
| `get()` | Returns the raw pointer without transferring ownership. |
| Move constructor | Transfers ownership from another `cst_ptr`. |
| Move assignment | Transfers ownership, replacing the current object. |

## Ownership Rules

`cst_ptr` follows an exclusive-ownership model:

- Only one `cst_ptr` can own an object at a time.
- Copying is disabled.
- Moving transfers ownership to another pointer.
- The moved-from pointer becomes `nullptr`.
- Destroying the owning pointer automatically deletes its object.

## Project Goals

This project was created as a hands-on exercise in understanding how C++ smart pointers work internally, particularly:

- Dynamic memory allocation and deallocation.
- RAII and object lifetime.
- Copy vs. move semantics.
- Ownership transfer.
- Operator overloading.
- Template classes.

## Limitations

This is an educational implementation, not a replacement for `std::unique_ptr`.

Currently, `cst_ptr`:
- Uses `delete` rather than `delete[]`.
- Does not support custom deleters.
- Does not support array ownership.
- Does not include `make_unique` functionality.

## License

This project is open source and available under the MIT License.
