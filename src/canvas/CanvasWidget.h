// src/canvas/CanvasWidget.h
#pragma once

#include <QWidget>
#include <QImage>
#include "../tools/Tool.h"
#include "../core/BrushSettings.h"
#include "../core/InputEvent.h"

class CanvasWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CanvasWidget(int width, int height, QWidget* parent = nullptr);

    void setActiveTool(Tool* tool) { m_activeTool = tool; }
    void clear(const QColor& color = Qt::white);
    QImage& image() { return m_canvas; }

protected:
    void paintEvent      (QPaintEvent*  event) override;
    void mousePressEvent (QMouseEvent*  event) override;
    void mouseMoveEvent  (QMouseEvent*  event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

private:
    QImage        m_canvas;
    BrushSettings m_brush;       // hardcoded defaults for now
    Tool*         m_activeTool = nullptr;
    QPointF       m_lastPos;     // passed into InputEvent

    InputEvent buildInputEvent(QMouseEvent* event) const;
    void       initCanvas();
};