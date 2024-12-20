#include "AssetDumperGameWorldSp.h"

using namespace T6;

bool AssetDumperGameWorldSp::ShouldDump(XAssetInfo<GameWorldSp>* asset)
{
    return true;
}

void AssetDumperGameWorldSp::DumpAsset(AssetDumpingContext& context, XAssetInfo<GameWorldSp>* asset)
{
    const auto* gameWorldSp = asset->Asset();
    const auto assetFile = context.OpenAssetFile(asset->m_name + "_gameworldsp.json");

    if (!assetFile)
    {
        std::cerr << std::format("WARNING: failed to dump {}", asset->m_name);
        return;
    }

    auto& stream = *assetFile;
    stream.write(gameWorldSp->name, gameWorldSp->path.nodeCount);
}
