#include "CanFrame.h"

#include <gtest/gtest.h>

// Test fixture for CanFrame
class CanFrameTest : public ::testing::Test {
 protected:
  // You can define any setup or teardown code here if needed
};

// Test for CanFrame constructor with id and message
TEST_F(CanFrameTest, ConstructorWithIdAndMessage) {
  uint32_t id = 1;
  std::vector<char> message = {'H', 'e', 'l', 'l', 'o'};
  CanFrame frame(id, message);
  ASSERT_TRUE(frame.is_valid());
  ASSERT_EQ(frame.id(), id);
  ASSERT_EQ(frame.message(), message);
  ASSERT_EQ(frame.message().size(), message.size());
  ASSERT_TRUE(frame.is_standard_id());
}

// Test for CanFrame constructor with id extended and message
TEST_F(CanFrameTest, ConstructorWithIdExtendedAndMessage) {
  uint32_t id = 1 << 28;
  std::vector<char> message = {'H', 'e', 'l', 'l', 'o'};
  CanFrame frame(id, message);
  ASSERT_TRUE(frame.is_valid());
  ASSERT_EQ(frame.id(), id);
  ASSERT_EQ(frame.message(), message);
  ASSERT_EQ(frame.message().size(), message.size());
  ASSERT_TRUE(frame.is_extended_id());
}

// Test for CanFrame constructor with id too big and message
TEST_F(CanFrameTest, ConstructorWithIdInvalidAndMessage) {
  uint32_t id = 1 << 29;
  std::vector<char> message = {'H', 'e', 'l', 'l', 'o'};
  CanFrame frame(id, message);
  ASSERT_FALSE(frame.is_valid());
}

TEST_F(CanFrameTest, ConstructorWithIdAndMessageInvalid) {
  uint32_t id = 1 << 29;
  std::vector<char> message = {'H', 'e', 'l', 'l', 'o', ' ',
                               'W', 'o', 'r', 'l', 'd'};
  CanFrame frame(id, message);
  ASSERT_FALSE(frame.is_valid());
}

// Test for CanFrame constructor with id and requested_length
TEST_F(CanFrameTest, ConstructorWithIdAndRequestedLength) {
  uint32_t id = 1;
  uint32_t requested_length = 8;
  CanFrame frame(id, requested_length);
  ASSERT_EQ(frame.flags(), CanFlags::STANDARD_ID | CanFlags::REMOTE_REQUEST);
  ASSERT_TRUE(frame.is_valid());
  ASSERT_EQ(frame.id(), id);
  ASSERT_EQ(frame.flags(), CanFlags::STANDARD_ID | CanFlags::REMOTE_REQUEST);
  ASSERT_EQ(frame.length(), requested_length);
  ASSERT_TRUE(frame.message().empty());
  ASSERT_TRUE(frame.is_remote_request());
}

// Test for CanFrame constructor with id, requested_length, and flags
TEST_F(CanFrameTest, ConstructorWithIdRequestedLengthAndFlagsIncomplete) {
  uint32_t id = 1;
  uint32_t requested_length = 8;
  uint32_t flags = CanFlags::STANDARD_ID;
  CanFrame frame(id, requested_length, flags);
  ASSERT_FALSE(frame.is_valid());
}

TEST_F(CanFrameTest, ConstructorWithIdRequestedLengthAndFlags) {
  uint32_t id = 1;
  uint32_t requested_length = 8;
  uint32_t flags = CanFlags::STANDARD_ID | CanFlags::REMOTE_REQUEST;
  CanFrame frame(id, requested_length, flags);
  ASSERT_TRUE(frame.is_valid());
  ASSERT_EQ(frame.length(), 8);
  ASSERT_EQ(frame.id(), id);
}

// Test for CanFrame constructor with id, message, and flags
TEST_F(CanFrameTest, ConstructorWithIdMessageAndFlags) {
  uint32_t id = 1;
  std::vector<char> message = {'H', 'e', 'l', 'l', 'o'};
  uint32_t flags = CanFlags::EXTENDED_ID;
  CanFrame frame(id, message, flags);
  ASSERT_EQ(frame.message(), message);
  ASSERT_TRUE(frame.is_valid());
  ASSERT_EQ(frame.id(), id);
  ASSERT_EQ(frame.flags(), CanFlags::EXTENDED_ID);
}

TEST_F(CanFrameTest, ConstructorWithIdExtendedMessageAndFlagsStandard) {
  uint32_t id = 1 << 28;
  std::vector<char> message = {'H', 'e', 'l', 'l', 'o'};
  uint32_t flags = CanFlags::STANDARD_ID;
  CanFrame frame(id, message, flags);
  ASSERT_FALSE(frame.is_valid());
}

TEST_F(CanFrameTest, ConstructorWithIdMessageAndFlagsRTR) {
  uint32_t id = 1 << 28;
  std::vector<char> message = {'H', 'e', 'l', 'l', 'o'};
  uint32_t flags = CanFlags::REMOTE_REQUEST;
  CanFrame frame(id, message, flags);
  ASSERT_FALSE(frame.is_valid());
}

TEST_F(CanFrameTest, ConstructorWithIdOnly) {
  uint32_t id = 1 << 28;
  CanFrame frame(id);
  ASSERT_TRUE(frame.is_valid());
  ASSERT_EQ(frame.id(), id);
  ASSERT_TRUE(frame.message().empty());
  ASSERT_EQ(frame.length(), 0);
  ASSERT_TRUE(frame.is_extended_id());
  ASSERT_TRUE(frame.is_remote_request());
}

TEST_F(CanFrameTest, TestEqual) {
  uint32_t id = 1 << 28;
  CanFrame frame1(id);
  CanFrame frame2(id);
  ASSERT_EQ(frame1, frame2);
}

TEST_F(CanFrameTest, TestNotEqual) {
  CanFrame frame1(1 << 28);
  CanFrame frame2(1);
  ASSERT_NE(frame1, frame2);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}