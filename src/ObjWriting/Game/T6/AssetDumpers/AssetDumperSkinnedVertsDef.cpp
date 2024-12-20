#include "AssetDumperSkinnedVertsDef.h"

using namespace T6;

std::string AssetDumperSkinnedVertsDef::GetFileNameForAsset(const std::string& assetName)
{
    return std::format("skinnedverts/{}", assetName);
}

bool AssetDumperSkinnedVertsDef::ShouldDump(XAssetInfo<SkinnedVertsDef>* asset)
{
    return true;
}

void AssetDumperSkinnedVertsDef::DumpAsset(AssetDumpingContext& context, XAssetInfo<SkinnedVertsDef>* asset)
{
    const auto* skinnedVertsDef = asset->Asset();
    const auto assetFile = context.OpenAssetFile(GetFileNameForAsset(asset->m_name));

    if (!assetFile)
    {
        std::cerr << std::format("WARNING: failed to dump {}", asset->m_name);
        return;
    }

    auto& stream = *assetFile;
    stream.write(skinnedVertsDef->name, skinnedVertsDef->maxSkinnedVerts);
}
