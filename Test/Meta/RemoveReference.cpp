// Copyright 2026 Netxonica. All Rights Reserved.
#if alice_major >= 0 and alice_middle >= 0 and alice_minor >= 1
#ifdef alice_windows
#include <Windows.h>
#endif
#include "Trait/Same.hpp"
#include "Meta/RemoveReference.hpp"

using Alice::Trait::Same;
using Alice::Meta::RemoveReference;

// --- Non-reference types are unchanged ---
static_assert(Same<RemoveReference<int>, int>, "int -> int");
static_assert(Same<RemoveReference<float>, float>, "float -> float");
static_assert(Same<RemoveReference<double>, double>, "double -> double");
static_assert(Same<RemoveReference<char>, char>, "char -> char");
static_assert(Same<RemoveReference<bool>, bool>, "bool -> bool");
static_assert(Same<RemoveReference<void>, void>, "void -> void");

// --- Lvalue reference is stripped ---
static_assert(Same<RemoveReference<int&>, int>, "int& -> int");
static_assert(Same<RemoveReference<float&>, float>, "float& -> float");
static_assert(Same<RemoveReference<double&>, double>, "double& -> double");
static_assert(Same<RemoveReference<char&>, char>, "char& -> char");
static_assert(Same<RemoveReference<bool&>, bool>, "bool& -> bool");

// --- Rvalue reference is stripped ---
static_assert(Same<RemoveReference<int&&>, int>, "int&& -> int");
static_assert(Same<RemoveReference<float&&>, float>, "float&& -> float");
static_assert(Same<RemoveReference<double&&>, double>, "double&& -> double");
static_assert(Same<RemoveReference<char&&>, char>, "char&& -> char");
static_assert(Same<RemoveReference<bool&&>, bool>, "bool&& -> bool");

// --- cv-qualification is preserved ---
static_assert(Same<RemoveReference<const int>, const int>, "const int -> const int");
static_assert(Same<RemoveReference<volatile int>, volatile int>, "volatile int -> volatile int");
static_assert(Same<RemoveReference<const volatile int>, const volatile int>, "cv int -> cv int");
static_assert(Same<RemoveReference<const int&>, const int>, "const int& -> const int");
static_assert(Same<RemoveReference<volatile int&>, volatile int>, "volatile int& -> volatile int");
static_assert(Same<RemoveReference<const volatile int&>, const volatile int>, "cv int& -> cv int");
static_assert(Same<RemoveReference<const int&&>, const int>, "const int&& -> const int");
static_assert(Same<RemoveReference<volatile int&&>, volatile int>, "volatile int&& -> volatile int"
);
static_assert(Same<RemoveReference<const volatile int&&>, const volatile int>, "cv int&& -> cv int"
);

// --- Pointer types are unchanged ---
static_assert(Same<RemoveReference<int*>, int*>, "int* -> int*");
static_assert(Same<RemoveReference<const int*>, const int*>, "const int* -> const int*");
static_assert(Same<RemoveReference<int**>, int**>, "int** -> int**");
static_assert(Same<RemoveReference<int*&>, int*>, "int*& -> int*");
static_assert(Same<RemoveReference<int*&&>, int*>, "int*&& -> int*");

// --- Array types ---
static_assert(Same<RemoveReference<int[4]>, int[4]>, "int[4] -> int[4]");
static_assert(Same<RemoveReference<int(&)[4]>, int[4]>, "int(&)[4] -> int[4]");
static_assert(Same<RemoveReference<int(&&)[4]>, int[4]>, "int(&&)[4] -> int[4]");
static_assert(Same<RemoveReference<int(&)[]>, int[]>, "int(&)[] -> int[]");
static_assert(Same<RemoveReference<int(&&)[]>, int[]>, "int(&&)[] -> int[]");

// --- Function types ---
static_assert(Same<RemoveReference<int(int)>, int(int)>, "fn -> fn");
static_assert(Same<RemoveReference<int(&)(int)>, int(int)>, "fn lvalue ref -> fn");
static_assert(Same<RemoveReference<int(&&)(int)>, int(int)>, "fn rvalue ref -> fn");

// --- User-defined types ---
struct Foo{};

static_assert(Same<RemoveReference<Foo>, Foo>, "Foo -> Foo");
static_assert(Same<RemoveReference<Foo&>, Foo>, "Foo& -> Foo");
static_assert(Same<RemoveReference<Foo&&>, Foo>, "Foo&& -> Foo");
static_assert(Same<RemoveReference<const Foo&>, const Foo>, "const Foo& -> const Foo");
static_assert(Same<RemoveReference<const Foo&&>, const Foo>, "const Foo&& -> const Foo");

[[nodiscard]] auto function(const int&&) noexcept -> bool
{
    return true;
}

[[nodiscard]] auto function(const int&) noexcept -> bool
{
    return false;
}

struct Incomplete;

[[nodiscard]] auto alice_test() noexcept -> bool
{
    return function(RemoveReference<const int&>{42}) and Same<RemoveReference<Incomplete&>,
    Incomplete> and Same<RemoveReference<Incomplete&&>, Incomplete>;
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