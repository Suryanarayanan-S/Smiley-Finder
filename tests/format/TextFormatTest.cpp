#include <TextFormat.hpp>

#include <gtest/gtest.h>
#include <string>

#include <Analyzer.hpp>

TEST(TextFormatTest, TextWithSmileysAndWords)
{
    static std::string const kTestTextBlock = "Sample application :) for finding smileys :-] and words.";
    static std::string const kFileName      = "Test.txt";

    /// Testing
    Analyzer   analyzer;
    TextFormat format{kFileName};
    EXPECT_NO_THROW(format.publish(analyzer.computeTextBlock(kTestTextBlock)));
}

TEST(TextFormatTest, EmptyText)
{
    static std::string const kTestTextBlock = "";
    static std::string const kFileName      = "Test1.txt";

    /// Testing
    Analyzer   analyzer;
    TextFormat format{kFileName};
    EXPECT_NO_THROW(format.publish(analyzer.computeTextBlock(kTestTextBlock)));
}

TEST(TextFormatTest, TextWithOnlySmiley)
{
    static std::string const kTestTextBlock = ":) :) :-] :):)";
    static std::string const kFileName      = "Test2.txt";

    /// Testing
    Analyzer   analyzer;
    TextFormat format{kFileName};
    EXPECT_NO_THROW(format.publish(analyzer.computeTextBlock(kTestTextBlock)));
}

TEST(TextFormatTest, TextWithOnlyWords)
{
    static std::string const kTestTextBlock = "Sample application for finding smileys and words.";
    static std::string const kFileName      = "Test3.txt";

    /// Testing
    Analyzer   analyzer;
    TextFormat format{kFileName};
    EXPECT_NO_THROW(format.publish(analyzer.computeTextBlock(kTestTextBlock)));
}

TEST(TextFormatTest, TextWithMoreThanTenWords)
{
    static std::string const kTestTextBlock
        = "Sample application for finding smileys and words. Sample application for finding smileys and words.";
    static std::string const kFileName = "Test4.txt";

    /// Testing
    Analyzer   analyzer;
    TextFormat format{kFileName};
    EXPECT_NO_THROW(format.publish(analyzer.computeTextBlock(kTestTextBlock)));
}
