#pragma once

enum TransitionActions : Uint8 {
	NextAction_None,
	NextAction_WindPath,
	NextAction_DashPanel,
	NextAction_VerticalSpring,
	NextAction_Spring,
	NextAction_Launched, // Sonic, Tails
	NextAction_Trampoline1,
	NextAction_Trampoline2,
	NextAction_Trampoline3,
	NextAction_Trampoline4,
	NextAction_Trampoline5,
	NextAction_Updraft,
	NextAction_CtrlStand, // Sonic, Tails, Knuckles, Amy
	NextAction_CtrlSpin, // Sonic, Tails, Knuckles
	NextAction_CtrlRun, // Sonic, Tails
	NextAction_CtrlPush, // Sonic, Tails, Knuckles, Amy
	NextAction_CtrlHook, // Sonic, Tails, Knuckles
	NextAction_Fall,
	NextAction_BumperCar,
	NextAction_Winning,
	NextAction_CtrlRocketStart, // Sonic, Tails
	NextAction_CtrlRocketH, // Sonic, Tails
	NextAction_CtrlRocketV, // Sonic, Tails
	NextAction_Waterslide, // Sonic
	NextAction_Reset,
	NextAction_RollBounce,
	NextAction_Loop,
	NextAction_ExitBumperCar, // Sonic
	NextAction_27, // Unused
	NextAction_MonkeyBars, // Sonic, Tails, Knuckles
	NextAction_Icicle, // Sonic
	NextAction_Ladder,
	NextAction_SkyDeckCylinder, // Sonic, Tails
	NextAction_EggKeeper, // Sonic, Tails, Amy, Gamma
	NextAction_LookAround, // Sonic, Tails
	NextAction_HitCol, // Sonic, Tails, Knuckles
	NextAction_Bubble, // Sonic, Tails
	NextAction_Hold,
	NextAction_Frozen, // Sonic, Knuckles
	NextAction_Drown, // Except Gamma
	NextAction_Shower, // Sonic, Tails
	NextAction_ShowerEnd, // Sonic, Tails
	NextAction_ShakeOffDust, // Sonic, Tails
	NextAction_Building, // Sonic
	NextAction_Snowboard, // Sonic, Tails
	NextAction_Pinball, // Sonic, Tails
	NextAction_SuperSonic, // Sonic
	NextAction_SuperSonicStop, // Sonic
	NextAction_Fly, // Tails
	NextAction_CharacterSelect, // Tails
	NextAction_Death
};