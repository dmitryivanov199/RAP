#ifndef RAP_RAP_PACKER_H
#define RAP_RAP_PACKER_H

#include <fstream>

class RapPacker {
private:
    std::ofstream *rap;
    std::ifstream *configFile;

public:
    RapPacker();

    ~RapPacker();

    bool formRap(std::ofstream &rapDescriptor, std::ifstream &configFileDescriptor);

private:
    bool checkDescriptorsValidity();
};

#endif //RAP_RAP_PACKER_H
