#define NOMINMAX
#include "AssetDumperFont.h"

#include <algorithm>

using namespace T6;

std::string AssetDumperFont::GetFileNameForAsset(const std::string& assetName)
{
    return std::format("fonts/{}.json", assetName);
}

bool AssetDumperFont::ShouldDump(XAssetInfo<Font_s>* asset)
{
    return true;
}

void AssetDumperFont::DumpAsset(AssetDumpingContext& context, XAssetInfo<Font_s>* asset)
{
    const auto* gfxLightDef = asset->Asset();
    const auto assetFile = context.OpenAssetFile(GetFileNameForAsset(asset->m_name));

    if (!assetFile)
        return;

    auto& stream = *assetFile;
    stream.write(gfxLightDef->fontName, gfxLightDef->pixelHeight);
}
