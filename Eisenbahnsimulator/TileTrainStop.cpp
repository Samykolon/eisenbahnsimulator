#include "TileTrainStop.h"

inline TrainStop::TrainStop(Directions dir, int imp, String^ imagePath, String^ name) : Rail(dir, imagePath, name), Importance(imp) {}
