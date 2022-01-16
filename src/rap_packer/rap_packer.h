#ifndef RAP_RAP_PACKER_H
#define RAP_RAP_PACKER_H

#include <fstream>

#include "../rap/header/header.h"
#include "../rap/padding_bit.h"
#include "../rap/ura_code_section/ura_code_section.h"

class RapPacker {
private:
    std::ofstream pack;

public:
    RapPacker() = default;

    ~RapPacker() = default;

    void formRap();

private:
    void formHeader();

    static void setRapDescriptor(RAPHeader &header);

    static bool setId(std::array<unsigned char, 8> &id, const char *setId);

    static bool setVersion(std::array<unsigned char, 4> &version, const char *setVersion);

    static void setDate(Date &date, uint8_t day, uint8_t month, uint8_t year);

    static void setProducerId(uint8_t &id, uint8_t setId);

    static void getRapFileName(std::array<unsigned char, 8> rapId, char *fileName);

    static void setRapStructureDescriptor(RAPHeader &header);

    static void setRadioLibDescriptor(RAPHeader &header);

    static void setTargetPlatformDescriptor(RAPHeader &header);

    void formUraCodeSection();

    static uint64_t calculateCodeSectionSize();

    static void setUraDescriptor(URADescriptor &descriptor);

    static void setUraComponentHeader(URAComponentHeader &header);

    void writeUraToRap();

    static uint64_t getUraSize();
};

#endif //RAP_RAP_PACKER_H