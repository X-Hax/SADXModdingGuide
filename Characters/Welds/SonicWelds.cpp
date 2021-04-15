uint16_t Sonic_UpperArmIndices[] = {
	0, 2,
	1, 3,
	4, 6,
	5, 7,
};

uint16_t Sonic_LowerArmIndices[] = {
	0, 10,
	1, 11,
	4, 14,
	5, 15,
};

uint16_t Sonic_UpperLegIndices[] = {
	0, 2,
	1, 3,
	4, 6,
	5, 7,
};

uint16_t Sonic_LowerLegIndices[] = {
	0, 2,
	1, 3,
	4, 6,
	5, 7,
};

uint16_t Sonic_ShoeIndices[] = {
	2, 3,
	12, 8,
	0, 1,
	1, 0,
	17, 13,
	3, 2,
};

uint16_t Sonic_HandIndices[] = {
	11, 50,
	4, 15,
	8, 12,
	5, 54,
	1, 55,
	12, 13,
	0, 14
};

void SetSonicWeldInfo(int id, int base, int modelA, int modelB, uint16_t* indices, size_t count) {
	SonicWeldInfo[id].BaseModel = SONIC_OBJECTS[base];
	SonicWeldInfo[id].ModelA = SONIC_OBJECTS[modelA];
	SonicWeldInfo[id].ModelB = SONIC_OBJECTS[modelB];
	SonicWeldInfo[id].WeldType = 2; // model linking weld
	SonicWeldInfo[id].VertIndexes = indices;
	SonicWeldInfo[id].VertexPairCount = static_cast<uint8_t>(count / 2);
	SonicWeldInfo[id].anonymous_5 = 0;
	SonicWeldInfo[id].VertexBuffer = 0;
}

void InitSonicWeldInfo_r();
Trampoline InitSonicWeldInfo_t((int)InitSonicWeldInfo, (int)InitSonicWeldInfo + 0x5, InitShadowWeldInfo);
void InitSonicWeldInfo_r() {
	((decltype(InitSonicWeldInfo_r)*)InitSonicWeldInfo_t.Target())(); // call original function

	// SONIC (base model is 0)
	SetSonicWeldInfo(0, 0, 1, 2, arrayptrandlength(Sonic_UpperArmIndices)); // this connect the vertices of model 1 with model 2
	SetSonicWeldInfo(1, 0, 2, 3, arrayptrandlength(Sonic_LowerArmIndices)); // model 2 with model 3
	SetSonicWeldInfo(2, 0, 7, 8, arrayptrandlength(Sonic_UpperArmIndices));
	SetSonicWeldInfo(3, 0, 8, 9, arrayptrandlength(Sonic_LowerArmIndices));
	SetSonicWeldInfo(4, 0, 12, 13, arrayptrandlength(Sonic_UpperLegIndices));
	SetSonicWeldInfo(5, 0, 13, 14, arrayptrandlength(Sonic_LowerLegIndices));
	SetSonicWeldInfo(6, 0, 17, 18, arrayptrandlength(Sonic_UpperLegIndices));
	SetSonicWeldInfo(7, 0, 18, 19, arrayptrandlength(Sonic_LowerLegIndices));
	SetSonicWeldInfo(8, 0, 15, 16, arrayptrandlength(Sonic_ShoeIndices));
	SetSonicWeldInfo(9, 0, 20, 21, arrayptrandlength(Sonic_ShoeIndices));
	SetSonicWeldInfo(10, 0, 10, 11, arrayptrandlength(Sonic_HandIndices));
	SetSonicWeldInfo(11, 0, 4, 5, arrayptrandlength(Sonic_HandIndices));
	SetSonicWeldInfo(12, 0, 58, 59, arrayptrandlength(Sonic_ShoeIndices)); // light speed shoes
	SetSonicWeldInfo(13, 0, 60, 61, arrayptrandlength(Sonic_ShoeIndices)); // light speed shoes
	SetSonicWeldInfo(14, 0, 2, 63, arrayptrandlength(Sonic_LowerArmIndices)); // crystal ring wrist

	// SUPER SONIC (base model is 22)
	SetSonicWeldInfo(22, 22, 23, 24, arrayptrandlength(Sonic_UpperArmIndices));
	SetSonicWeldInfo(23, 22, 24, 25, arrayptrandlength(Sonic_LowerArmIndices));
	SetSonicWeldInfo(24, 22, 28, 29, arrayptrandlength(Sonic_UpperArmIndices));
	SetSonicWeldInfo(25, 22, 29, 30, arrayptrandlength(Sonic_LowerArmIndices));
	SetSonicWeldInfo(26, 22, 33, 34, arrayptrandlength(Sonic_UpperLegIndices));
	SetSonicWeldInfo(27, 22, 34, 35, arrayptrandlength(Sonic_LowerLegIndices));
	SetSonicWeldInfo(28, 22, 38, 39, arrayptrandlength(Sonic_UpperLegIndices));
	SetSonicWeldInfo(29, 22, 39, 40, arrayptrandlength(Sonic_LowerLegIndices));
	SetSonicWeldInfo(30, 22, 36, 37, arrayptrandlength(Sonic_ShoeIndices));
	SetSonicWeldInfo(31, 22, 41, 42, arrayptrandlength(Sonic_ShoeIndices));
	SetSonicWeldInfo(32, 22, 31, 32, arrayptrandlength(Sonic_HandIndices));
	SetSonicWeldInfo(33, 22, 26, 27, arrayptrandlength(Sonic_HandIndices));
	SetSonicWeldInfo(34, 22, 31, 32, arrayptrandlength(Sonic_HandIndices));
	SetSonicWeldInfo(35, 22, 26, 27, arrayptrandlength(Sonic_HandIndices));
}