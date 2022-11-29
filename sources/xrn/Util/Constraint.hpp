#pragma once

#include <xrn/Util/Id.hpp>
#include <xrn/Util/Time.hpp>
#include <xrn/Util/Clock.hpp>

namespace xrn::util::constraint {

///////////////////////////////////////////////////////////////////////////
/// \brief Checks whether the Type given as template parameter is an
///        ::xrn::util::Id of the default type
///
/// The comparison ignores cv-qualifiers and references (compares the type
/// referenced).
/// A ::xrn::util::Id::Type is concidered as a ::xrn::util::Id.
///
/// \tparam Type to check
///
/// \return True if the Type given as template parameter is an
///         ::xrn::util::BasicForwardId or the type contained. False
///         otherwise
///
/// \see ::xrn::util::BasicForwardId
///
///////////////////////////////////////////////////////////////////////////
template <
    typename Type
> concept isId =
    ::std::same_as<
        ::std::remove_cvref_t<::std::remove_pointer_t<::xrn::Id>>,
        ::std::remove_cvref_t<::std::remove_pointer_t<Type>>
    > || ::std::same_as<
        ::std::remove_cvref_t<::std::remove_pointer_t<::xrn::Id::Type>>,
        ::std::remove_cvref_t<::std::remove_pointer_t<Type>>
    >;

///////////////////////////////////////////////////////////////////////////
/// \brief Checks whether the Type given as template parameter is an
///        ::xrn::util::Time of the default type
///
/// The comparison ignores cv-qualifiers and references (compares the type
/// referenced).
/// A ::xrn::util::Time::Type is concidered as a ::xrn::util::Time.
///
/// \tparam Type to check
///
/// \return True if the Type given as template parameter is an
///         ::xrn::util::BasicTime or the type contained. False
///         otherwise
///
/// \see ::xrn::util::BasicTime
///
///////////////////////////////////////////////////////////////////////////
template <
    typename Type
> concept isTime =
    ::std::same_as<
        ::std::remove_cvref_t<::std::remove_pointer_t<::xrn::Time>>,
        ::std::remove_cvref_t<::std::remove_pointer_t<Type>>
    > || ::std::same_as<
        ::std::remove_cvref_t<::std::remove_pointer_t<::xrn::Time::Type>>,
        ::std::remove_cvref_t<::std::remove_pointer_t<Type>>
    >;

///////////////////////////////////////////////////////////////////////////
/// \brief Checks whether the Type given as template parameter is an
///        ::xrn::util::Clock of the default type ::xrn::util::BasicTime
///
/// The comparison ignores cv-qualifiers and references (compares the type
/// referenced).
///
/// \tparam Type to check
///
/// \return True if the Type given as template parameter is an
///         ::xrn::util::Clock. False otherwise
///
/// \see ::xrn::util::BasicClock, ::xrn::util::BasicTime
///
///////////////////////////////////////////////////////////////////////////
template <
    typename Type
> concept isClock =
    ::std::same_as<
        ::std::remove_cvref_t<::std::remove_pointer_t<::xrn::Clock>>,
        ::std::remove_cvref_t<::std::remove_pointer_t<Type>>
    >;

} // namespace xrn::ecs::detail::constraint
