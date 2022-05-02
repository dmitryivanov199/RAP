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

    static void setRapDescriptor(RapHeader &header);

    static bool setId(std::array<unsigned char, 8> &id, const char *setId);

    static bool setVersion(std::array<unsigned char, 4> &version, const char *setVersion);

    static void setDate(Date &date, uint8_t day, uint8_t month, uint8_t year);

    static void setProducerId(uint8_t &id, uint8_t setId);

    static void getRapFileName(std::array<unsigned char, 8> rapId, char *fileName);

    static void setRapStructureDescriptor(RapHeader &header);

    static void setRadioLibDescriptor(RapHeader &header);

    static void setTargetPlatformDescriptor(RapHeader &header);

    void formUraCodeSection();

    static uint64_t calculateCodeSectionSize();

    static void setUraDescriptor(UraDescriptor &descriptor);

    static void setUraComponentHeader(UraComponentHeader &header, const char *componentId);

    void writeUraToRap(const char *appName);

    static uint64_t getUraSize(const char *appName);
};

#endif //RAP_RAP_PACKER_H