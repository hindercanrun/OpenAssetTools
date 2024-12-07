#pragma once

#include "Dumping/AbstractAssetDumper.h"
#include "Game/T6/T6.h"

namespace T6
{
    class AssetDumperFont final : public AbstractAssetDumper<Font_s>
    {
        static std::string GetFileNameForAsset(const std::string& assetName);

    protected:
        bool ShouldDump(XAssetInfo<Font_s>* asset) override;
        void DumpAsset(AssetDumpingContext& context, XAssetInfo<Font_s>* asset) override;
    };
} // namespace T6
