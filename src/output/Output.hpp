#ifndef OUTPUT_OUTPUT_HPP
#define OUTPUT_OUTPUT_HPP

#include <memory>
#include <vector>

#include "IFormat.hpp"
#include "OutputFormatSettings.hpp"
#include "OutputMessage.hpp"

/**
 * @class Output
 * @details This class helps to publishes the output message to the configured output format.
 */
class Output final
{
public:
    explicit Output(std::shared_ptr<OutputFormatSettings> const& settings);
    ~Output() = default;

    /**
     * @brief Publishes the output message to the configured output format.
     * @param [in] message contains output details
     */
    void publish(std::shared_ptr<OutputMessage> const& message);

private:
    std::vector<std::shared_ptr<IFormat>> mFormats;  /// List to store Output formats
};

#endif  /// OUTPUT_OUTPUT_HPP
