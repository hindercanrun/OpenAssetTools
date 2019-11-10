ZoneCommonTests = {}

function ZoneCommonTests:include()
    
end

function ZoneCommonTests:link()
    links "ZoneCommonTests"
end

function ZoneCommonTests:use()
	
end

function ZoneCommonTests:project()
	local folder = TestFolder();

	project "ZoneCommonTests"
        targetdir(TargetDirectoryTest)
		location "%{wks.location}/test/%{prj.name}"
		kind "SharedLib"
		language "C++"
		
		files {
			path.join(folder, "ZoneCommonTests/**.h"), 
			path.join(folder, "ZoneCommonTests/**.cpp"),
			ZoneCode:allTestFiles()
		}
		
        vpaths {
			["*"] = {
				path.join(folder, "ZoneCommonTests"),
				path.join(BuildFolder(), "src/ZoneCode")
			}
		}
		
		self:include()
		ZoneCommon:include()

		ZoneCommon:link()

		ZoneCode:use()
end