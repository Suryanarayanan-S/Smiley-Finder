#include "OutputFormatSettings.hpp"

OutputFormatSettings::OutputFormatSettings()
  : mFormats()
{
}

void
OutputFormatSettings::registerFormat(std::shared_ptr<IFormat> const& format)
{
    mFormats.emplace_back(format);
}


std::vector<std::shared_ptr<IFormat>> const&
OutputFormatSettings::getOutputFormats() const
{
    return mFormats;
}
