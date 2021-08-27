#pragma once

#include "Dumping/AbstractAssetDumper.h"
#include "Game/IW4/IW4.h"

namespace IW4
{
    class AssetDumperMenuDef final : public AbstractAssetDumper<menuDef_t>
    {
        static const MenuList* GetParentMenuList(XAssetInfo<menuDef_t>* asset);
        static std::string GetPathForMenu(XAssetInfo<menuDef_t>* asset);

    protected:
        bool ShouldDump(XAssetInfo<menuDef_t>* asset) override;
        void DumpAsset(AssetDumpingContext& context, XAssetInfo<menuDef_t>* asset) override;
    };
}
