#include "AssetDumperMaterial.h"

#include "Game/T6/Material/JsonMaterialWriter.h"
#include "Game/T6/Material/MaterialConstantZoneState.h"

#include <algorithm>
#include <format>
#include <ranges>

using namespace T6;

std::string AssetDumperMaterial::GetFileNameForAsset(const std::string& assetName)
{
    std::string sanitizedFileName(assetName);
    if (sanitizedFileName[0] == '*')
    {
        std::ranges::replace(sanitizedFileName, '*', '_');
        const auto parenthesisPos = sanitizedFileName.find('(');
        if (parenthesisPos != std::string::npos)
            sanitizedFileName.erase(parenthesisPos);
        sanitizedFileName = "generated/" + sanitizedFileName;
    }

    return std::format("materials/{}.json", sanitizedFileName);
}

bool AssetDumperMaterial::ShouldDump(XAssetInfo<Material>* asset)
{
    return true;
}

void AssetDumperMaterial::DumpAsset(AssetDumpingContext& context, XAssetInfo<Material>* asset)
{
    const auto assetFile = context.OpenAssetFile(GetFileNameForAsset(asset->m_name));

    if (!assetFile)
    {
        std::cerr << std::format("WARNING: failed to dump {}", asset->m_name);
        return;
    }

    DumpMaterialAsJson(*assetFile, asset->Asset(), context);
}

void AssetDumperMaterial::DumpPool(AssetDumpingContext& context, AssetPool<Material>* pool)
{
    auto* materialConstantState = context.GetZoneAssetDumperState<MaterialConstantZoneState>();
    materialConstantState->ExtractNamesFromZone();

    AbstractAssetDumper::DumpPool(context, pool);
}
