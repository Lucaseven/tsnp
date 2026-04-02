qt_add_executable(tsnp)

target_sources(tsnp
    PRIVATE
        main.cpp
)

target_link_libraries(tsnp
    PRIVATE 
        Qt6::Widgets
)
