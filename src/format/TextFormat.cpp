#include "TextFormat.hpp"

TextFormat::TextFormat(std::string const& fileName)
  : mFile{fileName}
{
}

IFormat::FormatType
TextFormat::getType() const noexcept
{
    return IFormat::FormatType::TEXT;
}

void
TextFormat::publish(std::shared_ptr<OutputMessage> const& message)
{
    if (mFile.is_open()) {
        mFile << "\nInput Text: " << message->getInputText();
        mFile << "\n-------------------------------------------------------\n";

        publishSmileys(message->getMatchedSmileys());
        publishWords(message->getMatchedWords());

        mFile << "\n-------------------------------------------------------\n";
    }
    else {
        mFile << "\nUnable to publish the output in a text file\n";
    }
}

void
TextFormat::publishSmileys(std::vector<std::smatch> const& smileys)
{
    if (!smileys.empty()) {
        mFile << "\nSmileys present in the positions:";

        uint8_t constexpr kLimit = 10;
        uint8_t counter          = 0;
        for (auto const& smiley : smileys) {
            if (counter != kLimit) {
                mFile << " " << smiley.position();
            }

            ++counter;
        }
    }
    else {
        mFile << "\nNo smileys present in the given input text\n";
    }
}

void
TextFormat::publishWords(std::vector<std::smatch> const& words)
{
    if (!words.empty()) {
        mFile << "\n\nWords present in the text:\n";

        uint8_t constexpr kLimit = 10;
        uint8_t counter          = 0;
        for (auto const& word : words) {
            if (counter != kLimit) {
                mFile << word.str() << "\n";
            }

            ++counter;
        }
    }
    else {
        mFile << "\n\nNo words present in the given input text\n";
    }
}
