#ifndef FORMAT_XMLFORMAT_HPP
#define FORMAT_XMLFORMAT_HPP

#include <fstream>
#include <memory>
#include <regex>
#include <string>
#include <vector>

#include "IFormat.hpp"
#include "OutputMessage.hpp"

/**
 * @class XmlFormat
 * @details This class helps to publish the output in xml file.
 */
class XmlFormat : public IFormat
{
public:
    explicit XmlFormat(std::string const& fileName);
    ~XmlFormat()                           = default;
    XmlFormat(XmlFormat const&)            = delete;
    XmlFormat(XmlFormat&&)                 = delete;
    XmlFormat& operator=(XmlFormat const&) = delete;
    XmlFormat& operator=(XmlFormat&&)      = delete;

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

    std::ofstream mFile;  /// Xml file
};

#endif  /// FORMAT_XMLFORMAT_HPP
