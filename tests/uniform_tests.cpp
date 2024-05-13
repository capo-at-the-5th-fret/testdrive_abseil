#include <doctest/doctest.h>
#include "testdrive_abseil.h"

TEST_CASE("uniform")
{
    std::seed_seq seed2{ 1, 2, 3, 4, 5 };
    std::mt19937 rng(seed2);

    constexpr std::array<int, 4> expected_values = { 4, 3, 1, 1 };

    auto result = testdrive_abseil::uniform<expected_values.size()>(rng, 1, 6);
    REQUIRE(result == expected_values);
}
