#pragma once

#include <QColor>

struct BrushSettings
{
    QColor color    = Qt::black;  // default pen colour
    int    size     = 8;          // diameter in pixels
    float  opacity  = 1.0f;       // fully opaque
    float  hardness = 1.0f;       // hard edge — no feathering yet
};