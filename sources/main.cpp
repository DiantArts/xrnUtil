///////////////////////////////////////////////////////////////////////////
// Precompilled headers
///////////////////////////////////////////////////////////////////////////
#include <pch.hpp>

///////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////
#include <xrn/Util.hpp>

template <
    typename T
    , bool hasChangedFlag = true
> struct A
{
    T& func()
    {
        return static_cast<T&>(*this);
    }

    template <
        typename = ::std::enable_if_t<hasChangedFlag>
    > void test()
    {
        ::fmt::print("{}\n", "testing");
    }
};

struct B
    : public ::A<B, true>
{};

///////////////////////////////////////////////////////////////////////////
auto main()
    -> int
{
    // for (auto i{ 0uz }; i < 100; ++i) {
        // ::fmt::print("{}\n", ::xrn::rng(-10, 10));
    // }
    B b;
    ::fmt::print("{}\n", (void*)&b);
    ::fmt::print("{}\n", (void*)&b.func());
    b.test();
}
