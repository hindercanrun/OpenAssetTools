#include "AssetDumperGfxWorld.h"

using namespace T6;

bool AssetDumperGfxWorld::ShouldDump(XAssetInfo<GfxWorld>* asset)
{
    return true;
}

void AssetDumperGfxWorld::DumpAsset(AssetDumpingContext& context, XAssetInfo<GfxWorld>* asset)
{
    const auto* gfxWorld = asset->Asset();
    const auto assetFile = context.OpenAssetFile(asset->m_name + "_gfxworld.json");

    if (!assetFile)
    {
        std::cerr << std::format("WARNING: failed to dump {}", asset->m_name);
        return;
    }

    auto& stream = *assetFile;
    stream.write(gfxWorld->name, gfxWorld->materialMemoryCount);
}
