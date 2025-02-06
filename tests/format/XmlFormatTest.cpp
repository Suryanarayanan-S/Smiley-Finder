#include <XmlFormat.hpp>

#include <gtest/gtest.h>
#include <string>

#include <Analyzer.hpp>

TEST(XmlFormatTest, TextWithSmileysAndWords)
{
    static std::string const kTestTextBlock = "Sample application :) for finding smileys :-] and words.";
    static std::string const kFileName      = "Test.xml";

    /// Testing
    Analyzer  analyzer;
    XmlFormat format{kFileName};
    EXPECT_NO_THROW(format.publish(analyzer.computeTextBlock(kTestTextBlock)));
}

TEST(XmlFormatTest, EmptyText)
{
    static std::string const kTestTextBlock = "";
    static std::string const kFileName      = "Test1.xml";

    /// Testing
    Analyzer  analyzer;
    XmlFormat format{kFileName};
    EXPECT_NO_THROW(format.publish(analyzer.computeTextBlock(kTestTextBlock)));
}

TEST(XmlFormatTest, TextWithOnlySmiley)
{
    static std::string const kTestTextBlock = ":) :) :-] :):)";
    static std::string const kFileName      = "Test2.xml";

    /// Testing
    Analyzer  analyzer;
    XmlFormat format{kFileName};
    EXPECT_NO_THROW(format.publish(analyzer.computeTextBlock(kTestTextBlock)));
}

TEST(XmlFormatTest, TextWithOnlyWords)
{
    static std::string const kTestTextBlock = "Sample application for finding smileys and words.";
    static std::string const kFileName      = "Test3.xml";

    /// Testing
    Analyzer  analyzer;
    XmlFormat format{kFileName};
    EXPECT_NO_THROW(format.publish(analyzer.computeTextBlock(kTestTextBlock)));
}

TEST(XmlFormatTest, TextWithMoreThanTenWords)
{
    static std::string const kTestTextBlock
        = "Sample application for finding smileys and words. Sample application for finding smileys and words.";
    static std::string const kFileName = "Test4.xml";

    /// Testing
    Analyzer  analyzer;
    XmlFormat format{kFileName};
    EXPECT_NO_THROW(format.publish(analyzer.computeTextBlock(kTestTextBlock)));
}
