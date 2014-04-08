#ifndef SCGEN_H
#define SCGEN_H

#include <stdlib.h>
#include <vector>
#include <iostream>

typedef struct ScgenConfig
{
    bool stdin_opt;
    bool verbose;
    bool styled;
    int32_t code_length;
    std::vector<std::string> filenames;
} ScgenConfig;

extern struct ScgenConfig scgen_config;
extern void Generate();
#endif // SCGEN_H
// vim: expandtab sw=4 ts=4 tw=0
