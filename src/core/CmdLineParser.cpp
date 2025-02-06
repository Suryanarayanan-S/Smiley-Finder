#include "CmdLineParser.hpp"

#include <getopt.h>
#include <iostream>

#include "ConsoleFormat.hpp"
#include "TextFormat.hpp"
#include "XmlFormat.hpp"

CmdLineParser::CmdLineParser()
  : mSettings(std::make_shared<OutputFormatSettings>())
{
}

CmdLineParser::ParsingResult
CmdLineParser::parseOptions(int const argc, char* const argv[])
{
    ParsingResult     status       = ParsingResult::OK;
    bool              isRegistered = false;
    const char* const kShortOpts   = "ctxh";
    option const      kLongOpts[]  = {{"console", no_argument, nullptr, 'c'},
                                      {"text", no_argument, nullptr, 't'},
                                      {"xml", no_argument, nullptr, 'x'},
                                      {"help", no_argument, nullptr, 'h'},
                                      {nullptr, no_argument, nullptr, 0}};

    while (true) {
        auto opt = getopt_long(argc, argv, kShortOpts, kLongOpts, nullptr);
        if (opt == -1) {
            break;
        }

        switch (opt) {
        case 'c': {
            isRegistered = true;
            mSettings->registerFormat(std::make_shared<ConsoleFormat>());
            break;
        }
        case 't': {
            isRegistered = true;
            mSettings->registerFormat(std::make_shared<TextFormat>("SmileyFinder.txt"));
            break;
        }
        case 'x': {
            isRegistered = true;
            mSettings->registerFormat(std::make_shared<XmlFormat>("SmileyFinder.xml"));
            break;
        }
        case 'h': {
            status = ParsingResult::SHALL_EXIT;
            printHelp();
            break;
        }
        default: {
            status = ParsingResult::ERROR;
            printHelp();
            break;
        }
        }
    }

    if ((ParsingResult::OK == status) && !isRegistered) {
        mSettings->registerFormat(std::make_shared<ConsoleFormat>());
    }

    return status;
}

std::shared_ptr<OutputFormatSettings> const
CmdLineParser::getSettings() const
{
    return mSettings;
}

void
CmdLineParser::printHelp()
{
    std::cout << "\nUsage:";
    std::cout << "\n-c, --console : To enable the output in console";
    std::cout << "\n-t, --text    : To enable the output in text file";
    std::cout << "\n-x, --xml     : To enable the output in xml file";
    std::cout << "\n Default output type will be console";
}
