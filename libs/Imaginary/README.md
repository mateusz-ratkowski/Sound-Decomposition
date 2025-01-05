# C++-Imaginary-numbers-library

This C++ library provides a class `Imaginary` for representing and performing operations on complex numbers (with real and imaginary parts). The library includes basic arithmetic operations, comparisons, and additional functionalities like modulus, conjugate, and norm.

## Features
- **Basic Operations**: Addition, subtraction, multiplication, and division with complex numbers and scalars.
- **Increment/Decrement**: Custom increment and decrement operators that adjust the complex number’s modulus by 1.
- **Comparison**: Compare complex numbers based on their modulus.
- **Modulus and Conjugate**: Calculate the modulus, conjugate, and normalized version of complex numbers.
- **Array Access**: Access real and imaginary parts using the `[]` operator.

## Example Usage

```cpp
#include "Imaginary.h"

int main() {
    Imaginary a(3, 4);
    Imaginary b(1, 2);

    Imaginary sum = a + b;
    std::cout << "Sum: " << sum << std::endl;

    std::cout << "Modulus of a: " << a.module() << std::endl;
    std::cout << "Conjugate of b: " << b.conjugate() << std::endl;

    return 0;
}
