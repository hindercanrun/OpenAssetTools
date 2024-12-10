#include "AssetDumperDestructibleDef.h"

using namespace T6;

bool AssetDumperDestructibleDef::ShouldDump(XAssetInfo<DestructibleDef>* asset)
{
    return true;
}

void AssetDumperDestructibleDef::DumpAsset(AssetDumpingContext& context, XAssetInfo<DestructibleDef>* asset)
{
    const auto* destructibleDef = asset->Asset();
    const auto assetFile = context.OpenAssetFile(asset->m_name);

    if (!assetFile)
        return;

    auto& stream = *assetFile;
    stream.write(destructibleDef->name, destructibleDef->model->contents);
}
