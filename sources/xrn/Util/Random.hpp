#pragma once

///////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////
#include <xrn/Util/Time.hpp>



namespace xrn::util {

///////////////////////////////////////////////////////////////////////////
/// \brief Simplifies file manipulations
/// \ingroup util
///
/// \include Random.hpp <xrn/Util/Random.hpp>
///
/// ::xrn::util::Random provide an easy approach to Random number
/// generation
///
/// Usage example:
/// \code
/// ::xrn::Rng rng{ 5, 10 };
/// auto number2{ rng.generate(0, 10) }; // between 0 and 10 (inclusive)
/// auto number3{ rng.generate() }; // between 5 and 10 (inclusive)
/// \endcode
///
///////////////////////////////////////////////////////////////////////////
template <
    typename T
> class BasicRandomNumberGenerator {

public:

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Static
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Type internally contained by the class
    ///
    ///////////////////////////////////////////////////////////////////////////
    using Type = T;



public:

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Constructors
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Will return number in the range [0; 100] (inclusive)
    ///
    ///////////////////////////////////////////////////////////////////////////
    BasicRandomNumberGenerator();

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Get a random number in the specified range [0; 100] (inclusive)
    ///
    ///////////////////////////////////////////////////////////////////////////
    BasicRandomNumberGenerator(
        BasicRandomNumberGenerator::Type min
        , BasicRandomNumberGenerator::Type max
    );



    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Basic
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Get a random number in the default range [0; 100] (inclusive)
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto generate()
        -> BasicRandomNumberGenerator::Type;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Get a random number in the specified range (inclusive)
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto generate(
        BasicRandomNumberGenerator::Type min
        , BasicRandomNumberGenerator::Type max
    ) -> BasicRandomNumberGenerator::Type;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Get a random number in the default range [0; 100] (inclusive)
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto operator()()
        -> BasicRandomNumberGenerator::Type;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Get a random number in the specified range (inclusive)
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto operator()(
        BasicRandomNumberGenerator::Type min
        , BasicRandomNumberGenerator::Type max
    ) -> BasicRandomNumberGenerator::Type;



private:

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Variables
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ::std::random_device m_physicalRng;
    ::std::mt19937 m_rng;
    ::std::uniform_int_distribution<BasicRandomNumberGenerator::Type> m_range;

};

} // namespace xrn::ecs

///////////////////////////////////////////////////////////////////////////
// Template specialization
///////////////////////////////////////////////////////////////////////////
namespace xrn {
    template <typename T> using BasicRandomNumberGenerator =
        ::xrn::util::BasicRandomNumberGenerator<T>;
}
namespace xrn::util { using RandomNumberGenerator = BasicRandomNumberGenerator<int>; }
namespace xrn { using RandomNumberGenerator = ::xrn::util::RandomNumberGenerator; }
namespace xrn { using Rng = ::xrn::util::RandomNumberGenerator; }



///////////////////////////////////////////////////////////////////////////
// Static RNG
///////////////////////////////////////////////////////////////////////////
namespace xrn::util { inline ::xrn::Rng rng; }
namespace xrn { inline ::xrn::Rng& rng{ ::xrn::util::rng }; };



///////////////////////////////////////////////////////////////////////////
// Header-implimentation
///////////////////////////////////////////////////////////////////////////
#include <xrn/Util/Random.impl.hpp>
