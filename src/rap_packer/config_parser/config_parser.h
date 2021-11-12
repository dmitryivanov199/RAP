#ifndef RAP_CONFIG_PARSER_H
#define RAP_CONFIG_PARSER_H

#include <fstream>

class ConfigParser {
private:
    std::ifstream *configFile;

public:
    ConfigParser();

    ~ConfigParser();

private:
};

#endif //RAP_CONFIG_PARSER_H
