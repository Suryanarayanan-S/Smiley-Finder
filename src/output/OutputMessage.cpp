#include "OutputMessage.hpp"

OutputMessage::OutputMessage(std::string const&              inputText,
                             std::vector<std::smatch> const& smileys,
                             std::vector<std::smatch> const& words)
  : mInputText(inputText)
  , mSmileys(smileys)
  , mWords(words)
{
}

std::string const&
OutputMessage::getInputText() const
{
    return mInputText;
}

std::vector<std::smatch> const&
OutputMessage::getMatchedSmileys() const
{
    return mSmileys;
}


std::vector<std::smatch> const&
OutputMessage::getMatchedWords() const
{
    return mWords;
}
