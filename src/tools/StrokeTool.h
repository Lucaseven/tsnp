// src/tools/StrokeTool.h
#include "Tool.h"
#include <QPointF>

class StrokeTool : public Tool
{
public:
    // These are implemented in StrokeTool.cpp — not pure virtual.
    // Stroke tools inherit this behaviour for free.
    void onPress  (QImage& canvas,
                   const InputEvent& ev,
                   const BrushSettings& brush) override;

    void onDrag   (QImage& canvas,
                   const InputEvent& ev,
                   const BrushSettings& brush) override;

    void onRelease(QImage& canvas,
                   const InputEvent& ev,
                   const BrushSettings& brush) override;

protected:
    // The one thing subclasses must implement:
    // "given a painter and a point, what do you draw?"
    virtual void drawAt(QImage& canvas,
                        const QPointF& point,
                        const BrushSettings& brush) = 0;

private:
    QPointF m_lastPos;  // tracks previous point for interpolation
};