// src/tools/PenTool.cpp
#include "PenTool.h"
#include <QPainter>

void PenTool::drawAt(QImage& canvas,
                     const QPointF& point,
                     const BrushSettings& brush)
{
    QPainter painter(&canvas);

    // SmoothPixmapTransform gives clean edges when zooming later.
    painter.setRenderHint(QPainter::Antialiasing, true);

    // Apply opacity — QPainter works in 0-255, we store 0.0-1.0
    painter.setOpacity(brush.opacity);

    // A hard round brush is just a filled circle.
    // hardness=1.0 for now — feathered edges come later.
    painter.setPen(Qt::NoPen);  // no outline on the circle
    painter.setBrush(QBrush(brush.color));

    // Draw a filled circle centred on the point.
    // The radius is half the brush diameter.
    double radius = brush.size / 2.0;
    painter.drawEllipse(point, radius, radius);

    // QPainter destructor flushes and ends painting automatically.
}