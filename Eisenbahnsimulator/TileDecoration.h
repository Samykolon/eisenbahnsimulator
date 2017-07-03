#pragma once
#include "TileObject.h"

enum class DecoType { FoliageTree, Conifer, Bush, House };

public ref class Decoration : TileObject {
protected:
	DecoType Type;
public:
	Decoration(DecoType dt, String^ imagePath, String^ name);

};