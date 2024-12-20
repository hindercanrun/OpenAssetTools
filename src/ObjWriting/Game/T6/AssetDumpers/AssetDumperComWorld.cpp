#include "AssetDumperComWorld.h"

using namespace T6;

bool AssetDumperComWorld::ShouldDump(XAssetInfo<ComWorld>* asset)
{
    return true;
}

void AssetDumperComWorld::DumpAsset(AssetDumpingContext& context, XAssetInfo<ComWorld>* asset)
{
    const auto* comWorld = asset->Asset();
    const auto assetFile = context.OpenAssetFile(asset->m_name + "_comworld.json");

    if (!assetFile)
    {
        std::cerr << std::format("WARNING: failed to dump {}", asset->m_name);
        return;
    }

    auto& stream = *assetFile;
    stream.write(comWorld->name, comWorld->primaryLightCount);
}
