#ifndef CORE_CMDLINEPARSER_HPP
#define CORE_CMDLINEPARSER_HPP

#include <memory>

#include "OutputFormatSettings.hpp"

/**
 * @class CmdLineParser
 * @details This class helps to handles argument parsing.
 */
class CmdLineParser final
{
public:
    enum class ParsingResult : uint8_t
    {
        OK,         ///< Parsing successful.
        ERROR,      ///< Parsing failed.
        SHALL_EXIT  ///< Parsing was successful, but the options passed by the
                    ///< command line indicate that the process should exit
                    ///< (e.g. help option was given).
    };

    CmdLineParser();
    ~CmdLineParser()                               = default;
    CmdLineParser(CmdLineParser const&)            = delete;
    CmdLineParser(CmdLineParser&&)                 = delete;
    CmdLineParser& operator=(CmdLineParser const&) = delete;
    CmdLineParser& operator=(CmdLineParser&&)      = delete;

    /**
     * @brief Process input arguments
     *
     * @param [in] argc Number of arguments contained in argv.
     * @param [in] argv C-style array of strings containing the
     *                  arguments specified on the command line.
     *                  Usually, the `main` function's argv
     *                  argument will be passed through to this
     *                  method.
     *
     * @return ParsingResult that indicate how caller shall handle it.
     */
    ParsingResult parseOptions(int const argc, char* const argv[]);

    /**
     * @brief Getter to get the output format settings.
     *
     * @return settings for output format
     */
    std::shared_ptr<OutputFormatSettings> const getSettings() const;

private:
    /**
     * @brief Helper function to print the help text block to user.
     */
    void printHelp();

    std::shared_ptr<OutputFormatSettings> mSettings;  /// Contains output formats
};

#endif  /// CORE_CMDLINEPARSER_HPP
