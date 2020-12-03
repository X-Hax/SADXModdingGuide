#include "SADXModLoader.h"
#include "ModelInfo.h"

// Example of a function that loads external models in the mods' system folder
// To retrieve the NJS_OBJECT use "MyModel->getmodel()".
// Compatible with other mods: if someone wishes to improve your model, they can make a simple file replacement mod.

ModelInfo* MyModel = nullptr;

void LoadModel(ModelInfo** info, const char* name, const HelperFunctions& helperFunctions) {
	std::string fullPath = "system\\";
	fullPath = fullPath + name + ".sa1mdl";

	ModelInfo* mdl = new ModelInfo(helperFunctions.GetReplaceablePath(fullPath.c_str()));

	if (mdl->getformat() != ModelFormat_Basic) {
		*info = nullptr;
		delete mdl;
	}
	else {
		*info = mdl;
	}
}

extern "C"
{
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		LoadModel(&MyModel, "model-name", helperFunctions);
	}

	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
}