#pragma once

#include "Dumping/AbstractAssetDumper.h"
#include "Game/T6/T6.h"

namespace T6
{
    class AssetDumperDestructibleDef final : public AbstractAssetDumper<DestructibleDef>
    {
    protected:
        bool ShouldDump(XAssetInfo<DestructibleDef>* asset) override;
        void DumpAsset(AssetDumpingContext& context, XAssetInfo<DestructibleDef>* asset) override;
    };
} // namespace T6
