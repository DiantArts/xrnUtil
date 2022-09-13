#pragma once

#define ENABLE_IF_CONST(Type) ::std::enable_if_t< \
        ::std::is_const_v<::std::remove_reference_t<::std::remove_pointer_t<Type>>> \
    >
#define ENABLE_IF_NOT_CONST(Type) ::std::enable_if_t< \
        !::std::is_const_v<::std::remove_reference_t<::std::remove_pointer_t<Type>>> \
    >

namespace xrn::util {

///////////////////////////////////////////////////////////////////////////
/// \brief Optional reference
/// \ingroup util
///
/// \include OptionalReference.hpp <xrn/Util/OptionalReference.hpp>
///
/// Usage example:
/// \code
/// \endcode
///
///////////////////////////////////////////////////////////////////////////
template <
    typename T,
    typename = void
> class OptionalReference;

///////////////////////////////////////////////////////////////////////////
/// \brief Optional reference
/// \ingroup util
///
/// \include OptionalReference.hpp <xrn/Util/OptionalReference.hpp>
///
/// Usage example:
/// \code
/// \endcode
///
///////////////////////////////////////////////////////////////////////////
template <
    typename T
> class OptionalReference<T, ENABLE_IF_NOT_CONST(T)> {

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
    /// Constructs an empty reference
    ///
    ///////////////////////////////////////////////////////////////////////////
    OptionalReference() noexcept;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Constructor from reference
    ///
    ///////////////////////////////////////////////////////////////////////////
    OptionalReference(
        T& value
    ) noexcept;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Constructor from pointer
    ///
    ///////////////////////////////////////////////////////////////////////////
    OptionalReference(
        T* value
    ) noexcept;



    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Comparison
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Compares with any type if comparable with the internal type
    ///
    /// Compares the internal value of type Type
    ///
    /// \throws Throws if lhs is empty
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] constexpr auto operator<=>(
        const auto& rhs
    ) const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Compares with any type if comparable with the internal type
    ///
    /// Compares the internal value of type Type
    ///
    /// \throws Throws if lhs or rhs is empty
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] constexpr auto operator<=>(
        const auto* rhs
    ) const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Checks if the value contains anything
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] constexpr auto isEmpty() const
        -> bool;



    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Getters
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Gets the value
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto get()
        -> T&;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Gets the value
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto get() const
        -> const T&;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Gets the value
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] operator T&();

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Gets the internal pointer
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] operator T*() noexcept;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Gets the value
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] operator const T&() const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Gets the internal pointer
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] operator const T*() const noexcept;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Gets the value
    ///
    /// \throws If is empty
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto unsafeGet() noexcept
        -> T&;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Gets the value
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto unsafeGet() const noexcept
        -> const T&;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Gets the value
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto operator->() noexcept
        -> T*;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Gets the value
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto operator->() const noexcept
        -> const T*;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Gets the value
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto operator*() noexcept
        -> T&;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Gets the value
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto operator*() const noexcept
        -> const T&;



    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Setters
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Sets the value
    ///
    ///////////////////////////////////////////////////////////////////////////
    void set(
        T& value
    ) noexcept;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Sets the value
    ///
    /// nullptr is the same as clear()
    ///
    ///////////////////////////////////////////////////////////////////////////
    void set(
        T* value
    ) noexcept;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Sets the value
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto operator=(
        T& value
    ) noexcept
        -> T&;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Sets the value
    ///
    /// nullptr is the same as clear()
    ///
    ///////////////////////////////////////////////////////////////////////////
    auto operator=(
        T* value
    ) noexcept
        -> T&;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Clears the value
    ///
    ///////////////////////////////////////////////////////////////////////////
    void clear() noexcept;



private:

    T* m_value;

};

///////////////////////////////////////////////////////////////////////////
/// \brief Const optional reference
/// \ingroup util
///
/// \include OptionalReference.hpp <xrn/Util/OptionalReference.hpp>
///
/// Usage example:
/// \code
/// \endcode
///
///////////////////////////////////////////////////////////////////////////
template <
    typename T
> class OptionalReference<T, ENABLE_IF_CONST(T)> {

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
    /// Constructs an empty reference
    ///
    ///////////////////////////////////////////////////////////////////////////
    OptionalReference() noexcept;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Constructor from reference
    ///
    ///////////////////////////////////////////////////////////////////////////
    OptionalReference(
        T& value
    ) noexcept;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Constructor from pointer
    ///
    ///////////////////////////////////////////////////////////////////////////
    OptionalReference(
        T* value
    ) noexcept;



    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Comparison
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Compares with any type if comparable with the internal type
    ///
    /// Compares the internal value of type Type
    ///
    /// \throws Throws if lhs is empty
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] constexpr auto operator<=>(
        const auto& rhs
    ) const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Compares with any type if comparable with the internal type
    ///
    /// Compares the internal value of type Type
    ///
    /// \throws Throws if lhs or rhs is empty
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] constexpr auto operator<=>(
        const auto* rhs
    ) const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Checks if the value contains anything
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] constexpr auto isEmpty() const
        -> bool;



    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    // Getters
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Gets the value
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto get() const
        -> const T&;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Gets the value
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto unsafeGet() const noexcept
        -> const T&;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Gets the value
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] operator const T&() const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Gets the internal pointer
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] operator const T*() const noexcept;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Gets the value
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto operator->() const noexcept
        -> const T*;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Gets the value
    ///
    ///////////////////////////////////////////////////////////////////////////
    [[ nodiscard ]] auto operator*() const noexcept
        -> const T&;



private:

    T* m_value;

};

} // namespace xrn::util



///////////////////////////////////////////////////////////////////////////
// ostream
///////////////////////////////////////////////////////////////////////////
template <
    typename T
> auto operator<<(
    ::std::ostream& os,
    const ::xrn::util::OptionalReference<T, ENABLE_IF_NOT_CONST(T)>& that
) -> ::std::ostream&
{
    os << that.get();
    return os;
}

template <
    typename T
> auto operator<<(
    ::std::ostream& os,
    const ::xrn::util::OptionalReference<T, ENABLE_IF_CONST(T)>& that
) -> ::std::ostream&
{
    os << that.get();
    return os;
}



///////////////////////////////////////////////////////////////////////////
// Type aliases
///////////////////////////////////////////////////////////////////////////
namespace xrn::util { template <typename T> using OptRef = ::xrn::util::OptionalReference<T>; }
namespace xrn { template <typename T> using OptionalReference = ::xrn::util::OptionalReference<T>; }
namespace xrn { template <typename T> using OptRef = ::xrn::util::OptionalReference<T>; }



///////////////////////////////////////////////////////////////////////////
// Header-implimentation
///////////////////////////////////////////////////////////////////////////
#include <xrn/Util/OptionalReference.impl.hpp>
#include <xrn/Util/ConstOptionalReference.impl.hpp>

#undef ENABLE_IF_CONST
#undef ENABLE_IF_NOT_CONST
