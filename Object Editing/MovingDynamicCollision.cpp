#include "SADXModLoader.h"

static constexpr int MaxPlayers = 8;

// Example of a custom object with dynamic collisions that moves.

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
		EntityData1* data = obj->Data1;

		// Some very basic movement
		data->Position.x += 0.01f;
		data->Position.y += 0.1f;
		data->Position.z += 0.05f;

		// Move players with the dyncol
		for (int i = 0; i < MaxPlayers; ++i) {
			CharObj2* co2 = CharObj2Ptrs[i];

			if (co2 && co2->field_6C == obj) {
				NJS_VECTOR offset = data->Position;
				njSubVector(&offset, (NJS_VECTOR*)&data->Object->pos); // Get the difference between current position and previous position (where the dyncol currently is)
				njAddVector(&EntityData1Ptrs[i]->Position, &offset); // Add the difference to the player position
			}
		}

		// Update the dyncol position to the current position
		data->Object->pos[0] = data->Position.x;
		data->Object->pos[1] = data->Position.y;
		data->Object->pos[2] = data->Position.z;

		// Run the display
		obj->DisplaySub(obj);
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
	// Note: 0x08000000 is the dyncol for collisions that move
	// If you don't set it, the dyncol will not update every frame
	DynamicCOL_Add((ColFlags)(0x08000000 | ColFlags_Solid), obj, object);

	obj->Data1->Object = object; // Store the dyncol into our object to edit it and remove it later
}