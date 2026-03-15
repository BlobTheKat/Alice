# `Alice::Meta::RemoveReference`

**Header:** `Meta/RemoveReference.hpp`
**Namespace:** `Alice::Meta`
**Introduced:** `0.0.1` - `15/03/2026`

```cpp
namespace Alice::Meta
{
    template<class Self> using RemoveReference;
}
```

---

## Requirements

- `Alice::Meta::RemoveLvalueReference`
- `Alice::Meta::RemoveRvalueReference`

---

## Description

Returns the type of `Self` with the removed top-level lvalue or rvalue reference. If `Self` has no reference, returns `Self` unchanged.

---

## Template Parameters

| Parameter | Description                                                                                     |
| --------- | ----------------------------------------------------------------------------------------------- |
| `Self`    | The type to remove the lvalue or rvalue reference from. May be any complete or incomplete type. |
