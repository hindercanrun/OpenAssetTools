#include "AssetDumperXAnimParts.h"

using namespace T6;

std::string AssetDumperXAnimParts::GetFileNameForAsset(const std::string& assetName)
{
    return std::format("xanim/{}", assetName);
}

bool AssetDumperXAnimParts::ShouldDump(XAssetInfo<XAnimParts>* asset)
{
    return true;
}

void AssetDumperXAnimParts::DumpAsset(AssetDumpingContext& context, XAssetInfo<XAnimParts>* asset)
{
    const auto* animParts = asset->Asset();
    const auto assetFile = context.OpenAssetFile(GetFileNameForAsset(asset->m_name));

    if (!assetFile)
    {
        return;
    }

    auto& stream = *assetFile;
    // this a big not working thing
    stream.write(animParts->name, animParts->numframes);
}
