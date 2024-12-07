#pragma once

#include "Dumping/AbstractAssetDumper.h"
#include "Game/T6/T6.h"

namespace T6
{
    class AssetDumperKeyValuePairs final : public AbstractAssetDumper<KeyValuePairs>
    {
        static std::string GetFileNameForAsset(const std::string& assetName);

    protected:
        bool ShouldDump(XAssetInfo<KeyValuePairs>* asset) override;
        void DumpAsset(AssetDumpingContext& context, XAssetInfo<KeyValuePairs>* asset) override;
    };
} // namespace T6
