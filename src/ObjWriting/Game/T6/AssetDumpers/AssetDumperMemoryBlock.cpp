#include "AssetDumperMemoryBlock.h"

using namespace T6;

bool AssetDumperMemoryBlock::ShouldDump(XAssetInfo<MemoryBlock>* asset)
{
    return true;
}

void AssetDumperMemoryBlock::DumpAsset(AssetDumpingContext& context, XAssetInfo<MemoryBlock>* asset)
{
    const auto* memoryBlock = asset->Asset();
    const auto assetFile = context.OpenAssetFile(asset->m_name);

    if (!assetFile)
        return;

    auto& stream = *assetFile;
    stream.write(memoryBlock->name, (int)memoryBlock->data.mainData);
}
