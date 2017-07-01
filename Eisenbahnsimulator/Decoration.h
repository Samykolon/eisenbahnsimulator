#pragma once
#include "TileObject.h"

public ref class Decoration : TileObject {
public:
	enum class DecoType { FoliageTree, Conifer, Bush, House };
	DecoType Type;

	Decoration(DecoType dt) {
		Type = dt;
	}

};