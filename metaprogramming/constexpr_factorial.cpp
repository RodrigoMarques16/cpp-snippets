#include <iostream>

template <int N> constexpr auto factorial() noexcept -> int { return N * factorial<N-1>(); };
template <> constexpr auto factorial<0>() noexcept -> int { return 1; };

int main() {
	std::cout << factorial<10>() << '\n';
    return 0;
}