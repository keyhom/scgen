#include <getopt.h>
#include <cstring>
#include <iostream>
#include "scgen.h"

const char* const short_options = "hvl:";
const struct option long_options[] = {
    {"help", 0, NULL, 'h'},
    {"version", 0, NULL, 'v'},
    {"length", 2, NULL, 'l'},
    {0, 0, 0, 0}
};

const char* usages[] = {
    "Scgen 1.0.0-SNAPSHOT, a short code-generator.",
    "Generates a random short-code for the file(s).",
    "",
    "usage: scgen [options ..] [file ..]    work for the file(s).",
    "       scgen [options ..] -            read file(s) from stdin.",
    "",
    "Mandatory arguments to long options are mandatory for short options too.",
    "",
    "Options: ",
    "-h,    --help                          print this help.",
    "-v,    --verbose                       trace the debug output message.",
    "",
    "Message bug reports and suggestions to jeremy.",
    ""
};

void PrintHelp()
{
    int num = sizeof(usages) / sizeof(void*);
    for (int i = 0; i < num; ++i)
        std::cout << usages[i] << std::endl;
}

int main(int argc, char** argv)
{
    int ch;
    while (-1 != (ch = getopt_long(argc, argv, short_options, long_options, NULL)))
    {
        switch (ch)
        {
            case 'h':
                PrintHelp();
                return 0;
            case 'v':
                scgen_config.verbose = true;
                std::cout << "Enabled debug trace ..." << std::endl;
                std::cout << usages[0] << std::endl; // print the version also.
                break;
            case 'l':
                scgen_config.code_length = atoi(optarg);
                break;
            case '?':
            default:
                break;
        }
    }

    if (argc > optind) // 剩余结尾参数，视为文件完全限定路径
    {
        std::string filename;

        for (; optind < argc; ++optind)
        {
            // 首先确认是否指定从stdin读取文件列表
            if (1 == strlen((const char*)argv[optind]) && (int)(*argv[optind]) == '-')
            {
                scgen_config.stdin_opt = true;
                continue;
            }

            filename = argv[optind];

            if (-1 == access(filename.c_str(), 0))
            {
                std::cout << "The file \"" << filename << "\" can't access." << std::endl;
                continue;
            }

            scgen_config.filenames.push_back(std::string(filename));
        }

        if (scgen_config.stdin_opt)
        {
            // Reads from the stdin.
            // Ignores the specified input files.
            std::string sin; 

            while (std::cin >> sin)
            {
                scgen_config.filenames.push_back(std::string(sin));
            }
        }
        
        if (scgen_config.verbose)
        {
            std::cout << "Trace the submit filenames: " << std::endl;
            std::vector<std::string>::iterator it;
            for (it = scgen_config.filenames.begin(); it != scgen_config.filenames.end(); ++it)
            {
                std::cout << *it << std::endl;
            }
        }
    }

    if (scgen_config.filenames.empty())
    {
        if (scgen_config.verbose)
        {
            std::cout << "No file(s) process ..." << std::endl;
            return 1;
        }
    }

    Generate();
    return 0;
}

