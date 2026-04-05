qt_add_executable(tsnp)

target_sources(tsnp
    PRIVATE
        main.cpp
        MainWindow.cpp
        MainWindow.h
        canvas/CanvasWidget.cpp
        canvas/CanvasWidget.h
)

target_link_libraries(tsnp 
    PRIVATE 
        Qt6::Core 
        Qt6::Widgets
)
