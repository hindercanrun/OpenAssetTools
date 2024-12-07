#pragma once

#include "Dumping/AbstractAssetDumper.h"
#include "Game/T6/T6.h"

namespace T6
{
    class AssetDumperGameWorldSp final : public AbstractAssetDumper<GameWorldSp>
    {
    protected:
        bool ShouldDump(XAssetInfo<GameWorldSp>* asset) override;
        void DumpAsset(AssetDumpingContext& context, XAssetInfo<GameWorldSp>* asset) override;
    };
} // namespace T6
