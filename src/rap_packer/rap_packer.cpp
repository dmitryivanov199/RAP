#include <cstring>

#include "rap_packer.h"

void RapPacker::formRap() {
    formHeader();
    formUraCodeSection();
}

void RapPacker::formHeader() {
    RapHeader header{};

    setRapId(header);
    setRapVersion(header);
    setRapDate(header);
    setProducerId(header);

    char fileName[20];
    getRapFileName(header.rapDescriptor.rapId, fileName);
    rap.open(fileName, std::ios_base::binary | std::ios_base::trunc | std::ios_base::out);

    setRapStructureDescriptor(header);
    setRadioLibDescriptor(header);
    setTargetPlatformDescriptor(header);

    rap.write((char *) &header, sizeof(header));
    rap.close();
};

void RapPacker::setRapId(RapHeader &header) {
    header.rapDescriptor.rapId.at(0) = 'R';
    header.rapDescriptor.rapId.at(1) = 'A';
    header.rapDescriptor.rapId.at(2) = 'P';
    header.rapDescriptor.rapId.at(3) = '1';
    header.rapDescriptor.rapId.at(4) = '\0';
}

void RapPacker::setRapVersion(RapHeader &header) {
    header.rapDescriptor.rapVersion.at(0) = '1';
    header.rapDescriptor.rapVersion.at(1) = '.';
    header.rapDescriptor.rapVersion.at(2) = '0';
    header.rapDescriptor.rapVersion.at(3) = '\0';
}

void RapPacker::setRapDate(RapHeader &header) {
    header.rapDescriptor.rapDate.day = 15;
    header.rapDescriptor.rapDate.month = 1;
    header.rapDescriptor.rapDate.year = 22;
}

void RapPacker::setProducerId(RapHeader &header) {
    header.rapDescriptor.producerId = 126;
}

void RapPacker::getRapFileName(std::array<unsigned char, 8> rapId, char *fileName) {
    fileName = strcpy(fileName, "\0");
    size_t k = 0;
    fileName = strcat(fileName, "../rap/");
    k += strlen("../rap/");

    for (size_t i = 0; rapId.at(i) != '\0'; i++) {
        fileName[k] = rapId.at(i);
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
    header.radioLibDescriptor.radioLibVersion.at(0) = '1';
    header.radioLibDescriptor.radioLibVersion.at(1) = '.';
    header.radioLibDescriptor.radioLibVersion.at(2) = '0';
    header.radioLibDescriptor.radioLibVersion.at(3) = '\0';

    header.radioLibDescriptor.radioLibDate.day = 15;
    header.radioLibDescriptor.radioLibDate.month = 1;
    header.radioLibDescriptor.radioLibDate.year = 22;
}

void RapPacker::setTargetPlatformDescriptor(RapHeader &header) {
    header.targetPlatformDescriptor.targetPlatformId = 45;
    header.targetPlatformDescriptor.reconfigurationCode = 5;
}

void RapPacker::formUraCodeSection() {

}