#ifndef SSE_HH_
#define SSE_HH_

#include <cpuid.hh>

namespace xdt {
namespace sse {

xdt::cpuid::result sse();
xdt::cpuid::result sse2();
xdt::cpuid::result sse3();
xdt::cpuid::result ssse3();
xdt::cpuid::result sse4_1();
xdt::cpuid::result sse4_2();

}  // namespace sse
}  // namespace xdt

#endif  // SSE_HH_
