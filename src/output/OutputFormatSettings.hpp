#ifndef OUTPUT_OUTPUTFORMATSETTINGS_HPP
#define OUTPUT_OUTPUTFORMATSETTINGS_HPP

#include <string>
#include <vector>

#include "IFormat.hpp"

/**
 * @class OutputFormatSettings
 * @details This class helps to get the formats of the output, which is configured by the users.
 */
class OutputFormatSettings final
{
public:
    OutputFormatSettings();
    ~OutputFormatSettings() = default;

    /**
     * @brief Register the output formats configured by the user.
     * @param [in] format of the output
     */
    void registerFormat(std::shared_ptr<IFormat> const& format);

    /**
     * @brief Getter to get the output formats.
     *
     * @return list of all output formats
     */
    std::vector<std::shared_ptr<IFormat>> const& getOutputFormats() const;

private:
    std::vector<std::shared_ptr<IFormat>> mFormats;  /// List to store Output formats
};

#endif  /// OUTPUT_OUTPUTFORMATMESSAGE_HPP
