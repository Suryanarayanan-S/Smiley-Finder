#ifndef FORMAT_IFORMAT_HPP
#define FORMAT_IFORMAT_HPP

#include <memory>

#include "OutputMessage.hpp"

/**
 * @class IFormat
 * @details This interface helps extend various output format.
 */
class IFormat
{
public:
    enum class FormatType : uint8_t
    {
        UNKNOWN = 0,
        CONSOLE,
        TEXT,
        XML
    };

    ~IFormat() = default;

    /**
     * @brief Getter to get the output format type.
     * @return format type
     */
    virtual FormatType getType() const noexcept = 0;

    /**
     * @brief Publishes the output message.
     * @param [in] message (output)
     */
    virtual void publish(std::shared_ptr<OutputMessage> const& message) = 0;
};

#endif  /// OUTPUT_OUTPUT_HPP
