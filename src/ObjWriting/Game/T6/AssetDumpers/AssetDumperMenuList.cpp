#include "AssetDumperMenuList.h"

#include <cassert>
#include <filesystem>
#include <set>
#include <sstream>

namespace fs = std::filesystem;

using namespace T6;

std::string AssetDumperMenuList::GetFileNameForAsset(const std::string& assetName)
{
    return std::format("ui/{}", assetName);
}

bool AssetDumperMenuList::ShouldDump(XAssetInfo<MenuList>* asset)
{
    return true;
}

void AssetDumperMenuList::DumpAsset(AssetDumpingContext& context, XAssetInfo<MenuList>* asset)
{
    const auto* menuList = asset->Asset();
    const auto assetFile = context.OpenAssetFile(GetFileNameForAsset(asset->m_name));

    if (!assetFile)
        return;

    auto& stream = *assetFile;
    stream.write(menuList->name, menuList->menuCount);
}
