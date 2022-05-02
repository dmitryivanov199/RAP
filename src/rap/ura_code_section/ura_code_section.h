#ifndef RAP_URA_CODE_SECTION_H
#define RAP_URA_CODE_SECTION_H

#include <array>
#include <cstdint>

#include "../date.h"

struct UraDescriptor {
    std::array<unsigned char, 8> appId;
    std::array<unsigned char, 4> appVersion;
    Date appDate;
    uint8_t appProducerId;
};

struct UraComponentHeader {
    std::array<unsigned char, 8> appComponentId;
    uint8_t appComponentCodeType;
    uint8_t HwComponentId;
};

#endif //RAP_URA_CODE_SECTION_H