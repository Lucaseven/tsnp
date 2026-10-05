#pragma once

#include <QPointF>
#include <Qt>

struct InputEvent
{
    QPointF pos;            // current mouse position on the canvas
    QPointF lastPos;        // previous position — used for stroke interpolation
    float   pressure = 1.0f; // always 1.0 for mouse, varies for tablet later
};