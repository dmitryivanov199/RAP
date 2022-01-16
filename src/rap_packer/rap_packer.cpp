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
    getRapFileName(header.rapDescriptor.rapId, fileName);
    rap.open(fileName, std::ios_base::binary | std::ios_base::trunc | std::ios_base::out);

    setRapStructureDescriptor(header);
    setRadioLibDescriptor(header);
    setTargetPlatformDescriptor(header);

    rap.write((char *) &header, sizeof(header));
}

void RapPacker::setRapDescriptor(RapHeader &header) {
    setId(header.rapDescriptor.rapId, "RAP1");
    setVersion(header.rapDescriptor.rapVersion, "1.0");
    setDate(header.rapDescriptor.rapDate, 15, 1, 22);
    setProducerId(header.rapDescriptor.producerId, 126);
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
    header.rapStructureDescriptor.manufacturerInfoFlag = 0;
    header.rapStructureDescriptor.initialProfileFlag = 0;
    header.rapStructureDescriptor.rapReserveFlag = 0;
    header.rapStructureDescriptor.headerReserveFlag = 0;
    header.rapStructureDescriptor.manufacturerInfoReserveFlag = 0;
    header.rapStructureDescriptor.securityReserveFlag = 0;
    header.rapStructureDescriptor.reserveFlags = 0;
}

void RapPacker::setRadioLibDescriptor(RapHeader &header) {
    setVersion(header.radioLibDescriptor.radioLibVersion, "1.0");
    setDate(header.radioLibDescriptor.radioLibDate, 15, 1, 22);
}

void RapPacker::setTargetPlatformDescriptor(RapHeader &header) {
    header.targetPlatformDescriptor.targetPlatformId = 45;
    header.targetPlatformDescriptor.reconfigurationClass = 1;
}

void RapPacker::formUraCodeSection() {
    size_t subsectionsNumber = 1;

    for (size_t i = 0; i < subsectionsNumber; i++) {
        UraDescriptor uraDescriptor{};
        setUraDescriptor(uraDescriptor);
        rap.write((char *) &uraDescriptor, sizeof(uraDescriptor));

        size_t componentsNumber = 1;

        for (size_t j = 0; j < componentsNumber; j++) {

        }
    }

    rap.close();
}

void RapPacker::setUraDescriptor(UraDescriptor &descriptor) {
    setId(descriptor.uraId, "URA1");
    setVersion(descriptor.uraVersion, "1.0");
    setDate(descriptor.uraDate, 15, 1, 22);
    setProducerId(descriptor.uraProducerId, 1);
}