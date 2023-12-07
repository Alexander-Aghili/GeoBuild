#include <Parser.h>
#include <gtest/gtest.h>

TEST(ParserTest, ParsePacket) {
  // Create a mock NakedPacket object
  ParsedPacket mockPacket;
  memset(&mockPacket, 0, sizeof(mockPacket));

  // Set some sample values for the UDP header
  uint8_t sampleUdpHeader[42] = {
    0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
    0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10,
    0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18,
    0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x20,
    0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28,
    0x29, 0x2A };
  memcpy(mockPacket.udpHeader, sampleUdpHeader, sizeof(sampleUdpHeader));

  // Set some sample values for each data block
  for (int i = 0; i < NUM_DATABLOCKS; ++i) {
    DataBlock& dataBlock = mockPacket.dataBlocks[i];
    dataBlock.flag = 0x1234;
    dataBlock.azimuth = 0x5678;
    for (int j = 0; j < 32; ++j) {
      dataBlock.dataPoints[j][0] = j;
      dataBlock.dataPoints[j][1] = i;
      dataBlock.dataPoints[j][2] = 0;
    }
  }

  // Set some sample values for timestamp and factory bytes
  uint32_t sampleTimestamp = 0x9ABCDEF0;
  uint16_t sampleFactoryBytes = 0xABCD;
  memcpy(&(mockPacket.timestamp), &sampleTimestamp, sizeof(sampleTimestamp));
  memcpy(&(mockPacket.factoryBytes), &sampleFactoryBytes, sizeof(sampleFactoryBytes));


  NakedPacket mockNakedPacket;

  memcpy(&mockNakedPacket, &mockPacket, 1248);

  // Parse the NakedPacket object
  ParsedPacket parsedPacket = parsePacket(&mockNakedPacket);

  // Verify the parsed UDP header
  ASSERT_EQ(memcmp(parsedPacket.udpHeader, sampleUdpHeader, sizeof(sampleUdpHeader)), 0);

  // Verify the parsed data blocks
  for (int i = 0; i < NUM_DATABLOCKS; ++i) {
    ASSERT_EQ(parsedPacket.dataBlocks[i].flag, 0x1234);
    ASSERT_EQ(parsedPacket.dataBlocks[i].azimuth, 0x5678);
    for (int j = 0; j < 32; ++j) {
      ASSERT_EQ(parsedPacket.dataBlocks[i].dataPoints[j][0], j);
      ASSERT_EQ(parsedPacket.dataBlocks[i].dataPoints[j][1], i);
      ASSERT_EQ(parsedPacket.dataBlocks[i].dataPoints[j][2], 0);
    }
  }

  // Verify the parsed timestamp and factory bytes
  ASSERT_EQ(parsedPacket.timestamp, sampleTimestamp);
  ASSERT_EQ(parsedPacket.factoryBytes, sampleFactoryBytes);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}