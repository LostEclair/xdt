#ifndef CPUID_HH_
#define CPUID_HH_

#include <cstdint>
#include <optional>

namespace xdt {
namespace cpuid {

enum class register_selector { eax, ebx, ecx, edx };

struct registers {
    std::uint32_t eax;
    std::uint32_t ebx;
    std::uint32_t ecx;
    std::uint32_t edx;
};

/// false        -> Not supported
/// true         -> Supported
/// std::nullopt -> N/A (CPUID/Leaf is not supported)
using result = std::optional<bool>;

using raw_result = std::optional<registers>;

raw_result cpuid(const std::uint32_t leaf, const std::uint32_t subleaf);

result has_field(const std::uint32_t     leaf,
                 const std::uint32_t     subleaf,
                 const register_selector selection,
                 const std::uint32_t     mask);

}  // namespace cpuid
}  // namespace xdt

#endif  // CPUID_HH_
