#pragma once

#include "Dumping/AbstractAssetDumper.h"
#include "Game/T6/T6.h"

namespace T6
{
    class AssetDumperGfxLightDef final : public AbstractAssetDumper<GfxLightDef>
    {
        static std::string GetFileNameForAsset(const std::string& assetName);

    protected:
        bool ShouldDump(XAssetInfo<GfxLightDef>* asset) override;
        void DumpAsset(AssetDumpingContext& context, XAssetInfo<GfxLightDef>* asset) override;
    };
} // namespace T6
