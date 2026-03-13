# `Alice::Trait::Same`

**Header:** `Trait/Same.hpp`  
**Namespace:** `Alice::Trait`  
**Introduced:** `0.0.1` - `13/03/2026`

```cpp
namespace Alice::Trait
{
    template<class Self, class T> concept Same;
}
```

---

## Description

`Alice::Trait::Same` is a concept that is satisfied if and only if `Self` is the same type as `T`, including any top-level cvref-qualification (`&`, `&&`, `const`, and/or `volatile`).

---

## Template Parameters

| Parameter | Description                                                                   |
| --------- | ----------------------------------------------------------------------------- |
| `Self`    | The type being tested against `T`. May be any complete or incomplete type.    |
| `T`       | The type being tested against `Self`. May be any complete or incomplete type. |
