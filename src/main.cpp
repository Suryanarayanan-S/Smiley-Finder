#include <sysexits.h>
#include <memory>
#include <string>

#include "Analyzer.hpp"
#include "CmdLineParser.hpp"
#include "Output.hpp"
#include "OutputMessage.hpp"


static std::string const kTextBlock = "Application :) for finding smileys :) position :-] and words. :)";

int
main(int const argc, char* const argv[])
{
    int                          exitCode = EX_OK;
    CmdLineParser                parser;
    CmdLineParser::ParsingResult result = parser.parseOptions(argc, argv);

    if (CmdLineParser::ParsingResult::OK == result) {
        Analyzer                              analyzer;
        std::shared_ptr<OutputMessage> const& message = analyzer.computeTextBlock(kTextBlock);

        Output Output{parser.getSettings()};
        Output.publish(message);
    }
    else if (CmdLineParser::ParsingResult::ERROR == result) {
        exitCode = EX_SOFTWARE;
    }
    else {
        /// Do nothing.
        /// Safe exit for help.
    }

    return exitCode;
}