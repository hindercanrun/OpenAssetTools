#include "AssetDumperClipMap.h"

#include <algorithm>

using namespace T6;

bool AssetDumperClipMap::ShouldDump(XAssetInfo<clipMap_t>* asset)
{
    return true;
}

void AssetDumperClipMap::DumpAsset(AssetDumpingContext& context, XAssetInfo<clipMap_t>* asset)
{
    const auto* clipMap = asset->Asset();
    const auto assetFile = context.OpenAssetFile(asset->m_name + "_clipmap.json");

    if (!assetFile)
        return;

    auto& stream = *assetFile;
    stream.write(clipMap->name, clipMap->numStaticModels + clipMap->checksum);
}
