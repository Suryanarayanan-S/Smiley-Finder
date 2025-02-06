#include "Analyzer.hpp"

std::shared_ptr<OutputMessage> const
Analyzer::computeTextBlock(std::string const& inputText)
{
    return std::make_shared<OutputMessage>(inputText, findSmileys(inputText), findWords(inputText));
}

std::vector<std::smatch> const
Analyzer::findSmileys(std::string const& inputText)
{
    std::regex const         regex(":\\)|:-\\]");
    std::vector<std::smatch> smileys;

    for (auto it = std::sregex_iterator(inputText.begin(), inputText.end(), regex); it != std::sregex_iterator();
         ++it) {
        smileys.push_back(*it);
    }

    return smileys;
}

std::vector<std::smatch> const
Analyzer::findWords(std::string const& inputText)
{
    std::regex const         regex("\\w+");
    std::vector<std::smatch> words;

    for (auto it = std::sregex_iterator(inputText.begin(), inputText.end(), regex); it != std::sregex_iterator();
         ++it) {
        words.push_back(*it);
    }

    return words;
}