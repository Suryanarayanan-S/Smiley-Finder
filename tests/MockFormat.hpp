#include <IFormat.hpp>

#include <gmock/gmock.h>
#include <string>

class MockFormat : public IFormat
{
public:
    MOCK_METHOD(void, publish, (std::shared_ptr<OutputMessage> const& message), (override));
    MOCK_METHOD(IFormat::FormatType, getType, (), (const, noexcept, override));
};
