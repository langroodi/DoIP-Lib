#include <stdexcept>
#include <gtest/gtest.h>
#include <doiplib/announcement_timer.h>

namespace DoipLib
{
    TEST(AnnouncementTimerTest, Constructor)
    {
        const std::chrono::seconds cDelay{1};
        const std::chrono::seconds cInterval{1};
        const uint8_t cCount{0};

        EXPECT_THROW(AnnouncementTimer _timer(cDelay, cInterval, cCount), std::out_of_range);
    }
}