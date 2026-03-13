// Copyright 2026 Netxonica. All Rights Reserved.
#if alice_major >= 0 and alice_middle >= 0 and alice_minor >= 1
#ifndef alice_header_guard_meta_add_rvalue_reference
#define alice_header_guard_meta_add_rvalue_reference

namespace Alice::Meta
{
    template<class Self> using AddRvalueReference = __add_rvalue_reference(Self);
}

#endif
#endif