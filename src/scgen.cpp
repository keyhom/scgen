#include "scgen.h"
#include <stdlib.h>
#include <iostream> 
#include <sstream>
#include "json/json.h"

struct ScgenConfig scgen_config = { false, false, false, 4 };

const char codes[] = {
    'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
    '1','2','3','4','5','6','7','8','9','0',
    'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'
};

inline double random(double start, double end)
{
    return start + (end - start) * rand() / (RAND_MAX + 1.0);
}

std::string randomCode(int32_t length)
{
    int size = sizeof(codes) / sizeof(char);
    int i;
    std::stringstream ss;

    for (i = 0; i < length; ++i)
    {
        ss << codes[int(random(0, size))];
    }

    ss.flush();
    return ss.str();
}

// Generates the result.
void Generate()
{
    Json::Value root; // construct a json object.
    // make sure the scgen_config.filenames wasn't empty.
    std::vector<std::string>::iterator it;
    // loop the filenames and process them.
    srand((unsigned)time(NULL));

    for (it = scgen_config.filenames.begin(); it != scgen_config.filenames.end(); ++it)
    {
        root[(*it)] = randomCode(scgen_config.code_length);
    }

    if (scgen_config.styled)
    {
        std::cout << root.toStyledString() << std::endl;
    }
    else
    {
        Json::FastWriter writer;
        std::cout << writer.write(root) << std::endl;
    }
}
