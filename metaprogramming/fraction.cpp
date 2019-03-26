#include <type_traits>
#include <iostream>

// 1. constexpr function ///////////////////
// can't partially specialize templatized functions so at least I can't do better than this
template <int N, int D> struct Fraction1 {};
template <int S, int N, int D> constexpr auto scalar1() noexcept -> Fraction1<S*N, S*D> {};

// 2. static class ///////////////////////
template <int N, int D> struct Fraction2 { 
    static constexpr int Num = N;
    static constexpr int Den = D;
};

template <int S, typename F> 
struct scalar2 { 
    typedef Fraction2<S*F::Num, S*F::Den> result;
};

// 3. partially specialized class /////////
// equivalent to the above
template <int S, typename F> 
struct scale {};

template <int S, template<int, int> typename F, int N, int D> 
struct scale<S, F<N, D>> {
    typedef Fraction2<S*F<N,D>::Num, S*F<N,D>::Den> result;
};

int main() {
    static_assert(std::is_same<decltype(scalar1<2, 2, 2>()), Fraction1<4,4>>::value);
    static_assert(std::is_same<scalar2<2, Fraction2<2,2>>::result, Fraction2<4,4>>::value);
}