#include "SADXModLoader.h"

// Example of a simple custom object with dynamic collisions that does not move.

void __cdecl YourObjectRender(ObjectMaster* obj) {
	if (!MissedFrames) { // don't render if the current frame is skipped
		njPushMatrixEx();
		njSetTexture(TEXLIST);
		njTranslateEx(&obj->Data1->Position);
		njRotateEx((Angle*)&obj->Data1->Rotation, 0);
		njDrawModel_SADX(MODEL);
		njPopMatrixEx();
	}
}

void __cdecl YourObjectExec(ObjectMaster* obj) {
	if (!ClipSetObject(obj)) { // This deletes the object if the player is too far away
		obj->DisplaySub(obj); // Run the display
	}
}

void __cdecl YourObjectDelete(ObjectMaster* obj) {
	DynamicCOL_Remove(obj, obj->Data1->Object); // Release the dyncol if the object is deleted
}

void __cdecl YourObjectInit(ObjectMaster* obj) {
	obj->DeleteSub = YourObjectDelete;
	obj->MainSub = YourObjectExec;
	obj->DisplaySub = YourObjectRender;

	NJS_OBJECT* object = ObjectArray_GetFreeObject();

	// The dyncol position
	object->pos[0] = obj->Data1->Position.x;
	object->pos[1] = obj->Data1->Position.y;
	object->pos[2] = obj->Data1->Position.z;

	// The dyncol rotation
	object->ang[0] = obj->Data1->Rotation.x;
	object->ang[1] = obj->Data1->Rotation.y;
	object->ang[2] = obj->Data1->Rotation.z;

	// The dyncol scale, we set it to normal (1.0f)
	object->scl[0] = 1.0f;
	object->scl[1] = 1.0f;
	object->scl[2] = 1.0f;

	// The dyncol model
	object->basicdxmodel = MODEL;

	// Initialize (the dyncol will run until DynamicCol_Remove is called on the object)
	DynamicCOL_Add(ColFlags_Solid, obj, object);

	obj->Data1->Object = object; // Store the dyncol into our object to edit it or remove it later
}