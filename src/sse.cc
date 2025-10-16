#include <xdt.hh>

static constexpr std::uint32_t SSE_MASK_{1u << 25};
static constexpr std::uint32_t SSE2_MASK_{1u << 26};
static constexpr std::uint32_t SSE3_MASK_{1u << 0};
static constexpr std::uint32_t SSSE3_MASK_{1u << 9};
static constexpr std::uint32_t SSE4_1_MASK_{1u << 19};
static constexpr std::uint32_t SSE4_2_MASK_{1u << 20};

xdt::cpuid::result xdt::sse::sse() {
    return xdt::cpuid::has_field(0x1, 0x0, xdt::cpuid::register_selector::edx, SSE_MASK_);
}

xdt::cpuid::result xdt::sse::sse2() {
    return xdt::cpuid::has_field(0x1, 0x0, xdt::cpuid::register_selector::edx, SSE2_MASK_);
}

xdt::cpuid::result xdt::sse::sse3() {
    return xdt::cpuid::has_field(0x1, 0x0, xdt::cpuid::register_selector::ecx, SSE3_MASK_);
}

xdt::cpuid::result xdt::sse::ssse3() {
    return xdt::cpuid::has_field(0x1, 0x0, xdt::cpuid::register_selector::ecx, SSSE3_MASK_);
}

xdt::cpuid::result xdt::sse::sse4_1() {
    return xdt::cpuid::has_field(0x1, 0x0, xdt::cpuid::register_selector::ecx, SSE4_1_MASK_);
}

xdt::cpuid::result xdt::sse::sse4_2() {
    return xdt::cpuid::has_field(0x1, 0x0, xdt::cpuid::register_selector::ecx, SSE4_2_MASK_);
}
