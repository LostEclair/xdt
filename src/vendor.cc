#include <cpuid.hh>
#include <vendor.hh>

#include <cstdint>
#include <optional>
#include <tuple>

static constexpr std::uint32_t AMD_EBX_{0x68747541};
static constexpr std::uint32_t AMD_EDX_{0x69746e65};
static constexpr std::uint32_t AMD_ECX_{0x444d4163};

static constexpr std::uint32_t CENTAUR_EBX_{0x746e6543};
static constexpr std::uint32_t CENTAUR_EDX_{0x48727561};
static constexpr std::uint32_t CENTAUR_ECX_{0x736c7561};

static constexpr std::uint32_t CYRIX_EBX_{0x69727943};
static constexpr std::uint32_t CYRIX_EDX_{0x736e4978};
static constexpr std::uint32_t CYRIX_ECX_{0x64616574};

static constexpr std::uint32_t HYGON_EBX_{0x6f677948};
static constexpr std::uint32_t HYGON_EDX_{0x6e65476e};
static constexpr std::uint32_t HYGON_ECX_{0x656e6975};

static constexpr std::uint32_t INTEL_EBX_{0x756e6547};
static constexpr std::uint32_t INTEL_EDX_{0x49656e69};
static constexpr std::uint32_t INTEL_ECX_{0x6c65746e};

static constexpr std::uint32_t TM1_EBX_{0x6e617254};
static constexpr std::uint32_t TM1_EDX_{0x74656d73};
static constexpr std::uint32_t TM1_ECX_{0x55504361};

static constexpr std::uint32_t TM2_EBX_{0x756e6547};
static constexpr std::uint32_t TM2_EDX_{0x54656e69};
static constexpr std::uint32_t TM2_ECX_{0x3638784d};

static constexpr std::uint32_t NSC_EBX_{0x646f6547};
static constexpr std::uint32_t NSC_EDX_{0x79622065};
static constexpr std::uint32_t NSC_ECX_{0x43534e20};

static constexpr std::uint32_t NEXGEN_EBX_{0x4778654e};
static constexpr std::uint32_t NEXGEN_EDX_{0x72446e65};
static constexpr std::uint32_t NEXGEN_ECX_{0x6e657669};

static constexpr std::uint32_t RISE_EBX_{0x65736952};
static constexpr std::uint32_t RISE_EDX_{0x65736952};
static constexpr std::uint32_t RISE_ECX_{0x65736952};

static constexpr std::uint32_t SIS_EBX_{0x20536953};
static constexpr std::uint32_t SIS_EDX_{0x20536953};
static constexpr std::uint32_t SIS_ECX_{0x20536953};

static constexpr std::uint32_t UMC_EBX_{0x20434d55};
static constexpr std::uint32_t UMC_EDX_{0x20434d55};
static constexpr std::uint32_t UMC_ECX_{0x20434d55};

static constexpr std::uint32_t VIA_EBX_{0x20414956};
static constexpr std::uint32_t VIA_EDX_{0x20414956};
static constexpr std::uint32_t VIA_ECX_{0x20414956};

static constexpr std::uint32_t VORTEX_EBX_{0x74726f56};
static constexpr std::uint32_t VORTEX_EDX_{0x36387865};
static constexpr std::uint32_t VORTEX_ECX_{0x436f5320};

static std::optional<std::tuple<std::uint32_t, std::uint32_t, std::uint32_t>>
get_vendor_signature_() {
    const auto registers{xdt::cpuid::cpuid(0x0, 0x0)};
    if (!registers) {
        return std::nullopt;
    }

    return std::make_tuple(registers->ebx, registers->edx, registers->ecx);
};

std::optional<std::string> xdt::vendor::signature() {
    const auto registers = xdt::cpuid::cpuid(0x0, 0x0);
    if (!registers) {
        return std::nullopt;
    }

    std::string signature;
    signature.reserve(12);

    auto append__ = [&signature](const std::uint32_t register_value) {
        signature.push_back(static_cast<char>(register_value & 0xFF));
        signature.push_back(static_cast<char>((register_value >> 8) & 0xFF));
        signature.push_back(static_cast<char>((register_value >> 16) & 0xFF));
        signature.push_back(static_cast<char>((register_value >> 24) & 0xFF));
    };
    append__(registers->ebx);
    append__(registers->edx);
    append__(registers->ecx);

    return signature;
}

#define EBX 0
#define EDX 1
#define ECX 2
#define MATCH(symbol, result)                                                                      \
    do {                                                                                           \
        if (std::get<EBX>(*vendor) == symbol##_EBX_ && std::get<EDX>(*vendor) == symbol##_EDX_ &&  \
            std::get<ECX>(*vendor) == symbol##_ECX_) {                                             \
            return result;                                                                         \
        }                                                                                          \
    } while (0)

xdt::vendor::vendors xdt::vendor::guess_vendor() {
    const auto vendor{get_vendor_signature_()};
    if (!vendor) {
        return xdt::vendor::UNKNOWN;
    }

    MATCH(AMD, xdt::vendor::AMD);
    MATCH(CENTAUR, xdt::vendor::CENTAUR);
    MATCH(CYRIX, xdt::vendor::CYRIX);
    MATCH(HYGON, xdt::vendor::HYGON);
    MATCH(INTEL, xdt::vendor::INTEL);
    MATCH(TM1, xdt::vendor::TM1);
    MATCH(TM2, xdt::vendor::TM2);
    MATCH(NSC, xdt::vendor::NSC);
    MATCH(NEXGEN, xdt::vendor::NEXGEN);
    MATCH(RISE, xdt::vendor::RISE);
    MATCH(SIS, xdt::vendor::SIS);
    MATCH(UMC, xdt::vendor::UMC);
    MATCH(VIA, xdt::vendor::VIA);
    MATCH(VORTEX, xdt::vendor::VORTEX);

    return xdt::vendor::UNKNOWN;
}
