#ifndef VENDOR_HH_
#define VENDOR_HH_

#include <optional>
#include <string>

namespace xdt {
namespace vendor {

enum class vendors {
    unknown, /* 0 */
    amd,     /* 1 */
    centaur, /* 2 */
    cyrix,   /* 3 */
    hygon,   /* 4 */
    intel,   /* 5 */
    tm1,     /* 6 */
    tm2,     /* 7 */
    nsc,     /* 8 */
    nexgen,  /* 9 */
    rise,    /* 10 */
    sis,     /* 11 */
    umc,     /* 12 */
    via,     /* 13 */
    vortex,  /* 14 */
};

std::optional<std::string> signature();
std::optional<std::string> branding();

vendors guess_vendor();

}  // namespace vendor
}  // namespace xdt

#endif  // VENDOR_HH_
