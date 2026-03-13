// Copyright 2026 Netxonica. All Rights Reserved.
#if alice_major >= 0 and alice_middle >= 0 and alice_minor >= 1
#ifdef alice_windows
#include <Windows.h>
#endif
#include "Trait/Same.hpp"

using Alice::Trait::Same;

// --- Identical types satisfy the concept ---
static_assert(Same<int, int>, "int == int");
static_assert(Same<float, float>, "float == float");
static_assert(Same<double, double>, "double == double");
static_assert(Same<char, char>, "char == char");
static_assert(Same<bool, bool>, "bool == bool");
static_assert(Same<void, void>, "void == void");

// --- Distinct types do not satisfy the concept ---
static_assert(not Same<int, float>, "int != float");
static_assert(not Same<int, double>, "int != double");
static_assert(not Same<int, char>, "int != char");
static_assert(not Same<int, bool>, "int != bool");
static_assert(not Same<float, double>, "float != double");

// --- cv-qualification is significant ---
static_assert(Same<const int, const int>, "const int == const int");
static_assert(Same<volatile int, volatile int>, "volatile int == volatile int");
static_assert(Same<const volatile int, const volatile int>, "cv int == cv int");
static_assert(not Same<int, const int>, "int != const int");
static_assert(not Same<int, volatile int>, "int != volatile int");
static_assert(not Same<const int, volatile int>, "const int != volatile int");
static_assert(not Same<const int, const volatile int>, "const int != const volatile int");

// --- Reference category is significant ---
static_assert(Same<int&, int&>, "int& == int&");
static_assert(Same<int&&, int&&>, "int&& == int&&");
static_assert(not Same<int, int&>, "int != int&");
static_assert(not Same<int, int&&>, "int != int&&");
static_assert(not Same<int&, int&&>, "int& != int&&");
static_assert(not Same<const int&, int&>, "const int& != int&");

// --- Pointer distinctions are significant ---
static_assert(Same<int*, int*>, "int* == int*");
static_assert(Same<const int*, const int*>, "const int* == const int*");
static_assert(not Same<int*, const int*>, "int* != const int*");
static_assert(not Same<int*, int**>, "int* != int**");
static_assert(not Same<int*, int&>, "int* != int&");

// --- Array types ---
static_assert(Same<int[], int[]>, "int[] == int[]");
static_assert(Same<int[4], int[4]>, "int[4] == int[4]");
static_assert(not Same<int[4], int[5]>, "int[4] != int[5]");
static_assert(not Same<int[4], int[]>, "int[4] != int[]");
static_assert(not Same<int[4], int*>, "int[4] != int* (no decay)");

// --- Function types ---
static_assert(Same<int(int), int(int)>, "fn == fn");
static_assert(not Same<int(int), int(float)>, "fn(int) != fn(float)");
static_assert(not Same<int(int), void(int)>, "int(int) != void(int)");

// --- User-defined types ---
struct Foo{};

struct Bar{};

static_assert(Same<Foo, Foo>, "Foo == Foo");
static_assert(not Same<Foo, Bar>, "Foo != Bar");
static_assert(not Same<Foo, const Foo>, "Foo != const Foo");
static_assert(not Same<Foo, Foo&>, "Foo != Foo&");

// --- Concept usable as a constraint ---
template<class A, class B> requires Same<A, B> [[nodiscard]] constexpr auto constrained(A, B)
noexcept -> bool
{
    return true;
}

static_assert(constrained(0, 0), "constraint: int, int");
static_assert(constrained(0.f, 0.f), "constraint: float, float");

struct Incomplete;

[[nodiscard]] auto alice_test() noexcept -> bool
{
    return Same<Incomplete, Incomplete>;
}

#ifdef alice_windows
int WINAPI wWinMain(HINSTANCE, HINSTANCE, PWSTR, int)
#else
int main()
#endif
{
    return not alice_test();
}

#endif