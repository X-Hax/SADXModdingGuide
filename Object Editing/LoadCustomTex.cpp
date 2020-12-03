#include "SADXModLoader.h"

// Example of a custom pvm/pvmx loading

NJS_TEXNAME customtexlist_entries[TEXCOUNT]; // replace texcount with the amount of texture in your archive, if this number is wrong the mod loader will try to expend it.
NJS_TEXLIST customtexlist = { arrayptrandlength(customtexlist_entries) };

void AnyFunction() {
	// This will load any pvm or pvmx in your mods' "textures" OR "system" folder with the given name
	// Do not specify ".pvm" or ".pvmx", just the filename
	LoadPVM("pvm-name", &customtexlist);

	// Now your texture is loaded, you can use "njSetTexture(&customtexlist);" in any drawing function
	// And the drawn model will use the textures in this specific texlist
}