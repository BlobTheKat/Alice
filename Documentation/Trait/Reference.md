# `Alice::Trait::Reference`

**Header:** `Trait/Reference.hpp`
**Namespace:** `Alice::Trait`
**Introduced:** `0.0.1` - `18/03/2026`

```cpp
namespace Alice::Trait
{
    template<class Self> concept Reference;
}
```

---

## Requirements

- `Alice::Trait::LvalueReference`
- `Alice::Trait::RvalueReference`

---

## Description

Satisfied if and only if one of the following is satisfied:

- `Alice::Trait::LvalueReference<Self>`.
- `Alice::Trait::RvalueReference<Self>`.

---

## Template Parameters

| Parameter | Description                                                    |
| --------- | -------------------------------------------------------------- |
| `Self`    | The type being tested. May be any complete or incomplete type. |
