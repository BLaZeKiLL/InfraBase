find_package(spdlog CONFIG REQUIRED)

file(GLOB_RECURSE IB_CORE_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp")

add_library(IB_CORE ${IB_CORE_SOURCES})

#if (WIN32)
#    if (CMAKE_BUILD_TYPE MATCHES "Debug")
#        target_compile_options(ModelViewer PUBLIC /MTd)
#    else()
#        target_compile_options(ModelViewer PUBLIC /MT)
#    endif()
#endif ()

target_include_directories(IB_CORE PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/private")

target_include_directories(IB_CORE PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/public")

target_link_libraries(IB_CORE PUBLIC spdlog::spdlog_header_only)

if (WIN32)
    target_compile_definitions(IB_CORE PUBLIC IB_WINDOWS)
endif()

if (UNIX)
    target_compile_definitions(IB_CORE PUBLIC IB_UNIX)
endif()