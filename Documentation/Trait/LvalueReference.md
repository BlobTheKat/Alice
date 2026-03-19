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

The following won't work as expected:
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

That is because the `foo` definition is interpreted as

```cpp
template<typename T>
void foo(T& x) requires Alice::Trait::LvalueReference<T>
{}
```

Note how only the underlying type `T` is passed to `LvalueReference`, which is not a reference type.

The following definition does include the reference within the concept initialization and works as expected

```cpp
void foo(auto& x) requires Alice::Trait::LvalueReference<decltype(x)>
{}
```