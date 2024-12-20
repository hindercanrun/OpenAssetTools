#include "AssetDumperMenuDef.h"

#include <filesystem>
#include <string>

using namespace T6;

std::string AssetDumperMenuDef::GetFileNameForAsset(const std::string& assetName)
{
    return std::format("ui/{}.menu", assetName);
}

bool AssetDumperMenuDef::ShouldDump(XAssetInfo<menuDef_t>* asset)
{
    return true;
}

void AssetDumperMenuDef::DumpAsset(AssetDumpingContext& context, XAssetInfo<menuDef_t>* asset)
{
    const auto* menuDef = asset->Asset();
    const auto assetFile = context.OpenAssetFile(GetFileNameForAsset(asset->m_name));

    if (!assetFile)
    {
        std::cerr << std::format("WARNING: failed to dump {}", asset->m_name);
        return;
    }

    auto& stream = *assetFile;
    stream.write(menuDef->window.name, menuDef->itemCount);
}
