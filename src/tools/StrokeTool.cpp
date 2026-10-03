// src/tools/StrokeTool.cpp
#include "StrokeTool.h"
#include <QLineF>

void StrokeTool::onPress(QImage& canvas,
                         const InputEvent& ev,
                         const BrushSettings& brush)
{
    m_lastPos = ev.pos;           // record stroke start
    drawAt(canvas, ev.pos, brush); // draw first dot
}

void StrokeTool::onDrag(QImage& canvas,
                        const InputEvent& ev,
                        const BrushSettings& brush)
{
    // Calculate distance between last and current mouse position.
    // Qt fires mouse events every few ms — at fast speeds this
    // gap can be 20-30 pixels, leaving holes in the stroke.
    float dist = QLineF(m_lastPos, ev.pos).length();

    // Stamp the brush every quarter of its diameter along the line.
    // Smaller step = smoother stroke, more stamps per drag event.
    float step = qMax(1.0f, brush.size * 0.25f);

    for (float t = 0.0f; t <= dist; t += step)
    {
        // Linearly interpolate between lastPos and current pos.
        // t=0 gives lastPos, t=dist gives ev.pos.
        float ratio = (dist > 0.0f) ? t / dist : 0.0f;
        QPointF pt  = m_lastPos + ratio * (ev.pos - m_lastPos);
        drawAt(canvas, pt, brush);
    }

    m_lastPos = ev.pos; // update for next drag event
}

void StrokeTool::onRelease(QImage& canvas,
                           const InputEvent& ev,
                           const BrushSettings& brush)
{
    drawAt(canvas, ev.pos, brush); // final dot at release point
}