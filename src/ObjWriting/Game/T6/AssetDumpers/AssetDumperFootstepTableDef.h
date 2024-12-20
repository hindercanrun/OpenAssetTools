#pragma once

#include "Dumping/AbstractAssetDumper.h"
#include "Game/T6/T6.h"

namespace T6
{
    class AssetDumperFootstepTableDef final : public AbstractAssetDumper<FootstepTableDef>
    {
        static std::string GetFileNameForAsset(const std::string& assetName);

    protected:
        bool ShouldDump(XAssetInfo<FootstepTableDef>* asset) override;
        void DumpAsset(AssetDumpingContext& context, XAssetInfo<FootstepTableDef>* asset) override;
    };
} // namespace T6
