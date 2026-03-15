# `Alice::Meta::RemoveRvalueReference`

**Header:** `Meta/RemoveRvalueReference.hpp`
**Namespace:** `Alice::Meta`
**Introduced:** `0.0.1` - `15/03/2026`

```cpp
namespace Alice::Meta
{
    template<class Self> using RemoveRvalueReference;
}
```

---

## Description

Returns the type of `Self` with the removed top-level rvalue reference. If `Self` is an lvalue reference, or it has no reference, returns `Self` unchanged.

---

## Template Parameters

| Parameter | Description                                                                           |
| --------- | ------------------------------------------------------------------------------------- |
| `Self`    | The type to remove the rvalue reference from. May be any complete or incomplete type. |
