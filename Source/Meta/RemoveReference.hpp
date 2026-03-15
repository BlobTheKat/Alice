// Copyright 2026 Netxonica. All Rights Reserved.
#if alice_major >= 0 and alice_middle >= 0 and alice_minor >= 1
#ifndef alice_header_guard_meta_remove_reference
#define alice_header_guard_meta_remove_reference
#include "Meta/RemoveLvalueReference.hpp"
#include "Meta/RemoveRvalueReference.hpp"

namespace Alice::Meta
{
    template<class Self> using RemoveReference = RemoveLvalueReference<RemoveRvalueReference<Self>>
    ;
}

#endif
#endif