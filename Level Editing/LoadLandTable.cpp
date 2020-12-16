#include "SADXModLoader.h"
#include "LandTableInfo.h"

// Example of a function that loads external levels in the mods' system folder
// To retrieve the LandTable use "MyLand->getlandtable()".

LandTableInfo* MyLand = nullptr;

void LoadLandTable(LandTableInfo** info, const char* name, const HelperFunctions& helperFunctions, NJS_TEXLIST* texlist) {
	std::string fullPath = "system\\";
	fullPath = fullPath + name + ".sa1lvl";

	LandTableInfo* land = new LandTableInfo(helperFunctions.GetReplaceablePath(fullPath.c_str()));

	if (land->getlandtable() == nullptr) {
		delete land;
		*info = nullptr;
	}
	else {
		if (texlist != nullptr) {
			land->getlandtable()->TexList = texlist;
		}
		
		*info = land;
	}
}

extern "C"
{
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		// If your landtable file contains a texlist address, leave the texlist param to nullptr
		LoadLandTable(&MyLand, "landtable-name", helperFunctions, nullptr);

		// If you want to apply a custom texlist, fill it in the texlist param
		LoadLandTable(&MyLand, "landtable-name", helperFunctions, CustomTexlist);
	}

	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
}