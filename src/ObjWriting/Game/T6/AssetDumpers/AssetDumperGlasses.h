#pragma once

#include "Dumping/AbstractAssetDumper.h"
#include "Game/T6/T6.h"

namespace T6
{
    class AssetDumperGlasses final : public AbstractAssetDumper<Glasses>
    {
        static std::string GetFileNameForAsset(const std::string& assetName);

    protected:
        bool ShouldDump(XAssetInfo<Glasses>* asset) override;
        void DumpAsset(AssetDumpingContext& context, XAssetInfo<Glasses>* asset) override;
    };
} // namespace T6
