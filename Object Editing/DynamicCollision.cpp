#include "SADXModLoader.h"

// Example of a simple custom object with a static geometric collision.

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
		tp->disp(tp); // Run the display
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

	// Initialize with solid attribute
	RegisterCollisionEntry(ColFlags_Solid, tp, object);

	twp->timer.ptr = object; // Store the dyncol into our object to remove it later
}