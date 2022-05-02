#pragma once

#include "Game/IW4/IW4.h"

namespace IW4
{
    inline infoParm_t infoParms[]
    {
        {"bark", 0x0, 0x100000, 0x0, 0x0},
        {"brick", 0x0, 0x200000, 0x0, 0x0},
        {"carpet", 0x0, 0x300000, 0x0, 0x0},
        {"cloth", 0x0, 0x400000, 0x0, 0x0},
        {"concrete", 0x0, 0x500000, 0x0, 0x0},
        {"dirt", 0x0, 0x600000, 0x0, 0x0},
        {"flesh", 0x0, 0x700000, 0x0, 0x0},
        {"foliage", 0x1, 0x800000, 0x2, 0x0},
        {"glass", 0x1, 0x900000, 0x10, 0x0},
        {"grass", 0x0, 0xa00000, 0x0, 0x0},
        {"gravel", 0x0, 0xb00000, 0x0, 0x0},
        {"ice", 0x0, 0xc00000, 0x0, 0x0},
        {"metal", 0x0, 0xd00000, 0x0, 0x0},
        {"mud", 0x0, 0xe00000, 0x0, 0x0},
        {"paper", 0x0, 0xf00000, 0x0, 0x0},
        {"plaster", 0x0, 0x1000000, 0x0, 0x0},
        {"rock", 0x0, 0x1100000, 0x0, 0x0},
        {"sand", 0x0, 0x1200000, 0x0, 0x0},
        {"snow", 0x0, 0x1300000, 0x0, 0x0},
        {"water", 0x1, 0x1400000, 0x20, 0x0},
        {"wood", 0x0, 0x1500000, 0x0, 0x0},
        {"asphalt", 0x0, 0x1600000, 0x0, 0x0},
        {"ceramic", 0x0, 0x1700000, 0x0, 0x0},
        {"plastic", 0x0, 0x1800000, 0x0, 0x0},
        {"rubber", 0x0, 0x1900000, 0x0, 0x0},
        {"cushion", 0x0, 0x1a00000, 0x0, 0x0},
        {"fruit", 0x0, 0x1b00000, 0x0, 0x0},
        {"paintedmetal", 0x0, 0x1c00000, 0x0, 0x0},
        {"riotshield", 0x0, 0x1d00000, 0x0, 0x0},
        {"slush", 0x0, 0x1e00000, 0x0, 0x0},
        {"opaqueglass", 0x0, 0x900000, 0x0, 0x0},
        {"clipmissile", 0x1, 0x0, 0x80, 0x0},
        {"ai_nosight", 0x1, 0x0, 0x1000, 0x0},
        {"clipshot", 0x1, 0x0, 0x2000, 0x0},
        {"playerclip", 0x1, 0x0, 0x10000, 0x0},
        {"monsterclip", 0x1, 0x0, 0x20000, 0x0},
        {"aiclipallowdeath", 0x1, 0x0, 0x4, 0x0},
        {"vehicleclip", 0x1, 0x0, 0x200, 0x0},
        {"itemclip", 0x1, 0x0, 0x400, 0x0},
        {"nodrop", 0x1, 0x0, 0x80000000, 0x0},
        {"nonsolid", 0x1, 0x4000, 0x0, 0x0},
        {"detail", 0x0, 0x0, 0x8000000, 0x0},
        {"structural", 0x0, 0x0, 0x10000000, 0x0},
        {"portal", 0x1, 0x80000000, 0x0, 0x0},
        {"canshootclip", 0x0, 0x0, 0x40, 0x0},
        {"origin", 0x1, 0x0, 0x0, 0x4},
        {"sky", 0x0, 0x4, 0x800, 0x0},
        {"nocastshadow", 0x0, 0x40000, 0x0, 0x0},
        {"physicsGeom", 0x0, 0x0, 0x0, 0x400},
        {"lightPortal", 0x0, 0x0, 0x0, 0x2000},
        {"outdoorBounds", 0x0, 0x0, 0x0, 0x8000},
        {"slick", 0x0, 0x2, 0x0, 0x0},
        {"noimpact", 0x0, 0x10, 0x0, 0x0},
        {"nomarks", 0x0, 0x20, 0x0, 0x0},
        {"nopenetrate", 0x0, 0x100, 0x0, 0x0},
        {"ladder", 0x0, 0x8, 0x0, 0x0},
        {"nodamage", 0x0, 0x1, 0x0, 0x0},
        {"mantleOn", 0x0, 0x2000000, 0x1000000, 0x0},
        {"mantleOver", 0x0, 0x4000000, 0x1000000, 0x0},
        {"stairs", 0x0, 0x200, 0x0, 0x0},
        {"soft", 0x0, 0x1000, 0x0, 0x0},
        {"nosteps", 0x0, 0x2000, 0x0, 0x0},
        {"nodraw", 0x0, 0x80, 0x0, 0x0},
        {"nolightmap", 0x0, 0x400, 0x0, 0x0},
        {"nodlight", 0x0, 0x20000, 0x0, 0x0}
    };

    inline const char* surfaceTypeNames[]
    {
        "default",
        "bark",
        "brick",
        "carpet",
        "cloth",
        "concrete",
        "dirt",
        "flesh",
        "foliage",
        "glass",
        "grass",
        "gravel",
        "ice",
        "metal",
        "mud",
        "paper",
        "plaster",
        "rock",
        "sand",
        "snow",
        "water",
        "wood",
        "asphalt",
        "ceramic",
        "plastic",
        "rubber",
        "cushion",
        "fruit",
        "paintedmetal",
        "riotshield",
        "slush"
    };
    static_assert(std::extent_v<decltype(surfaceTypeNames)> == SURF_TYPE_NUM);


    enum class BlendFunc_e
    {
        UNKNOWN,
        CUSTOM,
        REPLACE,
        BLEND,
        ADD,
        MULTIPLY,
        SCREEN_ADD,

        COUNT
    };

    inline const char* GdtBlendFuncNames[]
    {
        "",
        "Custom",
        "Replace*",
        "Blend",
        "Add",
        "Multiply",
        "Screen Add"
    };
    static_assert(std::extent_v<decltype(GdtBlendFuncNames)> == static_cast<size_t>(BlendFunc_e::COUNT));

    enum class BlendOp_e
    {
        UNKNOWN,
        DISABLE,
        ADD,
        SUBTRACT,
        REV_SUBTRACT,
        MIN,
        MAX,

        COUNT
    };

    inline const char* GdtBlendOpNames[]
    {
        "",
        "Disable",
        "Add*",
        "Subtract",
        "RevSubtract",
        "Min",
        "Max"
    };
    static_assert(std::extent_v<decltype(GdtBlendOpNames)> == static_cast<size_t>(BlendOp_e::COUNT));

    enum class CustomBlendFunc_e
    {
        UNKNOWN,
        DISABLED,
        ZERO,
        ONE,
        SRC_COLOR,
        INV_SRC_COLOR,
        SRC_ALPHA,
        INV_SRC_ALPHA,
        DST_ALPHA,
        INV_DST_ALPHA,
        DEST_COLOR,
        INV_DST_COLOR,

        COUNT
    };

    inline const char* GdtCustomBlendFuncNames[]
    {
        "",
        "Disable",
        "Zero",
        "One*",
        "SrcColor",
        "InvSrcColor",
        "SrcAlpha",
        "InvSrcAlpha",
        "DestAlpha",
        "InvDestAlpha",
        "DestColor",
        "InvDestColor"
    };
    static_assert(std::extent_v<decltype(GdtCustomBlendFuncNames)> == static_cast<size_t>(CustomBlendFunc_e::COUNT));

    enum class AlphaTest_e
    {
        UNKNOWN,
        ALWAYS,
        GT0,
        LT128,
        GE128,

        COUNT
    };

    inline const char* GdtAlphaTestNames[]
    {
        "",
        "Always*",
        "GT0",
        "LT128",
        "GE128"
    };
    static_assert(std::extent_v<decltype(GdtAlphaTestNames)> == static_cast<size_t>(AlphaTest_e::COUNT));

    enum class DepthTest_e
    {
        UNKNOWN,
        LESS_EQUAL,
        LESS,
        EQUAL,
        ALWAYS,
        DISABLE,

        COUNT
    };

    inline const char* GdtDepthTestNames[]
    {
        "",
        "LessEqual*",
        "Less",
        "Equal",
        "Always",
        "Disable"
    };
    static_assert(std::extent_v<decltype(GdtDepthTestNames)> == static_cast<size_t>(DepthTest_e::COUNT));

    enum class StateBitsEnabledStatus_e
    {
        UNKNOWN,
        ENABLED,
        DISABLED,

        COUNT
    };

    inline const char* GdtStateBitsEnabledStatusNames[]
    {
        "",
        "Enable",
        "Disable"
    };
    static_assert(std::extent_v<decltype(GdtStateBitsEnabledStatusNames)> == static_cast<size_t>(StateBitsEnabledStatus_e::COUNT));

    inline const char* GdtStateBitsOnOffStatusNames[]
    {
        "",
        "On",
        "Off"
    };
    static_assert(std::extent_v<decltype(GdtStateBitsOnOffStatusNames)> == static_cast<size_t>(StateBitsEnabledStatus_e::COUNT));

    enum class CullFace_e
    {
        UNKNOWN,
        NONE,
        BACK,
        FRONT,

        COUNT
    };

    inline const char* GdtCullFaceNames[]
    {
        "",
        "None",
        "Back*",
        "Front"
    };
    static_assert(std::extent_v<decltype(GdtCullFaceNames)> == static_cast<size_t>(CullFace_e::COUNT));

    enum class PolygonOffset_e
    {
        UNKNOWN,
        OFFSET_0,
        OFFSET_1,
        OFFSET_2,
        OFFSET_SHADOW_MAP,

        COUNT
    };

    inline const char* GdtPolygonOffsetNames[]
    {
        "",
        "0",
        "1",
        "2",
        "shadowMap"
    };
    static_assert(std::extent_v<decltype(GdtPolygonOffsetNames)> == static_cast<size_t>(PolygonOffset_e::COUNT));
}
