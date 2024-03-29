#pragma once

namespace xrn::util {

///////////////////////////////////////////////////////////////////////////
/// \brief Allows simple Time manipulations
/// \ingroup util
///
/// \include Time.hpp <xrn/Util/Time.hpp>
///
/// ::xrn::util::BasicTime's purpuse is to represent and uniform time
/// manipulations accross all xrn Projects.
/// Its usage is straight forward as it just contains a BasicTime value,
/// gettable as seconds, milliseconds or microseconds. It also is possible to
/// perform calculations between time values. By default, xrn projects
/// manipulate milliseconds, and if the same type as the template parameter of
/// the calss is passed to one of the methods, it will be interpreted as such.
/// The class can be constructed by the factories createAsSeconds(),
/// createAsMilliseconds() and with a constructor with the type given as
/// template parameter.
/// This class is mostly used by ::xrn::util::BasicClock, but can be used
/// manually.
/// This class is aliased with ::xrn::util::Time and ::xrn::Time.
///
/// Usage example:
/// \code
/// using ::xrn::util::literal::operator""_ns;
///
/// auto t1{ ::xrn::Time::createAsSeconds(0.1) };
/// auto t2{ t1.getAsMilliseconds() }; // 100ms
/// ::xrn::Time t3{ 30 };
/// auto t4{ t3.getAsMicroseconds() }; // 30000ms
/// auto t5{ ::xrn::Time::createAsNanoseconds(-800000) }; // -0.8
/// auto t6{ t5.getAsSeconds() }; // -0.0008ms
/// auto t7{ t1 + ::xrn::Time::createAsSeconds(t6) }; // 99.2ms
/// auto t8{ t1 + -800000_ns }; // 99.2ms
/// auto t9{ t1 + t5 }; // 99.2ms
/// auto t10{ t1 + 55 }; // 155ms
/// auto t11{ 55 + t1 }; // 155ms
/// \endcode
///
/// \see ::xrn::util::BasicClock
///
///////////////////////////////////////////////////////////////////////////
template <
    typename T
> class BasicTime {

public:

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // static elements
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Type internally contained by the class
    ///
    ///////////////////////////////////////////////////////////////////////////
    using Type = T;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Constructs a ::xrn::util::BasicTime from a value evaluated as
    ///        seconds
    ///
    /// \param amount Value contructed from the amount of seconds
    ///
    /// \return ::xrn::util::BasicTime just created
    ///
    /// \see createAsMilliseconds(), createAsMicroseconds(),
    ///      createAsNanoseconds()
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] constexpr static auto createAsSeconds(
        const auto& amount
    ) noexcept -> BasicTime;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Constructs a ::xrn::util::BasicTime from a value evaluated as
    ///        milliseconds
    ///
    /// \param amount Value contructed from the amount of milliseconds
    ///
    /// \return ::xrn::util::BasicTime just created
    ///
    /// \see createAsSeconds(), createAsMicroseconds(), createAsNanoseconds()
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] constexpr static auto createAsMilliseconds(
        const auto& amount
    ) noexcept -> BasicTime;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Constructs a ::xrn::util::BasicTime from a value evaluated as
    ///        microseconds
    ///
    /// \param amount Value contructed from the amount of microseconds
    ///
    /// \return ::xrn::util::BasicTime just created
    ///
    /// \see createAsSeconds(), createAsMilliseconds(), createAsNanoseconds()
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] constexpr static auto createAsMicroseconds(
        const auto& amount
    ) noexcept -> BasicTime;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Constructs a ::xrn::util::BasicTime from a value evaluated as
    ///        nanoseconds
    ///
    /// \param amount Value contructed from the amount of nanoseconds
    ///
    /// \return ::xrn::util::BasicTime just created
    ///
    /// \see createAsSeconds(), createAsMilliseconds(), createAsNanoseconds()
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] constexpr static auto createAsNanoseconds(
        const auto& amount
    ) noexcept -> BasicTime;



public:

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Constructors
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Constructor
    ///
    /// Constructs a ::xrn::util::BasicTime containing a point in time with no
    /// value.
    ///
    ///////////////////////////////////////////////////////////////////////////
    explicit constexpr BasicTime() noexcept;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Constructor
    ///
    /// Constructs a ::xrn::util::BasicTime containing a point in time.
    ///
    /// \param amount Time in milliseconds
    ///
    ///////////////////////////////////////////////////////////////////////////
    explicit constexpr BasicTime(
        auto amount
    ) noexcept;



    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Comparison
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Compares with a ::xrn::util::BasicTime values
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] constexpr auto operator<=>(
        const BasicTime& rhs
    ) const
        -> ::std::partial_ordering;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Compares with any type if comparable with the internal type
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] constexpr auto operator<=>(
        const auto& rhs
    ) const
        -> ::std::partial_ordering;



    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Get
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Convertion to the type internally stored
    ///
    /// \return Time in milliseconds
    ///
    /// \see get(), getAsMilliseconds()
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] constexpr operator BasicTime::Type() const noexcept;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Convertion to the type internally stored
    ///
    /// \return Time in milliseconds
    ///
    /// \see get(), getAsMilliseconds()
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] constexpr auto operator*() const noexcept
        -> BasicTime::Type;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Get the value as it's internally stored
    ///
    /// \return Time in milliseconds
    ///
    /// \see getAsMilliseconds()
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] constexpr auto get() const
        -> BasicTime::Type;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Get the value as seconds
    ///
    /// \return Value as second as the internally stored type
    ///
    /// \see get(), getAsMilliseconds(), getAsMicroseconds(),
    /// getAsNanoseconds()
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] constexpr auto getAsSeconds() const
        -> BasicTime::Type;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Get the value as milliseconds
    ///
    /// \return Value as second as the internally stored type
    ///
    /// \see get(), getAsSeconds(), getAsMicroseconds(), getAsNanoseconds()
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] constexpr auto getAsMilliseconds() const
        -> BasicTime::Type;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Get the value as milliseconds
    ///
    /// \return Value as second as the internally stored type
    ///
    /// \see get(), getAsSeconds(), getAsMilliseconds(), getAsNanoseconds()
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] constexpr auto getAsMicroseconds() const
        -> BasicTime::Type;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Get the value as milliseconds
    ///
    /// \return Value as second as the internally stored type
    ///
    /// \see get(), getAsSeconds(), getAsMilliseconds(), getAsMicroseconds()
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] constexpr auto getAsNanoseconds() const
        -> BasicTime::Type;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Get the value as seconds
    ///
    /// \return Value as second as the internally stored type
    ///
    /// \see get(), getAsChronoMilliseconds(), getAsChronoMicroseconds(),
    /// getAsChronoNanoseconds()
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] constexpr auto getAsChronoSeconds() const
        -> ::std::chrono::duration<BasicTime::Type>;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Get the value as milliseconds
    ///
    /// \return Value as second as the internally stored type
    ///
    /// \see get(), getAsChronoSeconds(), getAsChronoMicroseconds(),
    /// getAsChronoNanoseconds()
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] constexpr auto getAsChronoMilliseconds() const
        -> ::std::chrono::duration<BasicTime::Type, ::std::milli>;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Get the value as milliseconds
    ///
    /// \return Value as second as the internally stored type
    ///
    /// \see get(), getAsChronoSeconds(), getAsChronoMilliseconds(),
    /// getAsChronoNanoseconds()
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] constexpr auto getAsChronoMicroseconds() const
        -> ::std::chrono::duration<BasicTime::Type, ::std::micro>;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Get the value as milliseconds
    ///
    /// \return Value as second as the internally stored type
    ///
    /// \see get(), getAsChronoSeconds(), getAsChronoMilliseconds(),
    /// getAsChronoMicroseconds()
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] constexpr auto getAsChronoNanoseconds() const
        -> ::std::chrono::duration<BasicTime::Type, ::std::nano>;



    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Set
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Sets the internal point time value to a new one
    ///
    /// \param amount New time in milliseconds
    ///
    /// \return *this reassigned
    ///
    /// \see set()
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto operator=(
        const auto& amount
    ) -> BasicTime&;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Sets the internal point time value to a new one
    ///
    /// \param amount New time in milliseconds
    ///
    /// \see operator=()
    ///
    ///////////////////////////////////////////////////////////////////////////
    void set(
        const BasicTime& amount
    );

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Sets the internal point time value to a new one
    ///
    /// \param amount New time in milliseconds
    ///
    /// \see operator=()
    ///
    ///////////////////////////////////////////////////////////////////////////
    void set(
        const auto& amount
    );



    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Add
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Adds ::xrn::util::BasicTime given as parameter
    ///
    /// \param rhs Time to add
    ///
    /// \return New time added with \a rhs
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto operator+=(
        const BasicTime& rhs
    ) -> BasicTime&;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Adds time as milliseconds given as parameter
    ///
    /// \param rhs Time to add in milliseconds
    ///
    /// \return New time added with \a rhs
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto operator+=(
        const auto& rhs
    ) -> BasicTime&;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Adds ::xrn::util::BasicTime given as parameter
    ///
    /// Same as add, but does return a copy.
    ///
    /// \param rhs Time to add
    ///
    /// \return New time added with \a rhs
    ///
    /// \see add()
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] constexpr auto operator+(
        const BasicTime& rhs
    ) const
        -> BasicTime;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Adds time as milliseconds given as parameter
    ///
    /// Same as add, but does return a copy.
    ///
    /// \param rhs Time to add in milliseconds
    ///
    /// \return New time added with \a rhs
    ///
    /// \see add()
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] constexpr auto operator+(
        const auto& rhs
    ) const
        -> BasicTime;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Adds ::xrn::util::BasicTime given as parameter
    ///
    /// Adds the amount given as parameter.
    ///
    /// \param rhs Time to add
    ///
    /// \return New time added with \a rhs
    ///
    ///////////////////////////////////////////////////////////////////////////
    void add(
        const BasicTime& amount
    );

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Adds time as milliseconds given as parameter
    ///
    /// Adds the amount given as parameter.
    ///
    /// \param rhs Time to add in milliseconds
    ///
    /// \return New time added with \a rhs
    ///
    ///////////////////////////////////////////////////////////////////////////
    void add(
        const auto& amount
    );



    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Sub
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Substracts ::xrn::util::BasicTime given as parameter
    ///
    /// \param rhs Time to substract
    ///
    /// \return New time added with \a rhs
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto operator-=(
        const BasicTime& rhs
    ) -> BasicTime&;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Substracts time as milliseconds given as parameter
    ///
    /// \param rhs Time to substract in milliseconds
    ///
    /// \return New time added with \a rhs
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto operator-=(
        const auto& rhs
    ) -> BasicTime&;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Substracts ::xrn::util::BasicTime given as parameter
    ///
    /// Same as substract, but does return a copy.
    ///
    /// \param rhs Time to substract
    ///
    /// \return New time added with \a rhs
    ///
    /// \see sub()
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] constexpr auto operator-(
        const BasicTime& rhs
    ) const
        -> BasicTime;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Substracts time as milliseconds given as parameter
    ///
    /// Same as substract, but does return a copy.
    ///
    /// \param rhs Time to substract in milliseconds
    ///
    /// \return New time added with \a rhs
    ///
    /// \see sub()
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] constexpr auto operator-(
        const auto& rhs
    ) const
        -> BasicTime;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Substracts ::xrn::util::BasicTime given as parameter
    ///
    /// Substracts the amount given as parameter.
    ///
    /// \param rhs Time to substract
    ///
    /// \return New time added with \a rhs
    ///
    ///////////////////////////////////////////////////////////////////////////
    void sub(
        const BasicTime& amount
    );


    ///////////////////////////////////////////////////////////////////////////
    /// \brief Substracts time as milliseconds given as parameter
    ///
    /// Substracts the amount given as parameter.
    ///
    /// \param rhs Time to substract in milliseconds
    ///
    /// \return New time added with \a rhs
    ///
    ///////////////////////////////////////////////////////////////////////////
    void sub(
        const auto& amount
    );



    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Mul
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Multiply time as milliseconds given as parameter
    ///
    /// \param rhs Time to multiply in milliseconds
    ///
    /// \return New time added with \a rhs
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto operator*=(
        const auto& rhs
    ) -> BasicTime&;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Multiply time as milliseconds given as parameter
    ///
    /// Same as multiply, but does return a copy.
    ///
    /// \param rhs Time to multiply in milliseconds
    ///
    /// \return New time added with \a rhs
    ///
    /// \see mul()
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] constexpr auto operator*(
        const auto& rhs
    ) const
        -> BasicTime;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Multiply time as milliseconds given as parameter
    ///
    /// Multiply the amount given as parameter.
    ///
    /// \param rhs Time to multiply in milliseconds
    ///
    /// \return New time added with \a rhs
    ///
    ///////////////////////////////////////////////////////////////////////////
    void mul(
        const auto& amount
    );



    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Div
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Divides time as milliseconds given as parameter
    ///
    /// \param rhs Time to divide in milliseconds
    ///
    /// \return New time added with \a rhs
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto operator/=(
        const auto& rhs
    ) -> BasicTime&;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Divides time as milliseconds given as parameter
    ///
    /// Same as divide, but does return a copy.
    ///
    /// \param rhs Time to divide in milliseconds
    ///
    /// \return New time added with \a rhs
    ///
    /// \see div()
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] constexpr auto operator/(
        const auto& rhs
    ) const
        -> BasicTime;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Divides time as milliseconds given as parameter
    ///
    /// Divides the amount given as parameter.
    ///
    /// \param rhs Time to divide in milliseconds
    ///
    /// \return New time added with \a rhs
    ///
    ///////////////////////////////////////////////////////////////////////////
    void div(
        const auto& amount
    );



    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Mod
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Modulos time as milliseconds given as parameter
    ///
    /// \param rhs Time to modulo in milliseconds
    ///
    /// \return New time added with \a rhs
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto operator%=(
        const auto& rhs
    ) -> BasicTime&;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Modulos time as milliseconds given as parameter
    ///
    /// Same as modulo, but does return a copy.
    ///
    /// \param rhs Time to modulo in milliseconds
    ///
    /// \return New time added with \a rhs
    ///
    /// \see mod()
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] constexpr auto operator%(
        const auto& rhs
    ) const
        -> BasicTime;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Modulos time as milliseconds given as parameter
    ///
    /// Modulos the amount given as parameter.
    ///
    /// \param rhs Time to modulo in milliseconds
    ///
    /// \return New time added with \a rhs
    ///
    ///////////////////////////////////////////////////////////////////////////
    void mod(
        const auto& amount
    );



private:

    BasicTime::Type m_time;

};

} // namespace xrn::util



///////////////////////////////////////////////////////////////////////////
// Template specialization
///////////////////////////////////////////////////////////////////////////
namespace xrn::util { using Time = ::xrn::util::BasicTime<float>; }
namespace xrn { using Time = ::xrn::util::Time; }



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Litteral definitions
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

namespace xrn::util::literal {

///////////////////////////////////////////////////////////////////////////
/// \brief Alias for the ::xrn::util::BasicTime::createAsSeconds()
///
/// \param amount Value contructed from the amount of seconds
///
/// \see ::xrn::util::BasicTime::createAsSeconds()
///
///////////////////////////////////////////////////////////////////////////
[[ nodiscard ]] constexpr auto operator""_s(
    long double amount
) -> ::xrn::Time;

///////////////////////////////////////////////////////////////////////////
/// \brief Alias for the ::xrn::util::BasicTime::createAsSeconds()
///
/// \param amount Value contructed from the amount of seconds
///
/// \see ::xrn::util::BasicTime::createAsSeconds()
///
///////////////////////////////////////////////////////////////////////////
[[ nodiscard ]] constexpr auto operator""_s(
    long long unsigned amount
) -> ::xrn::Time;

///////////////////////////////////////////////////////////////////////////
/// \brief Alias for the ::xrn::util::BasicTime::createAsMilliseconds()
///
/// \param amount Value contructed from the amount of milliseconds
///
/// \see ::xrn::util::BasicTime::createAsMilliseconds()
///
///////////////////////////////////////////////////////////////////////////
[[ nodiscard ]] constexpr auto operator""_ms(
    long double amount
) -> ::xrn::Time;

///////////////////////////////////////////////////////////////////////////
/// \brief Alias for the ::xrn::util::BasicTime::createAsMilliseconds()
///
/// \param amount Value contructed from the amount of milliseconds
///
/// \see ::xrn::util::BasicTime::createAsMilliseconds()
///
///////////////////////////////////////////////////////////////////////////
[[ nodiscard ]] constexpr auto operator""_ms(
    long long unsigned amount
) -> ::xrn::Time;

///////////////////////////////////////////////////////////////////////////
/// \brief Alias for the ::xrn::util::BasicTime::createAsMicroseconds()
///
/// \param amount Value contructed from the amount of microseconds
///
/// \see ::xrn::util::BasicTime::createAsMicroseconds()
///
///////////////////////////////////////////////////////////////////////////
[[ nodiscard ]] constexpr auto operator""_us(
    long double amount
) -> ::xrn::Time;

///////////////////////////////////////////////////////////////////////////
/// \brief Alias for the ::xrn::util::BasicTime::createAsMicroseconds()
///
/// \param amount Value contructed from the amount of microseconds
///
/// \see ::xrn::util::BasicTime::createAsMicroseconds()
///
///////////////////////////////////////////////////////////////////////////
[[ nodiscard ]] constexpr auto operator""_us(
    long long unsigned amount
) -> ::xrn::Time;

///////////////////////////////////////////////////////////////////////////
/// \brief Alias for the ::xrn::util::BasicTime::createAsNanoseconds()
///
/// \param amount Value contructed from the amount of nanoseconds
///
/// \see ::xrn::util::BasicTime::createAsNanoseconds()
///
///////////////////////////////////////////////////////////////////////////
[[ nodiscard ]] constexpr auto operator""_ns(
    long double amount
) -> ::xrn::Time;

///////////////////////////////////////////////////////////////////////////
/// \brief Alias for the ::xrn::util::BasicTime::createAsNanoseconds()
///
/// \param amount Value contructed from the amount of nanoseconds
///
/// \see ::xrn::util::BasicTime::createAsNanoseconds()
///
///////////////////////////////////////////////////////////////////////////
[[ nodiscard ]] constexpr auto operator""_ns(
    long long unsigned amount
) -> ::xrn::Time;

} // namespace xrn::util::literal



///////////////////////////////////////////////////////////////////////////
// Header-implimentation
///////////////////////////////////////////////////////////////////////////
#include <xrn/Util/Time.impl.hpp>
