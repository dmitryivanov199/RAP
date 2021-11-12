#ifndef RAP_HEADER_INFO_H
#define RAP_HEADER_INFO_H

#include "date.h"

struct DescriptorInfo {
    unsigned char rapId[8];
    unsigned char rapVersion[4];
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
    unsigned char radioLibVersion[4];
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
