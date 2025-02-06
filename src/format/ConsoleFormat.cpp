#include "ConsoleFormat.hpp"

#include <iostream>

IFormat::FormatType
ConsoleFormat::getType() const noexcept
{
    return IFormat::FormatType::CONSOLE;
}

void
ConsoleFormat::publish(std::shared_ptr<OutputMessage> const& message)
{
    std::cout << "\nInput Text: " << message->getInputText();
    std::cout << "\n-------------------------------------------------------\n";

    publishSmileys(message->getMatchedSmileys());
    publishWords(message->getMatchedWords());

    std::cout << "\n-------------------------------------------------------\n";
}

void
ConsoleFormat::publishSmileys(std::vector<std::smatch> const& smileys)
{
    if (!smileys.empty()) {
        std::cout << "\nSmileys present in the positions:";

        uint8_t constexpr kLimit = 10;
        uint8_t counter          = 0;
        for (auto const& smiley : smileys) {
            if (counter != kLimit) {
                std::cout << " " << smiley.position();
            }

            ++counter;
        }
    }
    else {
        std::cout << "\nNo smileys present in the given input text\n";
    }
}

void
ConsoleFormat::publishWords(std::vector<std::smatch> const& words)
{
    if (!words.empty()) {
        std::cout << "\n\nWords present in the text:\n";

        uint8_t constexpr kLimit = 10;
        uint8_t counter          = 0;
        for (auto const& word : words) {
            if (counter != kLimit) {
                std::cout << word.str() << std::endl;
            }

            ++counter;
        }
    }
    else {
        std::cout << "\n\nNo words present in the given input text\n";
    }
}