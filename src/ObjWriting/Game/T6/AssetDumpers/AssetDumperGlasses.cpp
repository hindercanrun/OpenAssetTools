#include "AssetDumperGlasses.h"

using namespace T6;

std::string AssetDumperGlasses::GetFileNameForAsset(const std::string& assetName)
{
    return std::format("glass/{}.json", assetName);
}

bool AssetDumperGlasses::ShouldDump(XAssetInfo<Glasses>* asset)
{
    return true;
}

void AssetDumperGlasses::DumpAsset(AssetDumpingContext& context, XAssetInfo<Glasses>* asset)
{
    const auto* glasses = asset->Asset();
    const auto assetFile = context.OpenAssetFile(GetFileNameForAsset(asset->m_name));

    if (!assetFile)
    {
        std::cerr << std::format("WARNING: failed to dump {}", asset->m_name);
        return;
    }

    auto& stream = *assetFile;
    stream.write(glasses->name, glasses->glasses->index);
}
