#include "def.hh"

DEF(xdt::sse::sse, 0x1, 0x0, xdt::cpuid::register_selector::edx, BIT_NO(25))
DEF(xdt::sse::sse2, 0x1, 0x0, xdt::cpuid::register_selector::edx, BIT_NO(26))
DEF(xdt::sse::sse3, 0x1, 0x0, xdt::cpuid::register_selector::ecx, BIT_NO(0))
DEF(xdt::sse::ssse3, 0x1, 0x0, xdt::cpuid::register_selector::ecx, BIT_NO(9))
DEF(xdt::sse::sse4_1, 0x1, 0x0, xdt::cpuid::register_selector::ecx, BIT_NO(19))
DEF(xdt::sse::sse4_2, 0x1, 0x0, xdt::cpuid::register_selector::ecx, BIT_NO(20))
