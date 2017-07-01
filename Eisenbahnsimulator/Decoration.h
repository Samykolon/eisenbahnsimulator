#pragma once
#include "TileObject.h"

public ref class Decoration : TileObject {
public:
	enum class DecoType { FoliageTree, Conifer, Bush, House };
	DecoType Type;

	Decoration(int xi, int yi, DecoType dt);

};