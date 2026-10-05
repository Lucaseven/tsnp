// src/tools/PenTool.h
#pragma once

#include "StrokeTool.h"

class PenTool : public StrokeTool
{
protected:
    // The only thing PenTool needs to answer:
    // "how do I paint one dot of the stroke?"
    void drawAt(QImage& canvas,
                const QPointF& point,
                const BrushSettings& brush) override;
};