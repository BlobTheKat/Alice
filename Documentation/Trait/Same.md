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

Satisfied if and only if `Self` and `T` strictly denote the same type, including any cvref-qualifiers (`const`, `volatile`, `&`, or `&&`).

---

## Template Parameters

| Parameter | Description                                                                   |
| --------- | ----------------------------------------------------------------------------- |
| `Self`    | The type being tested against `T`. May be any complete or incomplete type.    |
| `T`       | The type being tested against `Self`. May be any complete or incomplete type. |
