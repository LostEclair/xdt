#ifndef AVX_HH_
#define AVX_HH_

#include <cpuid.hh>
#include <optional>

namespace xdt {
namespace avx {

xdt::cpuid::result avx();

}  // namespace avx
}  // namespace xdt

#endif  // AVX_HH_
