#pragma once

#include "Dumping/AbstractAssetDumper.h"
#include "Game/T6/T6.h"

namespace T6
{
    class AssetDumperMenuList final : public AbstractAssetDumper<MenuList>
    {
        static std::string GetFileNameForAsset(const std::string& assetName);

    protected:
        bool ShouldDump(XAssetInfo<MenuList>* asset) override;
        void DumpAsset(AssetDumpingContext& context, XAssetInfo<MenuList>* asset) override;
    };
} // namespace T6
