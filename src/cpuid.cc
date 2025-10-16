#include <cpuid.h>
#include <xdt.hh>

xdt::cpuid::raw_result xdt::cpuid::cpuid(const std::uint32_t leaf, const std::uint32_t subleaf) {
    xdt::cpuid::registers registers;

    if (!__get_cpuid_count(leaf, subleaf, &registers.eax, &registers.ebx, &registers.ecx,
                           &registers.edx)) {
        return std::nullopt;
    }

    return registers;
}

xdt::cpuid::result xdt::cpuid::has_field(const std::uint32_t                 leaf,
                                         const std::uint32_t                 subleaf,
                                         const xdt::cpuid::register_selector selection,
                                         const std::uint32_t                 mask) {
    const auto registers{xdt::cpuid::cpuid(leaf, subleaf)};
    if (!registers) {
        return std::nullopt;
    }

    switch (selection) {
        case xdt::cpuid::register_selector::eax:
            return (registers->eax & mask) != 0u;
        case xdt::cpuid::register_selector::ebx:
            return (registers->ebx & mask) != 0u;
        case xdt::cpuid::register_selector::ecx:
            return (registers->ecx & mask) != 0u;
        case xdt::cpuid::register_selector::edx:
            return (registers->edx & mask) != 0u;
        default:
            return std::nullopt;
    }
}
