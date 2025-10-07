#ifndef VENDOR_HH_
#define VENDOR_HH_

#include <optional>
#include <string>

namespace xdt {
namespace vendor {

enum vendors {
    UNKNOWN, /* 0 */
    AMD,     /* 1 */
    CENTAUR, /* 2 */
    CYRIX,   /* 3 */
    HYGON,   /* 4 */
    INTEL,   /* 5 */
    TM1,     /* 6 */
    TM2,     /* 7 */
    NSC,     /* 8 */
    NEXGEN,  /* 9 */
    RISE,    /* 10 */
    SIS,     /* 11 */
    UMC,     /* 12 */
    VIA,     /* 13 */
    VORTEX,  /* 14 */
};

std::optional<std::string> signature();
std::optional<std::string> branding();

vendors guess_vendor();

}  // namespace vendor
}  // namespace xdt

#endif  // VENDOR_HH_
