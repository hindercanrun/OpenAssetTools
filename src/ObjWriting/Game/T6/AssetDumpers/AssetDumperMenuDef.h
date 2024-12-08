#pragma once

#include "Dumping/AbstractAssetDumper.h"
#include "Game/T6/T6.h"

namespace T6
{
    class AssetDumperMenuDef final : public AbstractAssetDumper<menuDef_t>
    {
        static std::string GetFileNameForAsset(const std::string& assetName);

    protected:
        bool ShouldDump(XAssetInfo<menuDef_t>* asset) override;
        void DumpAsset(AssetDumpingContext& context, XAssetInfo<menuDef_t>* asset) override;
    };
} // namespace T6
