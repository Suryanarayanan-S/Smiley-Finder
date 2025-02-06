#ifndef OUTPUT_OUTPUTMESSAGE_HPP
#define OUTPUT_OUTPUTMESSAGE_HPP

#include <regex>
#include <string>
#include <vector>

/**
 * @class OutputMessage
 * @details This class helps to store the output informations.
 */
class OutputMessage final
{
public:
    OutputMessage(std::string const&              inputText,
                  std::vector<std::smatch> const& smileys,
                  std::vector<std::smatch> const& words);
    ~OutputMessage() = default;

    /**
     * @brief Getter to get input text.
     *
     * @return input text
     */
    std::string const& getInputText() const;

    /**
     * @brief Getter to get the found smileys.
     *
     * @return list of found smileys
     */
    std::vector<std::smatch> const& getMatchedSmileys() const;

    /**
     * @brief Getter to get the found words.
     *
     * @return list of found words
     */
    std::vector<std::smatch> const& getMatchedWords() const;

private:
    std::string              mInputText;  /// Input text
    std::vector<std::smatch> mSmileys;    /// List to store the smileys
    std::vector<std::smatch> mWords;      /// List to store the words
};

#endif  /// OUTPUT_OUTPUTMESSAGE_HPP