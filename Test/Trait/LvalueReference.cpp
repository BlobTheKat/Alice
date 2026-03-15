// Copyright 2026 Netxonica. All Rights Reserved.
#if alice_major >= 0 and alice_middle >= 0 and alice_minor >= 1
#ifdef alice_windows
#include <Windows.h>
#endif
#include "Trait/LvalueReference.hpp"

using Alice::Trait::LvalueReference;

// --- Basic lvalue references satisfy the concept ---
static_assert(LvalueReference<int&>, "int&");
static_assert(LvalueReference<float&>, "float&");
static_assert(LvalueReference<double&>, "double&");
static_assert(LvalueReference<char&>, "char&");
static_assert(LvalueReference<bool&>, "bool&");

// --- Non-reference types do not satisfy the concept ---
static_assert(not LvalueReference<int>, "int");
static_assert(not LvalueReference<float>, "float");
static_assert(not LvalueReference<double>, "double");
static_assert(not LvalueReference<char>, "char");
static_assert(not LvalueReference<bool>, "bool");
static_assert(not LvalueReference<void>, "void");

// --- Rvalue references do not satisfy the concept ---
static_assert(not LvalueReference<int&&>, "int&&");
static_assert(not LvalueReference<float&&>, "float&&");
static_assert(not LvalueReference<double&&>, "double&&");
static_assert(not LvalueReference<const int&&>, "const int&&");

// --- cv-qualified lvalue references satisfy the concept ---
static_assert(LvalueReference<const int&>, "const int&");
static_assert(LvalueReference<volatile int&>, "volatile int&");
static_assert(LvalueReference<const volatile int&>, "const volatile int&");

// --- cv-qualified non-references do not satisfy the concept ---
static_assert(not LvalueReference<const int>, "const int");
static_assert(not LvalueReference<volatile int>, "volatile int");
static_assert(not LvalueReference<const volatile int>, "const volatile int");

// --- Pointer types ---
static_assert(not LvalueReference<int*>, "int*");
static_assert(not LvalueReference<const int*>, "const int*");
static_assert(LvalueReference<int*&>, "int*&");
static_assert(not LvalueReference<int*&&>, "int*&&");

// --- Array types ---
static_assert(not LvalueReference<int[4]>, "int[4]");
static_assert(LvalueReference<int(&)[4]>, "int(&)[4]");
static_assert(not LvalueReference<int(&&)[4]>, "int(&&)[4]");

// --- Function types ---
static_assert(not LvalueReference<int(int)>, "fn type");
static_assert(LvalueReference<int(&)(int)>, "fn lvalue ref");
static_assert(not LvalueReference<int(&&)(int)>, "fn rvalue ref");

// --- User-defined types ---
struct Foo{};

static_assert(not LvalueReference<Foo>, "Foo");
static_assert(LvalueReference<Foo&>, "Foo&");
static_assert(not LvalueReference<Foo&&>, "Foo&&");
static_assert(LvalueReference<const Foo&>, "const Foo&");
static_assert(not LvalueReference<const Foo&&>, "const Foo&&");

// --- Concept usable as a constraint ---
[[nodiscard]] constexpr auto constrained(auto& x) noexcept -> bool requires LvalueReference<
decltype(x)>
{
    return true;
}

struct Incomplete;

[[nodiscard]] auto alice_test() noexcept -> bool
{
    int x = 0;
    int& lref = x;
    static_assert(constrained(lref), "constraint: int&");

    int arr[4] = {};
    int (&aref)[4] = arr;
    static_assert(constrained(aref), "constraint: int(&)[4]");

    return not LvalueReference<Incomplete>;
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