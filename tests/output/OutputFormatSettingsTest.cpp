#include <OutputFormatSettings.hpp>

#include <gtest/gtest.h>
#include <memory>

#include "MockFormat.hpp"

TEST(OutputFormatSettingsTest, RegisterFormat)
{
    /// Testing
    OutputFormatSettings settings;
    settings.registerFormat(std::make_shared<MockFormat>());
    EXPECT_EQ(1, settings.getOutputFormats().size());
}

TEST(OutputFormatSettingsTest, WithoutRegisterAnyFormat)
{
    /// Testing
    OutputFormatSettings settings;
    EXPECT_EQ(0, settings.getOutputFormats().size());
}
