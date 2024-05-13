#pragma once

#include <array>
#include <random>
#include <absl/random/random.h>

namespace testdrive_abseil
{
    // Generate N random numbers between lo and hi, each with a uniform chance
    // of being generated
    template <std::size_t N, typename Gen>
    requires (N > 0 && N <= 32)
    std::array<int, N> uniform(Gen&& gen, int lo, int hi)
    {
        //assert(lo <= hi);

        std::array<int, N> ret = { };

        for (std::size_t i = 0; i < N; ++i)
        {
            ret[i] = absl::Uniform(absl::IntervalClosedOpen, gen, lo, hi);
        }

        return ret;
    }

    bool return_false()
    {
        return false;
    }
}