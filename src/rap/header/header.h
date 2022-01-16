#ifndef RAP_HEADER_H
#define RAP_HEADER_H

#include <array>

#include "../date.h"

struct RAPDescriptor {
    std::array<unsigned char, 8> packID;
    std::array<unsigned char, 4> packVersion;
    Date packDate;
    uint8_t packProducerID;
};

struct RapStructureDescriptor {
    uint8_t manufacturerInfoFlag: 1;
    uint8_t initialProfileFlag: 1;
    uint8_t rapReserveFlag: 1;
    uint8_t headerReserveFlag: 1;
    uint8_t manufacturerInfoReserveFlag: 1;
    uint8_t securityReserveFlag: 1;
    uint8_t reserveFlags: 2;
};

struct RadioLibDescriptor {
    std::array<unsigned char, 4> radioLibVersion;
    Date radioLibDate;
};

struct TargetPlatformDescriptor {
    uint8_t targetPlatformID;
    uint8_t reconfigurationClass;
};

struct RAPHeader {
    RAPDescriptor packDescriptor;
    RapStructureDescriptor packStructureDescriptor;
    RadioLibDescriptor radioLibDescriptor;
    TargetPlatformDescriptor targetPlatformDescriptor;
};

#endif //RAP_HEADER_H