#pragma once

#include "Dumping/AbstractAssetDumper.h"
#include "Game/T6/T6.h"

namespace T6
{
    class AssetDumperMemoryBlock final : public AbstractAssetDumper<MemoryBlock>
    {
    protected:
        bool ShouldDump(XAssetInfo<MemoryBlock>* asset) override;
        void DumpAsset(AssetDumpingContext& context, XAssetInfo<MemoryBlock>* asset) override;
    };
} // namespace T6
