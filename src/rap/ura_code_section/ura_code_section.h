#ifndef RAP_URA_CODE_SECTION_H
#define RAP_URA_CODE_SECTION_H

#include <array>
#include <cstdint>

#include "../date.h"

struct UraDescriptor {
    std::array<unsigned char, 8> uraId;
    std::array<unsigned char, 4> uraVersion;
    Date uraDate;
    uint8_t uraProducerId;
};

struct UraComponentHeader {
    std::array<unsigned char, 8> uraComponentId;
    uint8_t uraComponentCodeType;
    uint8_t HwComponentID;
};

#endif //RAP_URA_CODE_SECTION_H