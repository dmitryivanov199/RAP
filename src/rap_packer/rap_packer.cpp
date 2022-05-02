#include <cstring>

#include "rap_packer.h"

void RapPacker::formRap() {
    formHeader();
    formUraCodeSection();
}

void RapPacker::formHeader() {
    RapHeader header{};
    setRapDescriptor(header);

    char fileName[20];
    getRapFileName(header.packDescriptor.packId, fileName);
    pack.open(fileName, std::ios_base::binary | std::ios_base::trunc | std::ios_base::out);

    setRapStructureDescriptor(header);
    setRadioLibDescriptor(header);
    setTargetPlatformDescriptor(header);

    pack.write((char *) &header, sizeof(header));
}

void RapPacker::setRapDescriptor(RapHeader &header) {
    setId(header.packDescriptor.packId, "RAP1");
    setVersion(header.packDescriptor.packVersion, "1.0");
    setDate(header.packDescriptor.packDate, 15, 1, 22);
    setProducerId(header.packDescriptor.packProducerId, 126);
}

bool RapPacker::setId(std::array<unsigned char, 8> &id, const char *setId) {
    if (8 < strlen(setId) + 1) {
        return false;
    }

    size_t i;

    for (i = 0; *setId != '\0'; i++) {
        id.at(i) = static_cast<unsigned char>(*setId);
        setId++;
    }

    id.at(i) = '\0';

    return true;
}

bool RapPacker::setVersion(std::array<unsigned char, 4> &version, const char *setVersion) {
    if (4 < strlen(setVersion) + 1) {
        return false;
    }

    size_t i;

    for (i = 0; *setVersion != '\0'; i++) {
        version.at(i) = static_cast<unsigned char>(*setVersion);
        setVersion++;
    }

    version.at(i) = '\0';

    return true;
}

void RapPacker::setDate(Date &date, uint8_t day, uint8_t month, uint8_t year) {
    date.day = day;
    date.month = month;
    date.year = year;
}

void RapPacker::setProducerId(uint8_t &id, uint8_t setId) {
    id = setId;
}

void RapPacker::getRapFileName(std::array<unsigned char, 8> rapId, char *fileName) {
    fileName = strcpy(fileName, "\0");
    size_t k = 0;
    fileName = strcat(fileName, "../rap/");
    k += strlen("../rap/");

    for (size_t i = 0; rapId.at(i) != '\0'; i++) {
        fileName[k] = static_cast<char>(rapId.at(i));
        k++;
    }

    fileName[k] = '\0';
    strcat(fileName, ".bin");
}

void RapPacker::setRapStructureDescriptor(RapHeader &header) {
    header.packStructureDescriptor.manufacturerInfoFlag = 0;
    header.packStructureDescriptor.initialProfileFlag = 0;
    header.packStructureDescriptor.rapReserveFlag = 0;
    header.packStructureDescriptor.headerReserveFlag = 0;
    header.packStructureDescriptor.manufacturerInfoReserveFlag = 0;
    header.packStructureDescriptor.securityReserveFlag = 0;
    header.packStructureDescriptor.reserveFlags = 0;
}

void RapPacker::setRadioLibDescriptor(RapHeader &header) {
    setVersion(header.radioLibDescriptor.radioLibVersion, "1.0");
    setDate(header.radioLibDescriptor.radioLibDate, 1, 1, 22);
}

void RapPacker::setTargetPlatformDescriptor(RapHeader &header) {
    header.targetPlatformDescriptor.targetPlatformId = 45;
    header.targetPlatformDescriptor.reconfigurationClass = 2;
}

void RapPacker::formUraCodeSection() {
    uint64_t codeSectionSize = calculateCodeSectionSize();
    pack.write((char *) &codeSectionSize, sizeof(codeSectionSize));

    UraDescriptor uraDescriptor{};
    setUraDescriptor(uraDescriptor);
    pack.write((char *) &uraDescriptor, sizeof(uraDescriptor));

    PaddingBit paddingBit{};
    paddingBit.paddingBit = 0;
    pack.write((char *) &paddingBit, sizeof(paddingBit));

    UraComponentHeader header{};
    setUraComponentHeader(header);
    pack.write((char *) &header, sizeof(header));

    writeUraToRap();

    pack.close();
}

uint64_t RapPacker::calculateCodeSectionSize() {
    uint64_t codeSectionSize{sizeof(UraDescriptor) + sizeof(UraComponentHeader) + sizeof(PaddingBit)};
    codeSectionSize += sizeof(uint64_t);
    codeSectionSize += getUraSize();

    return codeSectionSize;
}

void RapPacker::setUraDescriptor(UraDescriptor &descriptor) {
    setId(descriptor.appId, "URA1");
    setVersion(descriptor.appVersion, "1.0");
    setDate(descriptor.appDate, 1, 1, 22);
    setProducerId(descriptor.appProducerId, 1);
}

void RapPacker::setUraComponentHeader(UraComponentHeader &header) {
    setId(header.appComponentId, "156R2n");
    header.appComponentCodeType = 0;
    header.HwComponentId = 123;
}

void RapPacker::writeUraToRap() {
    uint64_t uraSize = getUraSize();
    pack.write((char *) &uraSize, sizeof(uraSize));

    std::ifstream ura("../ura/URA", std::ios_base::in | std::ios_base::binary);

    if (ura.is_open()) {
        char byte;

        while (ura.get(byte)) {
            pack.write((char *) &byte, sizeof(byte));
        }
    }

    ura.close();
}

uint64_t RapPacker::getUraSize() {
    uint64_t uraSize = 0;

    std::ifstream ura("../ura/URA", std::ios_base::in | std::ios_base::binary);

    if (ura.is_open()) {
        char byte;

        while (ura.get(byte)) {
            uraSize++;
        }

        ura.close();
        return uraSize;
    }

    return 0;
}