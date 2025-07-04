#pragma once
#include "Game/IW5/IW5.h"
#include "Zone/ZoneTypes.h"

#include <cstdint>
#include <string>

namespace IW5
{
    class ZoneConstants final
    {
        ZoneConstants() = default;

    public:
        static constexpr const char* MAGIC_SIGNED_INFINITY_WARD = "IWff0100";
        static constexpr const char* MAGIC_SIGNED_OAT = "ABff0100";
        static constexpr const char* MAGIC_UNSIGNED = "IWffu100";
        static constexpr int ZONE_VERSION = 1;

        static_assert(std::char_traits<char>::length(MAGIC_SIGNED_INFINITY_WARD) == sizeof(ZoneHeader::m_magic));
        static_assert(std::char_traits<char>::length(MAGIC_SIGNED_OAT) == sizeof(ZoneHeader::m_magic));
        static_assert(std::char_traits<char>::length(MAGIC_UNSIGNED) == sizeof(ZoneHeader::m_magic));

        static constexpr const char* MAGIC_AUTH_HEADER = "IWffs100";
        inline static const uint8_t RSA_PUBLIC_KEY_INFINITY_WARD[]{
            0x30, 0x82, 0x01, 0x0A, 0x02, 0x82, 0x01, 0x01, 0x00, 0xA5, 0x86, 0xCC, 0x18, 0xA9, 0x12, 0x17, 0x4F, 0x3A, 0xC9, 0x0C, 0xD2, 0x38, 0x5D,
            0xDB, 0x67, 0x62, 0xA4, 0xE3, 0xD4, 0x42, 0x05, 0x8A, 0x57, 0x0C, 0x31, 0x4E, 0x19, 0xE4, 0xBA, 0x89, 0x73, 0x13, 0xDB, 0x72, 0x25, 0x63,
            0xB1, 0x2F, 0xD7, 0xF1, 0x08, 0x48, 0x34, 0x06, 0xD7, 0x84, 0x5F, 0xC8, 0xCF, 0x2F, 0xB6, 0xA3, 0x5A, 0x8F, 0x7E, 0xAA, 0x9D, 0x51, 0xE7,
            0x0F, 0xB9, 0x07, 0xB7, 0x30, 0x91, 0x04, 0x39, 0x9C, 0xDC, 0x1C, 0xF1, 0x16, 0xCB, 0x96, 0x10, 0xEB, 0x38, 0xB1, 0x3B, 0xBA, 0x42, 0xE3,
            0xE2, 0x78, 0xBD, 0x77, 0x82, 0x1A, 0x2B, 0x54, 0x27, 0x0A, 0xF7, 0x66, 0x06, 0xAD, 0x46, 0x39, 0xC0, 0xEB, 0xB5, 0xC2, 0x27, 0xDD, 0x2C,
            0x08, 0x62, 0x2C, 0x0B, 0xC4, 0x00, 0x0D, 0xCB, 0xAD, 0x22, 0x67, 0x01, 0xA6, 0x92, 0x9C, 0x00, 0xAF, 0x9D, 0x55, 0xCC, 0x68, 0xEC, 0x39,
            0x49, 0x85, 0x7E, 0x2C, 0x98, 0xCF, 0x4C, 0x12, 0x8D, 0xED, 0xC7, 0x1D, 0x21, 0x54, 0x9C, 0x2F, 0xC9, 0x54, 0x36, 0x08, 0xA9, 0x67, 0xEE,
            0x91, 0xE6, 0xD9, 0xB1, 0xFA, 0xA9, 0x2B, 0x88, 0xAD, 0x2A, 0xD0, 0xAA, 0x28, 0xF9, 0x47, 0xA6, 0x0F, 0xCF, 0x55, 0x4C, 0x9B, 0x26, 0x41,
            0x89, 0x76, 0x11, 0xFD, 0x1B, 0x83, 0xE4, 0xE8, 0x8E, 0x7E, 0xB4, 0x03, 0xA3, 0x29, 0xDD, 0x4F, 0xAC, 0x99, 0xBE, 0x7C, 0xD3, 0xFD, 0x14,
            0x28, 0x1C, 0x59, 0x69, 0xE0, 0x79, 0x5F, 0x4B, 0xDA, 0x6B, 0xAB, 0x48, 0x4E, 0x28, 0x39, 0x84, 0xC6, 0x2B, 0xC6, 0x20, 0x05, 0xDB, 0x05,
            0x21, 0xC3, 0xE1, 0xD4, 0x20, 0x28, 0xDD, 0x3A, 0x4D, 0x51, 0xE7, 0x49, 0x8A, 0x49, 0xEF, 0xF5, 0xDA, 0xDA, 0x7D, 0x5D, 0xA8, 0x0B, 0xA1,
            0x77, 0xCD, 0x62, 0x7D, 0x9D, 0x40, 0x26, 0x44, 0x4B, 0x3B, 0x0A, 0x89, 0x02, 0x03, 0x01, 0x00, 0x01,
        };

        static constexpr size_t AUTHED_CHUNK_SIZE = 0x2000;
        static constexpr unsigned AUTHED_CHUNK_COUNT_PER_GROUP = 256;

        static constexpr unsigned OFFSET_BLOCK_BIT_COUNT = 4u;
        static constexpr block_t INSERT_BLOCK = XFILE_BLOCK_VIRTUAL;
    };
} // namespace IW5
