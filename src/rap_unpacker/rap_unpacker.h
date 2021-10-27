#ifndef RAP_RAP_UNPACKER_H
#define RAP_RAP_UNPACKER_H

#include <fstream>

class RapUnpacker {
private:
    std::ifstream *rap;

public:
    RapUnpacker();

    ~RapUnpacker();

    bool unpackRap(std::ifstream &rapDescriptor);

private:
    bool checkRapValidity();
};

#endif //RAP_RAP_UNPACKER_H
