#include "SADXModLoader.h"

static constexpr int MaxPlayers = 8;

// Example of a custom object with a geometric collision that moves.

void __cdecl YourObjectDisplay(task* tp)
{
	if (!MissedFrames) // Don't render if the current frame is skipped
	{
		njPushMatrixEx();
		njSetTexture(TEXLIST);
		njTranslateEx(&tp->twp->pos);
		njRotateEx((Angle*)&tp->twp->ang, 0);
		dsDrawModel(MODEL);
		njPopMatrixEx();
	}
}

void __cdecl YourObjectExec(task* tp)
{
	if (!CheckRangeOut(tp)) // This deletes the object if the player is too far away
	{
		auto twp = tp->twp;
		auto landcol = (obj*)tp->twp->timer.ptr;

		// Some very basic movement
		twp->pos.x += 0.01f;
		twp->pos.y += 0.1f;
		twp->pos.z += 0.05f;

		// Loop for all player slots
		for (int i = 0; i < MaxPlayers; ++i)
		{
			// Move the player if on the collision
			if (CheckPlayerRideOnMobileLandObjectP(i, tp))
			{
				NJS_VECTOR offset = twp->pos;
				njSubVector(&offset, (NJS_VECTOR*)&landcol->pos); // Get the difference between current position and previous position (where the dyncol currently is)
				njAddVector(&playertwp[i]->pos, &offset); // Add the difference to the player position
			}
		}

		// Update the dyncol position to the current position
		landcol->pos[0] = twp->pos.x;
		landcol->pos[1] = twp->pos.y;
		landcol->pos[2] = twp->pos.z;

		// Run the display
		tp->disp(tp);
	}
}

void __cdecl YourObjectDestroy(task* tp)
{
	auto landcol = (obj*)tp->twp->timer.ptr;

	WithdrawCollisionEntry(tp, landcol);
	ReleaseMobileLandObject(landcol);
}

void __cdecl YourObjectInit(task* tp)
{
	tp->dest = YourObjectDestroy;
	tp->exec = YourObjectExec;
	tp->disp = YourObjectDisplay;

	auto twp = tp->twp;
	auto object = GetMobileLandObject();

	// The dyncol position
	object->pos[0] = twp->pos.x;
	object->pos[1] = twp->pos.y;
	object->pos[2] = twp->pos.z;

	// The dyncol rotation
	object->ang[0] = twp->ang.x;
	object->ang[1] = twp->ang.y;
	object->ang[2] = twp->ang.z;

	// The dyncol scale, we set it to normal (1.0f)
	object->scl[0] = 1.0f;
	object->scl[1] = 1.0f;
	object->scl[2] = 1.0f;

	// The dyncol model
	object->basicdxmodel = MODEL;

	// Initialize with dynamic attribute
	RegisterCollisionEntry(ColFlags_Dynamic | ColFlags_Solid, tp, object);

	twp->timer.ptr = object; // Store the dyncol into our object to edit it and remove it later
}