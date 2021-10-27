#include "rap_unpacker.h"

RapUnpacker::RapUnpacker() :
        rap{nullptr} {

}

RapUnpacker::~RapUnpacker() = default;

bool RapUnpacker::unpackRap(std::ifstream &rapDescriptor) {
    rap = &rapDescriptor;

    if (checkRapValidity()) {
        return true;
    }

    return false;
}

bool RapUnpacker::checkRapValidity() {
    if (rap == nullptr) {
        return false;
    }

    return rap->is_open();
}