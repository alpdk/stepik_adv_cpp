#include <iostream>

// определите метафункцию Fib<N>
template<size_t N>
struct Fib {
    static size_t const value = Fib<N - 1>::value + Fib<N - 2>::value;
};

template<>
struct Fib<1> {
    static size_t const value = 1;
};

template<>
struct Fib<0> {
    static size_t const value = 0;
};

int main() {
    std::cout << Fib<10>::value;
    return 0;
}
