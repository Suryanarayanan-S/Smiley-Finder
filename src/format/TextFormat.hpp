#ifndef FORMAT_TEXTFORMAT_HPP
#define FORMAT_TEXTFORMAT_HPP

#include <fstream>
#include <memory>
#include <regex>
#include <string>
#include <vector>

#include "IFormat.hpp"
#include "OutputMessage.hpp"

/**
 * @class TextFormat
 * @details This class helps to publish the output in text file.
 */
class TextFormat : public IFormat
{
public:
    explicit TextFormat(std::string const& fileName);
    ~TextFormat()                            = default;
    TextFormat(TextFormat const&)            = delete;
    TextFormat(TextFormat&&)                 = delete;
    TextFormat& operator=(TextFormat const&) = delete;
    TextFormat& operator=(TextFormat&&)      = delete;

    /**
     * @brief Getter to get the output format type.
     * @return format type
     */
    FormatType getType() const noexcept override;

    /**
     * @brief Publishes the output message.
     * @param [in] message (output)
     */
    void publish(std::shared_ptr<OutputMessage> const& message) override;

private:
    /**
     * @brief Publishes the smileys.
     * @param [in] smileys
     */
    void publishSmileys(std::vector<std::smatch> const& smileys);

    /**
     * @brief Publishes the words.
     * @param [in] words
     */
    void publishWords(std::vector<std::smatch> const& words);

    std::ofstream mFile;  /// Text file
};

#endif  /// FORMAT_TEXTFORMAT_HPP
