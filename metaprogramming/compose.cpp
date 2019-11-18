#include <iostream>
#include <tuple>

// it'd be nice to remove the single argument restriction on g, so f could
// return a tuple

template <typename G, typename F> 
constexpr auto compose(G g, F f) {
    return [g, f](auto&&... x){
        return g(f(x...));
    };
}

int main() {
    auto sum = [](auto x, auto y) { return x + y; };
    auto square = [](auto x) { return x * x; };
    auto squareAfterSum = compose(square, sum);
    static_assert(squareAfterSum(1, 2) == square(sum(1, 2)));
}