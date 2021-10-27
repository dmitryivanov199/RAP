#include "rap_packer.h"

RapPacker::RapPacker() :
        rap{nullptr},
        configFile{nullptr} {

}

RapPacker::~RapPacker() = default;

bool RapPacker::formRap(std::ofstream &rapDescriptor, std::ifstream &configFileDescriptor) {
    rap = &rapDescriptor;
    configFile = &configFileDescriptor;

    if (checkDescriptorsValidity()) {
        return true;
    }

    return false;
}

bool RapPacker::checkDescriptorsValidity() {
    if (rap == nullptr || configFile == nullptr) {
        return false;
    }

    return rap->is_open() && configFile->is_open();
}