/// Some defines for smaller code

#ifndef DEF_HH_
#define DEF_HH_

#include <xdt.hh>

#define BIT_NO(bit_number) (1u << bit_number)

#define DEF(function_name, leaf, subleaf, register_selector, mask)             \
  xdt::cpuid::result function_name() {                                         \
    return xdt::cpuid::has_field(leaf, subleaf, register_selector, mask);      \
  }

#define ENSURE_VENDOR_(v)                                                      \
  do {                                                                         \
    if (xdt::vendor::guess_vendor() != v) {                                    \
      return false;                                                            \
    }                                                                          \
  } while (0)

#define ENSURE_INTEL() ENSURE_VENDOR_(xdt::vendor::vendors::intel)
#define ENSURE_AMD() ENSURE_VENDOR_(xdt::vendor::vendors::amd)

#define INTEL_DEF(function_name, leaf, subleaf, register_selector, mask)       \
  xdt::cpuid::result function_name() {                                         \
    ENSURE_INTEL();                                                            \
    return xdt::cpuid::has_field(leaf, subleaf, register_selector, mask);      \
  }

#define AMD_DEF(function_name, leaf, subleaf, register_selector, mask)         \
  xdt::cpuid::result function_name() {                                         \
    ENSURE_AMD();                                                              \
    return xdt::cpuid::has_field(leaf, subleaf, register_selector, mask);      \
  }

#endif // DEF_HH_
