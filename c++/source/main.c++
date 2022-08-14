#include <iostream>
#include <string_view>
#include <tuple>

template <size_t I>
constexpr auto rule() -> auto
{
    if constexpr ((I % 3 == 0) && (I % 5 == 0))
        return "fizzbuzz";
    else if constexpr (I % 3 == 0)
        return "fizz";
    else if constexpr (I % 5 == 0)
        return "buzz";
    else
        return I;
}

template <size_t... Is>
constexpr auto fizzbuzz(std::index_sequence<Is...>) -> auto
{
    return std::make_tuple(rule<Is>()...);
}

auto main() -> int
{
    constexpr auto result = fizzbuzz(std::make_index_sequence<101>{});

    std::apply([](auto &&...args) { ((std::cout << args << std::endl), ...); }, result);

    return 0;
}