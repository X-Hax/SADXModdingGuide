#include "SADXModLoader.h"
#include "AnimationFile.h"

// Example of a function that loads external animations in the mods' system folder
// To retrieve the NJS_MOTION use "MyAnim->getmotion()".
// Compatible with other mods: if someone wishes to improve your anim, they can make a simple file replacement mod.

AnimationFile* MyAnim = nullptr;

void LoadAnimation(AnimationFile** info, const char* name, const HelperFunctions& helperFunctions) {
	std::string fullPath = "system\\";
	fullPath = fullPath + name + ".saanim";

	AnimationFile* anm = new AnimationFile(helperFunctions.GetReplaceablePath(fullPath.c_str()));

	if (anm->getmodelcount() == 0) {
		delete anm;
		*info = nullptr;
	}
	else {
		*info = anm;
	}
}

extern "C"
{
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		LoadAnimation(&MyAnim, "anim-name", helperFunctions);
	}

	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
}