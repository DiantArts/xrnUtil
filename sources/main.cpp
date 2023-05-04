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

/*
 * generic helper macros
 */
#define CALL(macro, arguments) macro arguments
#define STR(...) STR_(__VA_ARGS__)
#define STR_(...) # __VA_ARGS__

/*
 * dumps a macro and its expansion to stdout
 * the second argument is optional and specifies the number of
 * arguments that macro takes: 0 means macro takes zero arguments
 * no second argument means macro is not function-like
 */
#define DUMP_MACRO(macro, ...) \
    do { \
        puts ( \
            "'" \
            # macro STR(DUMP_MACRO_ARGS_ ## __VA_ARGS__) \
            "' expands to '" \
            STR(CALL(macro, DUMP_MACRO_ARGS_ ## __VA_ARGS__)) \
            "'" \
        ); \
    } while (0)
/* helpers for DUMP_MACRO, add more if required */
#define DUMP_MACRO_ARGS_
#define DUMP_MACRO_ARGS_0 ()
#define DUMP_MACRO_ARGS_1 (<1>)
#define DUMP_MACRO_ARGS_2 (<1>, <2>)
#define DUMP_MACRO_ARGS_3 (<1>, <2>, <3>)

template <
    typename T
    , typename U
    , bool hasChangedFlag = false
> class BasicType {
public:
    void test();
};

#ifndef XRN_VA_ARGS
    #define XRN_VA_ARGS(...) , ##__VA_ARGS__
#endif // XRN_VA_ARGS

#define USING_THIS_BASIC_TYPE(argType, argParentType, ...) \
    using BasicType<argType, argParentType, ##__VA_ARGS__>

#define EXPOSE_BASIC_TYPE_METHODS(argType, argParentType, ...) \
    USING_THIS_BASIC_TYPE(argType, argParentType, ##__VA_ARGS__)::test;

template <
    typename T
    , bool hasChangedFlag = false
> class Vector3
    : public BasicType<float, T, hasChangedFlag>
{
public:
    void test2();
};

#define USING_THIS_VECTOR3(argParentType, ...) \
    using Vector3<argParentType, ##__VA_ARGS__>

#define EXPOSE_VECTOR3_METHODS(argParentType, ...) \
    EXPOSE_BASIC_TYPE_METHODS(float, argParentType, ##__VA_ARGS__); \
    USING_THIS_VECTOR3(argParentType, ##__VA_ARGS__)::test2;



class Class
    : public Vector3<float>
{
    EXPOSE_VECTOR3_METHODS(float);
    // EXPOSE_BASIC_TYPE_METHODS(float, float);
};



/*
 * macros to be used in examples for DUMP_MACRO
 */
#define EXAMPLE ( EXPOSE_VECTOR3_METHODS(float, true) )


///////////////////////////////////////////////////////////////////////////
auto main()
    -> int
{
    /* examples */
    DUMP_MACRO(EXAMPLE);
}
