#include "AssetDumperMapEnts.h"

using namespace T6;

bool AssetDumperMapEnts::ShouldDump(XAssetInfo<MapEnts>* asset)
{
    return true;
}

void AssetDumperMapEnts::DumpAsset(AssetDumpingContext& context, XAssetInfo<MapEnts>* asset)
{
    const auto* mapEnts = asset->Asset();
    const auto assetFile = context.OpenAssetFile(asset->m_name + ".ents");

    if (!assetFile)
    {
        std::cerr << std::format("WARNING: failed to dump {}", asset->m_name);
        return;
    }

    auto& stream = *assetFile;
    stream.write(mapEnts->entityString, mapEnts->numEntityChars);
}
