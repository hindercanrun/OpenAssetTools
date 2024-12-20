#pragma once

#include "Dumping/AbstractAssetDumper.h"
#include "Game/T6/T6.h"

namespace T6
{
    class AssetDumperSkinnedVertsDef final : public AbstractAssetDumper<SkinnedVertsDef>
    {
        static std::string GetFileNameForAsset(const std::string& assetName);

    protected:
        bool ShouldDump(XAssetInfo<SkinnedVertsDef>* asset) override;
        void DumpAsset(AssetDumpingContext& context, XAssetInfo<SkinnedVertsDef>* asset) override;
    };
} // namespace T6