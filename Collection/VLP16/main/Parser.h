#pragma once

#include <cstdint>
#include <iostream>
#include <cstring>

#include <spdlog/spdlog.h>

#define NUM_DATABLOCKS 12
#define UDP_HEADER 42

#define NUM_DATAPOINTS 32
#define DATAPOINT 3

#define TOTAL_BYTES 1248

typedef struct {
    uint16_t flag;
    uint16_t azimuth;
    uint8_t dataPoints[NUM_DATAPOINTS][DATAPOINT];
} DataBlock;

typedef struct {
    uint8_t udpHeader[UDP_HEADER];
    DataBlock dataBlocks[NUM_DATABLOCKS];
    uint32_t timestamp;
    uint16_t factoryBytes;
} ParsedPacket;

typedef struct {
    uint8_t rawData[TOTAL_BYTES];
} NakedPacket;

/**
 * Parses a NakedPacket object into a ParsedPacket object.
 *
 * This function extracts information from the provided NakedPacket object and organizes
 * it into a ParsedPacket structure based on the specified data structure.
 *
 * @cite https://velodynelidar.com/wp-content/uploads/2019/12/63-9243-Rev-E-VLP-16-User-Manual.pdf
 * @cite Chapter 9 - Sensor Data
 * 
 * 
 * @param nakedPacket The NakedPacket object to be parsed.
 * @return A ParsedPacket object containing the extracted information.
 */
ParsedPacket parsePacket(const NakedPacket* nakedPacket);