#include "AssetDumperDestructibleDef.h"

#include "Game/T6/InfoString/EnumStrings.h"
#include "Game/T6/InfoString/InfoStringFromStructConverter.h"
#include "Game/T6/InfoString/WeaponFields.h"
#include "Game/T6/ObjConstantsT6.h"

#include <cassert>
#include <cstring>
#include <sstream>
#include <type_traits>

using namespace T6;

namespace T6
{
    class InfoStringFromWeaponConverter final : public InfoStringFromStructConverter
    {
    protected:
        void FillFromExtensionField(const cspField_t& field) override
        {
            switch (static_cast<weapFieldType_t>(field.iFieldType))
            {
            case WFT_WEAPONTYPE:
                FillFromEnumInt(std::string(field.szName), field.iOffset, szWeapTypeNames, std::extent_v<decltype(szWeapTypeNames)>);
                break;
            default:
                assert(false);
                break;
            }
        }

    public:
        InfoStringFromWeaponConverter(const WeaponFullDef* structure,
                                      const cspField_t* fields,
                                      const size_t fieldCount,
                                      std::function<std::string(scr_string_t)> scriptStringValueCallback)
            : InfoStringFromStructConverter(structure, fields, fieldCount, std::move(scriptStringValueCallback))
        {
        }
    };
} // namespace T6

InfoString AssetDumperDestructibleDef::CreateInfoString(XAssetInfo<DestructibleDef>* asset)
{
    const auto fullDef = std::make_unique<WeaponFullDef>();
    memset(fullDef.get(), 0, sizeof(WeaponFullDef));

    InfoStringFromWeaponConverter converter(fullDef.get(),
                                            weapon_fields,
                                            std::extent_v<decltype(weapon_fields)>,
                                            [asset](const scr_string_t scrStr) -> std::string
                                            {
                                                assert(scrStr < asset->m_zone->m_script_strings.Count());
                                                if (scrStr >= asset->m_zone->m_script_strings.Count())
                                                    return "";

                                                return asset->m_zone->m_script_strings[scrStr];
                                            });

    return converter.Convert();
}

bool AssetDumperDestructibleDef::ShouldDump(XAssetInfo<DestructibleDef>* asset)
{
    return true;
}

void AssetDumperDestructibleDef::DumpAsset(AssetDumpingContext& context, XAssetInfo<DestructibleDef>* asset)
{
    // Only dump to raw when no GDT is available
    if (context.m_gdt)
    {
        const auto infoString = CreateInfoString(asset);
        GdtEntry gdtEntry(asset->m_name, ObjConstants::GDF_FILENAME_DESTRUCTIBLE_DEF);
        infoString.ToGdtProperties(ObjConstants::INFO_STRING_PREFIX_DESTRUCTIBLE_DEF, gdtEntry);
        context.m_gdt->WriteEntry(gdtEntry);
    }
    else
    {
        const auto assetFile = context.OpenAssetFile("destructibledef/" + asset->m_name);

        if (!assetFile)
        {
            std::cerr << std::format("WARNING: failed to dump {}", asset->m_name);
            return;
        }

        auto& stream = *assetFile;
        const auto infoString = CreateInfoString(asset);
        const auto stringValue = infoString.ToString(ObjConstants::INFO_STRING_PREFIX_DESTRUCTIBLE_DEF);
        stream.write(stringValue.c_str(), stringValue.size());
    }
}
