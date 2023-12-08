#include <Parser.h>


ParsedPacket parsePacket(const NakedPacket* nakedPacket) {
    spdlog::info("Parsing Packet");

    ParsedPacket parsedPacket;

    std::memcpy(parsedPacket.udpHeader, nakedPacket->rawData, sizeof(parsedPacket.udpHeader));

    for (int i = 0; i < NUM_DATABLOCKS; ++i) {
        std::memcpy(&parsedPacket.dataBlocks[i], nakedPacket->rawData + UDP_HEADER + i * sizeof(DataBlock), sizeof(DataBlock));
    }

    std::memcpy(&parsedPacket.timestamp, nakedPacket->rawData + UDP_HEADER + NUM_DATABLOCKS * sizeof(DataBlock), sizeof(parsedPacket.timestamp));
    std::memcpy(&parsedPacket.factoryBytes, nakedPacket->rawData + UDP_HEADER + NUM_DATABLOCKS * sizeof(DataBlock) + sizeof(parsedPacket.timestamp), sizeof(parsedPacket.factoryBytes));

    return parsedPacket;
}