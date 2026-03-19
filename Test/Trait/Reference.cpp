// Copyright 2026 Netxonica. All Rights Reserved.
#if alice_major >= 0 and alice_middle >= 0 and alice_minor >= 1
#ifdef alice_windows
#include <Windows.h>
#endif
#include "Trait/Reference.hpp"

using Alice::Trait::Reference;

// --- Lvalue references satisfy the concept ---
static_assert(Reference<int&>, "int&");
static_assert(Reference<float&>, "float&");
static_assert(Reference<double&>, "double&");
static_assert(Reference<char&>, "char&");
static_assert(Reference<bool&>, "bool&");

// --- Rvalue references satisfy the concept ---
static_assert(Reference<int&&>, "int&&");
static_assert(Reference<float&&>, "float&&");
static_assert(Reference<double&&>, "double&&");
static_assert(Reference<char&&>, "char&&");
static_assert(Reference<bool&&>, "bool&&");

// --- Non-reference types do not satisfy the concept ---
static_assert(not Reference<int>, "int");
static_assert(not Reference<float>, "float");
static_assert(not Reference<double>, "double");
static_assert(not Reference<char>, "char");
static_assert(not Reference<bool>, "bool");
static_assert(not Reference<void>, "void");

// --- cv-qualified lvalue references satisfy the concept ---
static_assert(Reference<const int&>, "const int&");
static_assert(Reference<volatile int&>, "volatile int&");
static_assert(Reference<const volatile int&>, "const volatile int&");

// --- cv-qualified rvalue references satisfy the concept ---
static_assert(Reference<const int&&>, "const int&&");
static_assert(Reference<volatile int&&>, "volatile int&&");
static_assert(Reference<const volatile int&&>, "const volatile int&&");

// --- cv-qualified non-references do not satisfy the concept ---
static_assert(not Reference<const int>, "const int");
static_assert(not Reference<volatile int>, "volatile int");
static_assert(not Reference<const volatile int>, "const volatile int");

// --- Pointer types ---
static_assert(not Reference<int*>, "int*");
static_assert(not Reference<const int*>, "const int*");
static_assert(Reference<int*&>, "int*&");
static_assert(Reference<int*&&>, "int*&&");

// --- Array types ---
static_assert(not Reference<int[4]>, "int[4]");
static_assert(Reference<int(&)[4]>, "int(&)[4]");
static_assert(Reference<int(&&)[4]>, "int(&&)[4]");

// --- Function types ---
static_assert(not Reference<int(int)>, "fn type");
static_assert(Reference<int(&)(int)>, "fn lvalue ref");
static_assert(Reference<int(&&)(int)>, "fn rvalue ref");

// --- User-defined types ---
struct Foo{};

static_assert(not Reference<Foo>, "Foo");
static_assert(Reference<Foo&>, "Foo&");
static_assert(Reference<Foo&&>, "Foo&&");
static_assert(Reference<const Foo&>, "const Foo&");
static_assert(Reference<const Foo&&>, "const Foo&&");

// --- Concept usable as a constraint ---
[[nodiscard]] constexpr auto constrained(auto&& x) noexcept -> bool requires Reference<decltype(x)>
{
    return true;
}

struct Incomplete;

[[nodiscard]] auto alice_test() noexcept -> bool
{
    static_assert(constrained(0), "constraint: int&&");
    static_assert(constrained(0.f), "constraint: float&&");
    static_assert(constrained(Foo{}), "constraint: Foo&&");

    return not Reference<Incomplete>;
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