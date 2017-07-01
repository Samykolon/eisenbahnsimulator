#include "Decoration.h"

Decoration::Decoration(int xi, int yi, DecoType dt) :TileObject(xi, yi) {
	Type = dt;
	switch (dt)
	{	//TODO: Define imagePaths
	case Decoration::DecoType::FoliageTree:
		break;
	case Decoration::DecoType::Conifer:
		break;
	case Decoration::DecoType::Bush:
		break;
	case Decoration::DecoType::House:
		break;
	default:
		break;
	}


}
