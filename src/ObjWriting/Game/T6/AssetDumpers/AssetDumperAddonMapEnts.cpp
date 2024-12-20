#include "AssetDumperAddonMapEnts.h"

using namespace T6;

bool AssetDumperAddonMapEnts::ShouldDump(XAssetInfo<AddonMapEnts>* asset)
{
    return true;
}

void AssetDumperAddonMapEnts::DumpAsset(AssetDumpingContext& context, XAssetInfo<AddonMapEnts>* asset)
{
    const auto* addonMapEnts = asset->Asset();
    const auto assetFile = context.OpenAssetFile(asset->m_name);

    if (!assetFile)
    {
        std::cerr << std::format("WARNING: failed to dump {}", asset->m_name);
        return;
    }

    auto& stream = *assetFile;
    stream.write(addonMapEnts->entityString, std::max(addonMapEnts->numEntityChars - 1, 0));
}
