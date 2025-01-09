#pragma once

#include "Dumping/AbstractAssetDumper.h"
#include "Game/T6/T6.h"

namespace T6
{
    class AssetDumperXAnimParts final : public AbstractAssetDumper<XAnimParts>
    {
        static std::string GetFileNameForAsset(const std::string& assetName);

    protected:
        bool ShouldDump(XAssetInfo<XAnimParts>* asset) override;
        void DumpAsset(AssetDumpingContext& context, XAssetInfo<XAnimParts>* asset) override;
    };
} // namespace T6
