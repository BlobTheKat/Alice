# `Alice::Meta::RemoveLvalueReference`

**Header:** `Meta/RemoveLvalueReference.hpp`
**Namespace:** `Alice::Meta`
**Introduced:** `0.0.1` - `13/03/2026`

```cpp
namespace Alice::Meta
{
    template<class Self> using RemoveLvalueReference;
}
```

---

## Description

Returns the type of `Self` with the removed top-level lvalue reference. If `Self` is an rvalue reference, or it has no reference, returns `Self` unchanged.

---

## Template Parameters

| Parameter | Description                                                                           |
| --------- | ------------------------------------------------------------------------------------- |
| `Self`    | The type to remove the lvalue reference from. May be any complete or incomplete type. |
