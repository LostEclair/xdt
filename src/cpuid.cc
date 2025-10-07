#include <cpuid.hh>

#include <cpuid.h>  // The GCC/Clang one

std::optional<xdt::cpuid::extended_registers> xdt::cpuid::cpuid(const std::uint32_t leaf,
                                                                const std::uint32_t subleaf) {
    xdt::cpuid::extended_registers registers;

    if (!__get_cpuid_count(leaf, subleaf, &registers.eax, &registers.ebx, &registers.ecx,
                           &registers.edx)) {
        return std::nullopt;
    }

    return registers;
}

std::optional<bool> xdt::cpuid::has_field(const std::uint32_t                 leaf,
                                          const std::uint32_t                 subleaf,
                                          const xdt::cpuid::register_selector selection,
                                          const std::uint32_t                 mask) {
    const auto registers{xdt::cpuid::cpuid(leaf, subleaf)};
    if (!registers) {
        return std::nullopt;
    }

    switch (selection) {
        case xdt::cpuid::EAX:
            return (registers->eax & mask) != 0u;
        case xdt::cpuid::EBX:
            return (registers->ebx & mask) != 0u;
        case xdt::cpuid::ECX:
            return (registers->ecx & mask) != 0u;
        case xdt::cpuid::EDX:
            return (registers->edx & mask) != 0u;
        default:
            return std::nullopt;
    }
}
