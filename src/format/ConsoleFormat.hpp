#ifndef FORMAT_CONSOLEFORMAT_HPP
#define FORMAT_CONSOLEFORMAT_HPP

#include <memory>
#include <regex>
#include <vector>

#include "IFormat.hpp"
#include "OutputMessage.hpp"

/**
 * @class ConsoleFormat
 * @details This class helps to publish the output in console format.
 */
class ConsoleFormat : public IFormat
{
public:
    ConsoleFormat()                                = default;
    ~ConsoleFormat()                               = default;
    ConsoleFormat(ConsoleFormat const&)            = delete;
    ConsoleFormat(ConsoleFormat&&)                 = delete;
    ConsoleFormat& operator=(ConsoleFormat const&) = delete;
    ConsoleFormat& operator=(ConsoleFormat&&)      = delete;


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
     * @param [in] smileys list
     */
    void publishSmileys(std::vector<std::smatch> const& smileys);

    /**
     * @brief Publishes the words.
     * @param [in] words list
     */
    void publishWords(std::vector<std::smatch> const& words);
};

#endif  /// FORMAT_CONSOLEFORMAT_HPP
