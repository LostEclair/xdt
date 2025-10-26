#ifndef INTEL_HH_
#define INTEL_HH_

#include "cpuid.hh"

namespace xdt {
namespace intel {

xdt::cpuid::result sgx();

}
}  // namespace xdt

#endif  // INTEL_HH_
