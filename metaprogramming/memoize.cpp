#include <iostream>
#include <chrono>
#include <thread>

auto const memoize(auto f) {
    return [f](auto... args) {
        using return_type = decltype(f(args...));
        static return_type value{};
        if (value == return_type{})   
            value = f(args...);
        return value;
    };
}

int main() {
    auto const timesTwo = memoize([](int x){
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        return x * 2;
    });
    std::cout << timesTwo(2); // slow
    std::cout << timesTwo(2); // instant
}