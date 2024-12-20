#include "AssetDumperKeyValuePairs.h"

using namespace T6;

std::string AssetDumperKeyValuePairs::GetFileNameForAsset(const std::string& assetName)
{
    return std::format("kvp/{}.kvp", assetName);
}

bool AssetDumperKeyValuePairs::ShouldDump(XAssetInfo<KeyValuePairs>* asset)
{
    return true;
}

void AssetDumperKeyValuePairs::DumpAsset(AssetDumpingContext& context, XAssetInfo<KeyValuePairs>* asset)
{
    const auto* keyValuePairs = asset->Asset();
    const auto assetFile = context.OpenAssetFile(GetFileNameForAsset(asset->m_name));

    if (!assetFile)
    {
        std::cerr << std::format("WARNING: failed to dump {}", asset->m_name);
        return;
    }

    auto& stream = *assetFile;
    stream.write(keyValuePairs->name, keyValuePairs->keyValuePairs->keyHash);
}
