// Copyright 2026 Netxonica. All Rights Reserved.
#if alice_major >= 0 and alice_middle >= 0 and alice_minor >= 1
#ifndef alice_header_guard_meta_add_lvalue_reference
#define alice_header_guard_meta_add_lvalue_reference

namespace Alice::Meta
{
    template<class Self> using AddLvalueReference = __add_lvalue_reference(Self);
}

#endif
#endif