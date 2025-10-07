#ifndef SSE_HH_
#define SSE_HH_

#include <optional>

namespace xdt {
namespace sse {

std::optional<bool> sse();

std::optional<bool> sse2();

std::optional<bool> sse3();

std::optional<bool> ssse3();

std::optional<bool> sse4_1();

std::optional<bool> sse4_2();

}  // namespace sse
}  // namespace xdt

#endif  // SSE_HH_
