#include <pch.hpp>
#include <catch2/catch.hpp>
#include <xrn/Util/Time.hpp>

template class ::xrn::util::BasicTime<float>;

using TestingTime = ::xrn::util::BasicTime<float>;

TEST_CASE("Time.Basic01")
{
    const auto t1{ ::TestingTime::createAsSeconds(1) };
    const auto t2{ ::TestingTime::createAsMilliseconds(1000) };
    const auto t3{ ::TestingTime::createAsMicroseconds(1000000) };
    const auto t4{ ::TestingTime::createAsNanoseconds(1000000000) };
    REQUIRE(t1 == t2);
    REQUIRE(t1 == t3);
    REQUIRE(t1 == t4);

    const auto t5{ ::TestingTime::createAsMilliseconds(900) };
    const auto t6{ ::TestingTime::createAsMilliseconds(1100) };
    REQUIRE(t1 != t5);
    REQUIRE(t1 != t6);

    REQUIRE(t1 > t5);
    REQUIRE(t1 >= t5);

    REQUIRE(t1 < t6);
    REQUIRE(t1 <= t6);

    REQUIRE(t1 == 1000);
    REQUIRE(t1 == 1000.0f);
}

TEST_CASE("Time.Basic02")
{
    const auto t1{ ::TestingTime::createAsSeconds(1) };
    const auto t2{ ::TestingTime::createAsMilliseconds(1) };
    const auto t3{ ::TestingTime::createAsMicroseconds(1) };
    const auto t4{ ::TestingTime::createAsNanoseconds(1) };

    REQUIRE(t1.getAsSeconds() == 1);
    REQUIRE(t2.get() == 1);
    REQUIRE(t2.getAsMilliseconds() == 1);
    REQUIRE(t3.getAsMicroseconds() == 1);
    REQUIRE(t4.getAsNanoseconds() == 1);
}

TEST_CASE("Time.Add01")
{
    ::TestingTime t1;

    t1.set(::TestingTime::createAsMilliseconds(900));
    t1 += 100;
    REQUIRE(t1.get() == 1000);

    t1 = 900;
    t1 = t1 + 100;
    REQUIRE(t1.get() == 1000);

    t1 = ::TestingTime::createAsMilliseconds(900);
    t1.add(100);
    REQUIRE(t1.get() == 1000);

    t1.set(900);
    t1 += ::TestingTime::createAsMilliseconds(100);
    REQUIRE(t1.get() == 1000);

    t1.set(900);
    t1 = t1 + ::TestingTime::createAsMilliseconds(100);
    REQUIRE(t1.get() == 1000);

    t1.set(900);
    t1.add(::TestingTime::createAsMilliseconds(100));
    REQUIRE(t1.get() == 1000);
}

TEST_CASE("Time.Sub01")
{
    ::TestingTime t1;

    t1.set(1100);
    t1 -= 100;
    REQUIRE(t1.get() == 1000);

    t1.set(1100);
    t1 = t1 - 100;
    REQUIRE(t1.get() == 1000);

    t1.set(1100);
    t1.sub(100);
    REQUIRE(t1.get() == 1000);

    t1.set(1100);
    t1 -= ::TestingTime::createAsMilliseconds(100);
    REQUIRE(t1.get() == 1000);

    t1.set(1100);
    t1 = t1 - ::TestingTime::createAsMilliseconds(100);
    REQUIRE(t1.get() == 1000);

    t1.set(1100);
    t1.sub(::TestingTime::createAsMilliseconds(100));
    REQUIRE(t1.get() == 1000);
}

TEST_CASE("Time.Mul01")
{
    ::TestingTime t1;

    t1.set(500);
    t1 *= 2;
    REQUIRE(t1.get() == 1000);

    t1.set(500);
    t1 = t1 * 2;
    REQUIRE(t1.get() == 1000);

    t1.set(500);
    t1.mul(2);
    REQUIRE(t1.get() == 1000);

    t1.set(500);
    t1 *= ::TestingTime::createAsMilliseconds(2);
    REQUIRE(t1.get() == 1000);

    t1.set(500);
    t1 = t1 * ::TestingTime::createAsMilliseconds(2);
    REQUIRE(t1.get() == 1000);

    t1.set(500);
    t1.mul(::TestingTime::createAsMilliseconds(2));
    REQUIRE(t1.get() == 1000);
}

TEST_CASE("Time.Div01")
{
    ::TestingTime t1;

    t1.set(2000);
    t1 /= 2;
    REQUIRE(t1.get() == 1000);

    t1.set(2000);
    t1 = t1 / 2;
    REQUIRE(t1.get() == 1000);

    t1.set(2000);
    t1.div(2);
    REQUIRE(t1.get() == 1000);

    t1.set(2000);
    t1 /= ::TestingTime::createAsMilliseconds(2);
    REQUIRE(t1.get() == 1000);

    t1.set(2000);
    t1 = t1 / ::TestingTime::createAsMilliseconds(2);
    REQUIRE(t1.get() == 1000);

    t1.set(2000);
    t1.div(::TestingTime::createAsMilliseconds(2));
    REQUIRE(t1.get() == 1000);
}

TEST_CASE("Time.Mod01")
{
    ::TestingTime t1;

    t1.set(1000);
    t1 %= 3;
    REQUIRE(t1.get() == 1);

    t1.set(1000);
    t1 = t1 % 3;
    REQUIRE(t1.get() == 1);

    t1.set(1000);
    t1.mod(3);
    REQUIRE(t1.get() == 1);

    t1.set(1000);
    t1 %= ::TestingTime::createAsMilliseconds(3);
    REQUIRE(t1.get() == 1);

    t1.set(1000);
    t1 = t1 % ::TestingTime::createAsMilliseconds(3);
    REQUIRE(t1.get() == 1);

    t1.set(1000);
    t1.mod(::TestingTime::createAsMilliseconds(3));
    REQUIRE(t1.get() == 1);
}

TEST_CASE("Time.litteral01")
{
    using namespace ::xrn::util::literal;

    const auto t1{ ::TestingTime::createAsSeconds(1) };
    const auto t2{ ::TestingTime::createAsMilliseconds(1000) };
    const auto t3{ ::TestingTime::createAsMicroseconds(1000000) };
    const auto t4{ ::TestingTime::createAsNanoseconds(1000000000) };

    const auto tt1{ 1_s };
    const auto tt2{ 1000_ms };
    const auto tt3{ 1000000_us };
    const auto tt4{ 1000000000_ns };

    REQUIRE(t1 == tt1);
    REQUIRE(t2 == tt2);
    REQUIRE(t3 == tt3);
    REQUIRE(t4 == tt4);
}
