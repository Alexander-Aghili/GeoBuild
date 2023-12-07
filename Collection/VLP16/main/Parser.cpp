#include <Parser.h>


ParsedPacket parsePacket(const NakedPacket* nakedPacket) {
    ParsedPacket parsedPacket;

    std::memcpy(parsedPacket.udpHeader, nakedPacket->rawData, sizeof(parsedPacket.udpHeader));

    for (int i = 0; i < NUM_DATABLOCKS; ++i) {
        std::memcpy(&parsedPacket.dataBlocks[i], nakedPacket->rawData + sizeof(parsedPacket.udpHeader) + i * sizeof(DataBlock), sizeof(DataBlock));
    }

    std::memcpy(&parsedPacket.timestamp, nakedPacket->rawData + sizeof(parsedPacket.udpHeader) + NUM_DATABLOCKS * sizeof(DataBlock), sizeof(parsedPacket.timestamp));
    std::memcpy(&parsedPacket.factoryBytes, nakedPacket->rawData + sizeof(parsedPacket.udpHeader) + NUM_DATABLOCKS * sizeof(DataBlock) + sizeof(parsedPacket.timestamp), sizeof(parsedPacket.factoryBytes));

    return parsedPacket;
}