#include "AssetDumperGameWorldMp.h"

using namespace T6;

bool AssetDumperGameWorldMp::ShouldDump(XAssetInfo<GameWorldMp>* asset)
{
    return true;
}

void AssetDumperGameWorldMp::DumpAsset(AssetDumpingContext& context, XAssetInfo<GameWorldMp>* asset)
{
    const auto* gameWorldMp = asset->Asset();
    const auto assetFile = context.OpenAssetFile(asset->m_name + "_gameworldmp.json");

    if (!assetFile)
    {
        std::cerr << std::format("WARNING: failed to dump {}", asset->m_name);
        return;
    }

    auto& stream = *assetFile;
    stream.write(gameWorldMp->name, gameWorldMp->path.nodeCount);
}
