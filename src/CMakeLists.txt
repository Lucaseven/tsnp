add_executable(tsnp
    main.cpp
    MainWindow.cpp
    MainWindow.h
    canvas/CanvasWidget.cpp
    canvas/CanvasWidget.h
    tools/Tool.h
    tools/StrokeTool.h
    tools/StrokeTool.cpp
    tools/PenTool.h
    tools/PenTool.cpp
    core/InputEvent.h
    core/BrushSettings.h
)

target_link_libraries(tsnp PRIVATE Qt6::Core Qt6::Widgets)
