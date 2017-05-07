// Copyright (c) 2017 Martin Moene
//
// https://github.com/martinmoene/ring-span-lite
//
// This code is licensed under the MIT License (MIT).

#include "ring-span-lite.t.hpp"

#define nsrs_PRESENT( x ) \
    std::cout << #x << ": " << x << "\n"

#define nsrs_ABSENT( x ) \
    std::cout << #x << ": (undefined)\n"

lest::tests & specification()
{
    static lest::tests tests;
    return tests;
}

CASE( "__cplusplus" "[.stdc++]" )
{
    nsrs_PRESENT( __cplusplus );
}

CASE( "ring-span-lite version" "[.version]" )
{
    nsrs_PRESENT( ring_span_lite_VERSION );
}

CASE( "compiler version" "[.compiler]" )
{
#if nsrs_COMPILER_GNUC_VERSION
    nsrs_PRESENT( nsrs_COMPILER_GNUC_VERSION );
#else
    nsrs_ABSENT(  nsrs_COMPILER_GNUC_VERSION );
#endif

#if nsrs_COMPILER_MSVC_VERSION
    nsrs_PRESENT( nsrs_COMPILER_MSVC_VERSION );
#else
    nsrs_ABSENT(  nsrs_COMPILER_MSVC_VERSION );
#endif
}

CASE( "Presence of C++ language features" "[.stdlanguage]" )
{
#if nsrs_HAVE_DEFAULT_FUNCTION_TEMPLATE_ARG
    nsrs_PRESENT( nsrs_HAVE_DEFAULT_FUNCTION_TEMPLATE_ARG );
#else
    nsrs_ABSENT(  nsrs_HAVE_DEFAULT_FUNCTION_TEMPLATE_ARG );
#endif

#if nsrs_HAVE_CONSTEXPR_11
    nsrs_PRESENT( nsrs_HAVE_CONSTEXPR_11 );
#else
    nsrs_ABSENT(  nsrs_HAVE_CONSTEXPR_11 );
#endif

#if nsrs_HAVE_CONSTEXPR_14
    nsrs_PRESENT( nsrs_HAVE_CONSTEXPR_14 );
#else
    nsrs_ABSENT(  nsrs_HAVE_CONSTEXPR_14 );
#endif

#if nsrs_HAVE_ENUM_CLASS
    nsrs_PRESENT( nsrs_HAVE_ENUM_CLASS );
#else
    nsrs_ABSENT(  nsrs_HAVE_ENUM_CLASS );
#endif

#if nsrs_HAVE_ENUM_CLASS_CONSTRUCTION_FROM_UNDERLYING_TYPE
    nsrs_PRESENT( nsrs_HAVE_ENUM_CLASS_CONSTRUCTION_FROM_UNDERLYING_TYPE );
#else
    nsrs_ABSENT(  nsrs_HAVE_ENUM_CLASS_CONSTRUCTION_FROM_UNDERLYING_TYPE );
#endif

#if nsrs_HAVE_EXPLICIT_CONVERSION
    nsrs_PRESENT( nsrs_HAVE_EXPLICIT_CONVERSION );
#else
    nsrs_ABSENT(  nsrs_HAVE_EXPLICIT_CONVERSION );
#endif

#if nsrs_HAVE_NOEXCEPT
    nsrs_PRESENT( nsrs_HAVE_NOEXCEPT );
#else
    nsrs_ABSENT(  nsrs_HAVE_NOEXCEPT );
#endif
}

CASE( "Presence of C++ library features" "[.stdlibrary]" )
{
#if nsrs_HAVE_TYPE_TRAITS
    nsrs_PRESENT( nsrs_HAVE_TYPE_TRAITS );
#else
    nsrs_ABSENT(  nsrs_HAVE_TYPE_TRAITS );
#endif
}

int main( int argc, char * argv[] )
{
    return lest::run( specification(), argc, argv );
}

#if 0
g++            -I../include/nonstd -o ring-span-lite.t.exe ring-span-lite.t.cpp ring-span.t.cpp && ring-span-lite.t.exe --pass
g++ -std=c++98 -I../include/nonstd -o ring-span-lite.t.exe ring-span-lite.t.cpp ring-span.t.cpp && ring-span-lite.t.exe --pass
g++ -std=c++03 -I../include/nonstd -o ring-span-lite.t.exe ring-span-lite.t.cpp ring-span.t.cpp && ring-span-lite.t.exe --pass
g++ -std=c++0x -I../include/nonstd -o ring-span-lite.t.exe ring-span-lite.t.cpp ring-span.t.cpp && ring-span-lite.t.exe --pass
g++ -std=c++11 -I../include/nonstd -o ring-span-lite.t.exe ring-span-lite.t.cpp ring-span.t.cpp && ring-span-lite.t.exe --pass
g++ -std=c++14 -I../include/nonstd -o ring-span-lite.t.exe ring-span-lite.t.cpp ring-span.t.cpp && ring-span-lite.t.exe --pass
g++ -std=c++17 -I../include/nonstd -o ring-span-lite.t.exe ring-span-lite.t.cpp ring-span.t.cpp && ring-span-lite.t.exe --pass

cl -EHsc -I../include/nonstd ring-span-lite.t.cpp ring-span.t.cpp && ring-span-lite.t.exe --pass
#endif

// end of file