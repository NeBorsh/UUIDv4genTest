#include <random>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <chrono>

std::string generate_uuid_v4() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<uint32_t> dis(0, std::numeric_limits<uint32_t>::max());

    uint32_t part1 = dis(gen);
    uint32_t part2 = dis(gen) & 0x0FFF | 0x4000;
    uint32_t part3 = dis(gen) & 0x3FFF | 0x8000;
    uint32_t part4 = dis(gen);
    uint32_t part5 = dis(gen);

    std::stringstream ss;
    ss << std::hex << std::setfill('0');
    ss << std::setw(8) << part1 << '-';
    ss << std::setw(4) << part2 << '-';
    ss << std::setw(4) << part3 << '-';
    ss << std::setw(4) << (part4 >> 16) << '-';
    ss << std::setw(4) << (part4 & 0xFFFF);
    ss << std::setw(8) << part5;

    return ss.str();
}
