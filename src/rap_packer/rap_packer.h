#ifndef RAP_RAP_PACKER_H
#define RAP_RAP_PACKER_H

#include <fstream>

#include "rap/header/header.h"

class RapPacker {
private:
    std::ofstream rap;

public:
    RapPacker() = default;

    ~RapPacker() = default;

    bool formRap();

private:
    void formHeader();

    static void setRapId(RapHeader &header);

    static void setRapVersion(RapHeader &header);

    static void setRapDate(RapHeader &header);

    static void setProducerId(RapHeader &header);

    static void getRapFileName(std::array<unsigned char, 8> rapId, char *fileName);

    static void setRapStructureDescriptor(RapHeader &header);

    static void setRadioLibDescriptor(RapHeader &header);

    static void setTargetPlatformDescriptor(RapHeader &header);
};

#endif //RAP_RAP_PACKER_H
