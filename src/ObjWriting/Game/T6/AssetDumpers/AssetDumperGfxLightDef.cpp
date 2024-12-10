#include "AssetDumperGfxLightDef.h"

using namespace T6;

std::string AssetDumperGfxLightDef::GetFileNameForAsset(const std::string& assetName)
{
    return std::format("lights/{}.json", assetName);
}

bool AssetDumperGfxLightDef::ShouldDump(XAssetInfo<GfxLightDef>* asset)
{
    return true;
}

void AssetDumperGfxLightDef::DumpAsset(AssetDumpingContext& context, XAssetInfo<GfxLightDef>* asset)
{
    const auto* gfxLightDef = asset->Asset();
    const auto assetFile = context.OpenAssetFile(GetFileNameForAsset(asset->m_name));

    if (!assetFile)
        return;

    auto& stream = *assetFile;
    stream.write(gfxLightDef->name, gfxLightDef->attenuation.samplerState);
}
