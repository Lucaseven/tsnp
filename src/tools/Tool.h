// src/tools/Tool.h
#pragma once

#include <QImage>
#include "../core/InputEvent.h"
#include "../core/BrushSettings.h"

class Tool
{
public:
    virtual ~Tool() = default;

    // Every tool must handle these three mouse events.
    // QImage& is passed by reference so tools draw directly
    // into the canvas pixel buffer — no copying needed.
    virtual void onPress  (QImage& canvas,
                           const InputEvent& ev,
                           const BrushSettings& brush) = 0;

    virtual void onDrag   (QImage& canvas,
                           const InputEvent& ev,
                           const BrushSettings& brush) = 0;

    virtual void onRelease(QImage& canvas,
                           const InputEvent& ev,
                           const BrushSettings& brush) = 0;
};
