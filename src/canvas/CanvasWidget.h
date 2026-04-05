#pragma once

#include <QWidget>
#include <QImage>
#include <QColor>

// CanvasWidget owns the pixel data for the drawing surface.
// Right now it just renders a blank white canvas.
// Future: layers, tools, mouse input will all hook into this class.

class CanvasWidget : public QWidget
{
    Q_OBJECT

public:
    // Construct a canvas of a fixed pixel size.
    // This is the resolution of the image being drawn —
    // independent of how large the widget appears on screen.
    explicit CanvasWidget(int width, int height, QWidget *parent = nullptr);
    ~CanvasWidget() = default;

    // Returns the canvas image dimensions (not widget size)
    int canvasWidth()  const { return m_canvas.width();  }
    int canvasHeight() const { return m_canvas.height(); }

    // Clears the canvas to a solid colour (default white)
    void clear(const QColor &color = Qt::white);

    // Direct access to the pixel data for future tools
    QImage &image() { return m_canvas; }

protected:
    // Qt calls this whenever the widget needs to be redrawn
    void paintEvent(QPaintEvent *event) override;

private:
    QImage m_canvas;   // The actual pixel buffer

    void initCanvas();
};
