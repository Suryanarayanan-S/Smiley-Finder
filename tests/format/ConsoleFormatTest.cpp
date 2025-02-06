#include <ConsoleFormat.hpp>

#include <gtest/gtest.h>
#include <string>

#include <Analyzer.hpp>

TEST(ConsoleFormatTest, TextWithSmileysAndWords)
{
    static std::string const kTestTextBlock = "Sample application :) for finding smileys :-] and words.";

    /// Testing
    Analyzer      analyzer;
    ConsoleFormat format;
    EXPECT_NO_THROW(format.publish(analyzer.computeTextBlock(kTestTextBlock)));
}

TEST(ConsoleFormatTest, EmptyText)
{
    static std::string const kTestTextBlock = "";

    /// Testing
    Analyzer      analyzer;
    ConsoleFormat format;
    EXPECT_NO_THROW(format.publish(analyzer.computeTextBlock(kTestTextBlock)));
}

TEST(ConsoleFormatTest, TextWithOnlySmiley)
{
    static std::string const kTestTextBlock = ":) :) :-] :):)";

    /// Testing
    Analyzer      analyzer;
    ConsoleFormat format;
    EXPECT_NO_THROW(format.publish(analyzer.computeTextBlock(kTestTextBlock)));
}

TEST(ConsoleFormatTest, TextWithOnlyWords)
{
    static std::string const kTestTextBlock = "Sample application for finding smileys and words.";

    /// Testing
    Analyzer      analyzer;
    ConsoleFormat format;
    EXPECT_NO_THROW(format.publish(analyzer.computeTextBlock(kTestTextBlock)));
}

TEST(ConsoleFormatTest, TextWithMoreThanTenWords)
{
    static std::string const kTestTextBlock
        = "Sample application for finding smileys and words. Sample application for finding smileys and words.";

    /// Testing
    Analyzer      analyzer;
    ConsoleFormat format;
    EXPECT_NO_THROW(format.publish(analyzer.computeTextBlock(kTestTextBlock)));
}
