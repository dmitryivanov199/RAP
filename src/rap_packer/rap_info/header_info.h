#ifndef RAP_HEADER_INFO_H
#define RAP_HEADER_INFO_H

#include <array>

#include "date.h"

struct DescriptorInfo {
    std::array<unsigned char, 8> rapId;
    std::array<unsigned char, 4> rapVersion;
    Date rapDate;
    uint8_t producerId;
};

struct StructureInfo {
    uint8_t manufacturerInfoFlag: 1;
    uint8_t initialProfileFlag: 1;
    uint8_t rapReserveFlag: 1;
    uint8_t headerReserveFlag: 1;
    uint8_t manufacturerInfoReserveFlag: 1;
    uint8_t securityReserveFlag: 1;
    uint8_t reserveFlags: 2;
};

struct RadioLibInfo {
    std::array<unsigned char, 4> radioLibVersion;
    Date radioLibDate;
};

struct TargetPlatformInfo {
    uint8_t targetPlatformId;
    uint8_t reconfigurationCode;
};

struct HeaderInfo {
    DescriptorInfo descriptor;
    StructureInfo structure;
    RadioLibInfo radioLib;
    TargetPlatformInfo targetPlatform;
};

#endif //RAP_HEADER_INFO_H
