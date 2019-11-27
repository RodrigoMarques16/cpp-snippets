template <int N> struct Adder {
    constexpr int operator()(int x) const { return x + N; }
};

int main() {
    constexpr Adder<2> add2;
    static_assert(add2(3) == Adder<4>{}(1));
}