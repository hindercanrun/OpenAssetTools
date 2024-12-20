#include "AssetDumperFootstepTableDef.h"

using namespace T6;

std::string AssetDumperFootstepTableDef::GetFileNameForAsset(const std::string& assetName)
{
    return std::format("footsteptable/{}", assetName);
}

bool AssetDumperFootstepTableDef::ShouldDump(XAssetInfo<FootstepTableDef>* asset)
{
    return true;
}

void AssetDumperFootstepTableDef::DumpAsset(AssetDumpingContext& context, XAssetInfo<FootstepTableDef>* asset)
{
    const auto* footstepTableDef = asset->Asset();
    const auto assetFile = context.OpenAssetFile(GetFileNameForAsset(asset->m_name));

    if (!assetFile)
    {
        std::cerr << std::format("WARNING: failed to dump {}", asset->m_name);
        return;
    }

    auto& stream = *assetFile;
    stream.write(footstepTableDef->name, (std::streamsize)footstepTableDef->sndAliasTable);//this doesnt even work but i cant be bothered to properly fix it
}
