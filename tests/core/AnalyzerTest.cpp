#include <Analyzer.hpp>

#include <gtest/gtest.h>
#include <memory>
#include <string>

#include <OutputMessage.hpp>

TEST(AnalyzerTest, TextWithSmileysAndWords)
{
    static std::string const kTestTextBlock = "Sample application :) for finding smileys :-] and words.";

    Analyzer                             analyzer;
    std::shared_ptr<OutputMessage> const message = analyzer.computeTextBlock(kTestTextBlock);

    EXPECT_EQ(2, message->getMatchedSmileys().size());  // Expecting 2 smileys.
    EXPECT_EQ(7, message->getMatchedWords().size());    // Expecting 7 words.
}

TEST(AnalyzerTest, EmptyText)
{
    static std::string const kTestTextBlock = "";

    Analyzer                             analyzer;
    std::shared_ptr<OutputMessage> const message = analyzer.computeTextBlock(kTestTextBlock);

    EXPECT_EQ(0, message->getMatchedSmileys().size());  // Expecting 0 smileys.
    EXPECT_EQ(0, message->getMatchedWords().size());    // Expecting 0 words.
}


TEST(AnalyzerTest, TextWithOnlySmiley)
{
    static std::string const kTestTextBlock = ":) :) :-] :):)";

    Analyzer                             analyzer;
    std::shared_ptr<OutputMessage> const message = analyzer.computeTextBlock(kTestTextBlock);

    EXPECT_EQ(5, message->getMatchedSmileys().size());  // Expecting 5 smileys.
    EXPECT_EQ(0, message->getMatchedWords().size());    // Expecting 0 words.
}

TEST(AnalyzerTest, TextWithOnlyWords)
{
    static std::string const kTestTextBlock = "Sample application for finding smileys and words.";

    Analyzer                             analyzer;
    std::shared_ptr<OutputMessage> const message = analyzer.computeTextBlock(kTestTextBlock);

    EXPECT_EQ(0, message->getMatchedSmileys().size());  // Expecting 0 smileys.
    EXPECT_EQ(7, message->getMatchedWords().size());    // Expecting 7 words.
}
