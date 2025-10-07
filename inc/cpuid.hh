#ifndef CPUID_HH_
#define CPUID_HH_

#include <cstdint>
#include <optional>

namespace xdt {
namespace cpuid {

enum register_selector { EAX, EBX, ECX, EDX };

struct extended_registers {
    std::uint32_t eax;
    std::uint32_t ebx;
    std::uint32_t ecx;
    std::uint32_t edx;
};

std::optional<extended_registers> cpuid(const std::uint32_t leaf, const std::uint32_t subleaf);

std::optional<bool> has_field(const std::uint32_t     leaf,
                              const std::uint32_t     subleaf,
                              const register_selector selection,
                              const std::uint32_t     mask);

}  // namespace cpuid
}  // namespace xdt

#endif  // CPUID_HH_
