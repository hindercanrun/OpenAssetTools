#define NOMINMAX
#include "AssetDumperGfxWorld.h"

#include <algorithm>

using namespace T6;

bool AssetDumperGfxWorld::ShouldDump(XAssetInfo<GfxWorld>* asset)
{
    return true;
}

void AssetDumperGfxWorld::DumpAsset(AssetDumpingContext& context, XAssetInfo<GfxWorld>* asset)
{
    const auto* gfxWorld = asset->Asset();
    const auto assetFile = context.OpenAssetFile(asset->m_name + ".gfxworld");

    if (!assetFile)
        return;

    auto& stream = *assetFile;
    stream.write(gfxWorld->name, gfxWorld->materialMemoryCount);
}
