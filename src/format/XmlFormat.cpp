#include "XmlFormat.hpp"

XmlFormat::XmlFormat(std::string const& fileName)
  : mFile{fileName}
{
}

IFormat::FormatType
XmlFormat::getType() const noexcept
{
    return IFormat::FormatType::XML;
}

void
XmlFormat::publish(std::shared_ptr<OutputMessage> const& message)
{
    if (mFile.is_open()) {

        mFile << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>";
        mFile << "\n<SmileyFinder>";
        mFile << "\n<output>";
        mFile << "\n\t<name>Input Text</name>";
        mFile << "\n\t<text>" << message->getInputText() << "</text>";
        mFile << "\n</output>";

        publishSmileys(message->getMatchedSmileys());
        publishWords(message->getMatchedWords());

        mFile << "\n</SmileyFinder>";
    }
    else {
        mFile << "\nUnable to publish the output in a text file\n";
    }
}

void
XmlFormat::publishSmileys(std::vector<std::smatch> const& smileys)
{
    if (!smileys.empty()) {
        mFile << "\n<output>";
        mFile << "\n\t<name>Smileys Positions</name>";

        uint8_t constexpr kLimit = 10;
        uint8_t counter          = 0;
        for (auto const& smiley : smileys) {
            if (counter != kLimit) {
                mFile << "\n\t<position>" << smiley.position() << "</position>";
            }

            ++counter;
        }
    }
    else {
        mFile << "\n\t<position>No Smiley</position>";
    }

    mFile << "\n</output>";
}

void
XmlFormat::publishWords(std::vector<std::smatch> const& words)
{
    if (!words.empty()) {
        mFile << "\n<output>";
        mFile << "\n\t<name>Found Words</name>";

        uint8_t constexpr kLimit = 10;
        uint8_t counter          = 0;
        for (auto const& word : words) {
            if (counter != kLimit) {
                mFile << "\n\t<word>" << word.str() << "</word>";
            }

            ++counter;
        }
    }
    else {
        mFile << "\n\t<word>No Word</word>";
    }

    mFile << "\n</output>";
}
