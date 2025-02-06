#include "Output.hpp"

Output::Output(std::shared_ptr<OutputFormatSettings> const& settings)
  : mFormats(settings->getOutputFormats())
{
}

void
Output::publish(std::shared_ptr<OutputMessage> const& message)
{
    for (auto const& format : mFormats) {
        format->publish(message);
    }
}
