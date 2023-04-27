///////////////////////////////////////////////////////////////////////////
// Precompilled headers
///////////////////////////////////////////////////////////////////////////
#include <stdexcept>
#include <thread>
#include <pch.hpp>

///////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////
#include <xrn/Util.hpp>

void func(
    ::std::chrono::duration<float> value
    , int i
)
{
    // ::fmt::print("\t -- worker {}: start\n", i);
    // ::std::this_thread::sleep_for(value);
    // ::fmt::print("\t -- worker {}: done\n", i);
}

///////////////////////////////////////////////////////////////////////////
auto main()
    -> int
{
    ::xrn::SyncedThreads threads;
    auto i{ 0 };
    threads.push(func, 1000ms, i);
    threads.push(func, 500ms, ++i);
    ::std::this_thread::sleep_for(2000ms);

    for (auto i{ 0uz }; true; ++i) {
        threads.runOnce();
        if (i > 10000) {
            threads.terminate();
        }
    }
}
