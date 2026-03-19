# `Alice::Trait::RvalueReference`

**Header:** `Trait/RvalueReference.hpp`
**Namespace:** `Alice::Trait`
**Introduced:** `0.0.1` - `15/03/2026`

```cpp
namespace Alice::Trait
{
    template<class Self> concept RvalueReference;
}
```

---

## Description

Satisfied if and only if `Self` is an rvalue reference type.

---

## Template Parameters

| Parameter | Description                                                    |
| --------- | -------------------------------------------------------------- |
| `Self`    | The type being tested. May be any complete or incomplete type. |

---

## Notes

The following won't work as expected:
```cpp
void foo(Alice::Trait::RvalueReference auto&& x)
{}

int main()
{
	foo(42);
}
```

That is because the `foo` definition is interpreted as

```cpp
template<typename T>
void foo(T&& x) requires Alice::Trait::RvalueReference<T>
{}
```

Note how only the underlying type `T` is passed to `RvalueReference`, which is not a reference type.

The following definition does include the reference within the concept initialization and works as expected

```cpp
void foo(auto& x) requires Alice::Trait::RvalueReference<decltype(x)>
{}
```