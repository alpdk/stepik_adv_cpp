#include <iostream>

template<int ... Types>
struct IntList;

template<int H, int ... T>
struct IntList<H, T...> {
    static int const Head = H;
    using Tail = IntList<T...>;
};

template<>
struct IntList<> { };

template<typename T>
struct Length {
    static int const value = 1 + Length<typename T::Tail>::value;
};

template<>
struct Length<IntList<>> {
    static int const value = 0;
};

int main() {
    using primes = IntList<2,3,5,7,11,13>;

    constexpr size_t len = Length<primes>::value; // 6

    std::cout << len << std::endl;

    return 0;
}
