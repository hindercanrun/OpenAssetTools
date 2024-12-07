#define NOMINMAX
#include "AssetDumperGameWorldSp.h"

#include <algorithm>

using namespace T6;

bool AssetDumperGameWorldSp::ShouldDump(XAssetInfo<GameWorldSp>* asset)
{
    return true;
}

void AssetDumperGameWorldSp::DumpAsset(AssetDumpingContext& context, XAssetInfo<GameWorldSp>* asset)
{
    const auto* gameWorldSp = asset->Asset();
    const auto assetFile = context.OpenAssetFile(asset->m_name + ".gameworldsp");

    if (!assetFile)
        return;

    auto& stream = *assetFile;
    stream.write(gameWorldSp->name, /*std::max(gameWorldSp->path - 1,*/ 0);
}
