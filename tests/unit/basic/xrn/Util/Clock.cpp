#include <pch.hpp>
#include <catch2/catch.hpp>
#include <xrn/Util/Clock.hpp>

template class ::xrn::util::BasicClock<::xrn::Time>;

using TestingClock = ::xrn::util::BasicClock<::xrn::Time>;

TEST_CASE(" xrnUtil :: Clock.Basic01")
{
    ::TestingClock clock;

    auto t1{ clock.getElapsed() };
    auto t2{ clock.restart() };
    clock.reset();

    REQUIRE(t1 < t2);
}
