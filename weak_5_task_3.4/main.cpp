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

template<int H, typename T>
struct IntCons;

template<int H, int... T>
struct IntCons<H, IntList<T...>> {
    using type = IntList<H, T...>;
};

template<int H, typename T>
struct Add;

template<int H, int... T>
struct Add<H, IntList<T...>> {
    using type = IntList<T..., H>;
};

template<int H>
struct Generate {
    using type = typename Add<H - 1, typename Generate<H - 1>::type>::type;
};

template<>
struct Generate<0> {
    using type = IntList<>;
};

int main() {

    using L1 = IntList<2,3,4>;

    using L2 = IntCons<1, L1>::type;   // IntList<1,2,3,4>

    using L3 = Generate<5>::type;      // IntList<0,1,2,3,4>

    std::cout << L3::Head << std::endl;

    return 0;
}
