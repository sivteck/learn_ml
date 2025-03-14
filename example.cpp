#include <mlx/array.h>
#include <mlx/ops.h>
#include <iostream>

int main() {
    // Create arrays
    auto a = mlx::core::array({1.0f, 2.0f, 3.0f, 4.0f});
    auto b = mlx::core::array({5.0f, 6.0f, 7.0f, 8.0f});
    
    // Basic operations
    auto c = mlx::core::add(a, b);
    auto d = mlx::core::multiply(a, b);
    
    // Print results
    std::cout << "Sum: " << c << std::endl;
    std::cout << "Product: " << d << std::endl;
    
    return 0;
}
