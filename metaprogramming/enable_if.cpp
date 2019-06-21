#include <type_traits>
#include <iostream>

struct cat { static constexpr auto name = "cat"; };

template<typename T> struct is_cute : std::false_type {};
template<> struct is_cute<cat> : std::true_type {};

template<typename T>
using isCute = std::enable_if_t<is_cute<T>::value>;

template<typename T, typename = isCute<T>>
void constexpr appraise() {
    std::cout << T::name << " is cute\n";
};

int main() {
    appraise<cat>();
}
