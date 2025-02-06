#ifndef CORE_ANALYZER_HPP
#define CORE_ANALYZER_HPP

#include <memory>
#include <regex>
#include <string>
#include <vector>

#include "OutputMessage.hpp"

/**
 * @class Analyzer
 * @details This class helps to analyze the input text and formulate the response.
 */
class Analyzer final
{
public:
    Analyzer()                           = default;
    ~Analyzer()                          = default;
    Analyzer(Analyzer const&)            = delete;
    Analyzer(Analyzer&&)                 = delete;
    Analyzer& operator=(Analyzer const&) = delete;
    Analyzer& operator=(Analyzer&&)      = delete;

    /**
     * @brief Finds the smileys and words in a text block.
     * @param [in] inputText
     *
     * @return output message contains the match smileys and words
     */
    std::shared_ptr<OutputMessage> const computeTextBlock(std::string const& inputText);

private:
    /**
     * @brief Helper function to find the smileys.
     * @param [in] inputText
     *
     * @return list of matched smileys
     */
    std::vector<std::smatch> const findSmileys(std::string const& inputText);

    /**
     * @brief Helper function to find the words.
     * @param [in] text
     *
     * @return list of matched words
     */
    std::vector<std::smatch> const findWords(std::string const& inputText);
};

#endif  /// CORE_ANALYZER_HPP