#include <CmdLineParser.hpp>

#include <gtest/gtest.h>
#include <memory>
#include <vector>

#include <IFormat.hpp>
#include <OutputFormatSettings.hpp>

TEST(CmdLineParserTest, consoleOptions)
{
    char* const argv[]
        = {const_cast<char*>("ProcName"), const_cast<char*>("-c"), const_cast<char*>("-t"), const_cast<char*>("-x")};

    CmdLineParser parser;
    ASSERT_EQ(CmdLineParser::ParsingResult::OK, parser.parseOptions(4, argv));

    std::vector<std::shared_ptr<IFormat>> const& outputFormats = parser.getSettings()->getOutputFormats();
    EXPECT_EQ(3, outputFormats.size());
    ASSERT_NE(nullptr, outputFormats[0]);
    EXPECT_EQ(IFormat::FormatType::CONSOLE, outputFormats[0]->getType());
    ASSERT_NE(nullptr, outputFormats[1]);
    EXPECT_EQ(IFormat::FormatType::TEXT, outputFormats[1]->getType());
    ASSERT_NE(nullptr, outputFormats[2]);
    EXPECT_EQ(IFormat::FormatType::XML, outputFormats[2]->getType());
}
