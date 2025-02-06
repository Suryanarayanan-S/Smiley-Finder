#include <Output.hpp>

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>
#include <regex>
#include <string>
#include <vector>

#include <IFormat.hpp>
#include <OutputFormatSettings.hpp>
#include <OutputMessage.hpp>
#include "MockFormat.hpp"

using ::testing::_;
using ::testing::Invoke;
using ::testing::Return;

TEST(OutputTest, PublishOutput)
{
    /// Mock call for IFormat
    std::shared_ptr<MockFormat> format = std::make_shared<MockFormat>();

    ON_CALL(*format, getType()).WillByDefault(Invoke([]() {
        return IFormat::FormatType::UNKNOWN;
    }));

    EXPECT_CALL(*format, getType()).Times(0);
    EXPECT_CALL(*format, publish(_)).Times(1);

    /// Pre-defines
    std::shared_ptr<OutputFormatSettings> const& settings = std::make_shared<OutputFormatSettings>();
    settings->registerFormat(format);

    std::string              inputText;
    std::vector<std::smatch> smileys;
    std::vector<std::smatch> words;

    /// Testing
    Output output(settings);
    output.publish(std::make_shared<OutputMessage>(inputText, smileys, words));
}

TEST(OutputTest, PublishWithoutRegisteringAnyFormat)
{
    /// Mock call for IFormat
    std::shared_ptr<MockFormat> format = std::make_shared<MockFormat>();

    ON_CALL(*format, getType()).WillByDefault(Invoke([]() {
        return IFormat::FormatType::UNKNOWN;
    }));

    EXPECT_CALL(*format, getType()).Times(0);
    EXPECT_CALL(*format, publish(_)).Times(0);

    /// Pre-defines
    std::shared_ptr<OutputFormatSettings> const& settings = std::make_shared<OutputFormatSettings>();

    std::string              inputText;
    std::vector<std::smatch> smileys;
    std::vector<std::smatch> words;

    /// Testing
    Output output(settings);
    output.publish(std::make_shared<OutputMessage>(inputText, smileys, words));
}
