#include <OutputMessage.hpp>

#include <gtest/gtest.h>
#include <memory>
#include <regex>
#include <string>
#include <vector>

#include <OutputMessage.hpp>

TEST(OutputMessageTest, MessageWithEmptyInformation)
{
    std::string const              inputText;
    std::vector<std::smatch> const smileys;
    std::vector<std::smatch> const words;

    /// Testing
    std::shared_ptr<OutputMessage> message = std::make_shared<OutputMessage>(inputText, smileys, words);
    EXPECT_STREQ("", message->getInputText().c_str());
    EXPECT_EQ(0, message->getMatchedSmileys().size());
    EXPECT_EQ(0, message->getMatchedWords().size());
}

TEST(OutputMessageTest, MessageWithInformation)
{
    std::string const              inputText = "Testing text block";
    std::vector<std::smatch> const smileys   = {std::smatch()};
    std::vector<std::smatch> const words     = {std::smatch()};

    /// Testing
    std::shared_ptr<OutputMessage> message = std::make_shared<OutputMessage>(inputText, smileys, words);
    EXPECT_STREQ(inputText.c_str(), message->getInputText().c_str());
    EXPECT_EQ(1, message->getMatchedSmileys().size());
    EXPECT_EQ(1, message->getMatchedWords().size());
}
