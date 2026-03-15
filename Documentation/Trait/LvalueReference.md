# `Alice::Trait::LvalueReference`

**Header:** `Trait/LvalueReference.hpp`
**Namespace:** `Alice::Trait`
**Introduced:** `0.0.1` - `15/03/2026`

```cpp
namespace Alice::Trait
{
    template<class Self> concept LvalueReference;
}
```

---

## Description

Satisfied if and only if `Self` is an lvalue reference type.

---

## Template Parameters

| Parameter | Description                                                    |
| --------- | -------------------------------------------------------------- |
| `Self`    | The type being tested. May be any complete or incomplete type. |

---

## Notes

This works:  
```cpp
void foo(auto& x) requires Alice::Trait::LvalueReference<decltype(x)>
{}

int main()
{
	int x = 42;
	int& rx = x;
	
	foo(rx);
}
```

But this doesn't:
```cpp
void foo(Alice::Trait::LvalueReference auto& x)
{}

int main()
{
	int x = 42;
	int& rx = x;
	
	foo(rx);
}
```

That is because the later one is eagerly evaluating the concept before the type of `x` gets deduced due to the overload resolution requirements, and hence, the ambiguity of `x` is kept (`int`? `int&`? `const int&`?), hence the compiler doesn't know the type of `x` and it assumes it lacks a valid overload.

The former one forces the type of `x` to be deduced before the overload resolution, since such overload resolution is dependent on its type, due to the `decltype`. Then, `x` is deduced before the overload resolution, and `x` can't be ambiguous anymore because it sees its argument comes from an `int&`, which satisfies the concept.