// Copyright 2026 Netxonica. All Rights Reserved.
#if alice_major >= 0 and alice_middle >= 0 and alice_minor >= 1
#ifdef alice_windows
#include <Windows.h>
#endif
#include "Trait/RvalueReference.hpp"

using Alice::Trait::RvalueReference;

// --- Basic rvalue references satisfy the concept ---
static_assert(RvalueReference<int&&>, "int&&");
static_assert(RvalueReference<float&&>, "float&&");
static_assert(RvalueReference<double&&>, "double&&");
static_assert(RvalueReference<char&&>, "char&&");
static_assert(RvalueReference<bool&&>, "bool&&");

// --- Non-reference types do not satisfy the concept ---
static_assert(not RvalueReference<int>, "int");
static_assert(not RvalueReference<float>, "float");
static_assert(not RvalueReference<double>, "double");
static_assert(not RvalueReference<char>, "char");
static_assert(not RvalueReference<bool>, "bool");
static_assert(not RvalueReference<void>, "void");

// --- Lvalue references do not satisfy the concept ---
static_assert(not RvalueReference<int&>, "int&");
static_assert(not RvalueReference<float&>, "float&");
static_assert(not RvalueReference<double&>, "double&");
static_assert(not RvalueReference<const int&>, "const int&");

// --- cv-qualified rvalue references satisfy the concept ---
static_assert(RvalueReference<const int&&>, "const int&&");
static_assert(RvalueReference<volatile int&&>, "volatile int&&");
static_assert(RvalueReference<const volatile int&&>, "const volatile int&&");

// --- cv-qualified non-references do not satisfy the concept ---
static_assert(not RvalueReference<const int>, "const int");
static_assert(not RvalueReference<volatile int>, "volatile int");
static_assert(not RvalueReference<const volatile int>, "const volatile int");

// --- Pointer types ---
static_assert(not RvalueReference<int*>, "int*");
static_assert(not RvalueReference<const int*>, "const int*");
static_assert(not RvalueReference<int*&>, "int*&");
static_assert(RvalueReference<int*&&>, "int*&&");

// --- Array types ---
static_assert(not RvalueReference<int[4]>, "int[4]");
static_assert(not RvalueReference<int(&)[4]>, "int(&)[4]");
static_assert(RvalueReference<int(&&)[4]>, "int(&&)[4]");

// --- Function types ---
static_assert(not RvalueReference<int(int)>, "fn type");
static_assert(not RvalueReference<int(&)(int)>, "fn lvalue ref");
static_assert(RvalueReference<int(&&)(int)>, "fn rvalue ref");

// --- User-defined types ---
struct Foo{};

static_assert(not RvalueReference<Foo>, "Foo");
static_assert(not RvalueReference<Foo&>, "Foo&");
static_assert(RvalueReference<Foo&&>, "Foo&&");
static_assert(not RvalueReference<const Foo&>, "const Foo&");
static_assert(RvalueReference<const Foo&&>, "const Foo&&");

// --- Concept usable as a constraint ---
[[nodiscard]] constexpr auto constrained(auto&& x) noexcept -> bool requires RvalueReference<
decltype(x)>
{
    return true;
}

struct Incomplete;

[[nodiscard]] auto alice_test() noexcept -> bool
{
    static_assert(constrained(0), "constraint: int&&");
    static_assert(constrained(0.f), "constraint: float&&");
    static_assert(constrained(Foo{}), "constraint: Foo&&");

    return not RvalueReference<Incomplete>;
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