# `Alice::Meta::AddLvalueReference`

**Header:** `Meta/AddLvalueReference.hpp`
**Namespace:** `Alice::Meta`
**Introduced:** `0.0.1` - `13/03/2026`

```cpp
namespace Alice::Meta
{
    template<class Self> using AddLvalueReference;
}
```

---

## Description

Returns the type of `Self` with an added top-level lvalue reference. If `Self` is an rvalue reference, reference collapsing yields an lvalue reference. No reference is added if `Self` is `void` (possibly cv-qualified) or a type alias thereof.

---

## Template Parameters

| Parameter | Description                                                                      |
| --------- | -------------------------------------------------------------------------------- |
| `Self`    | The type to add the lvalue reference to. May be any complete or incomplete type. |
