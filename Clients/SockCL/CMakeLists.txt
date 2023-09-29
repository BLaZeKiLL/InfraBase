file(GLOB_RECURSE IB_SOCKCL_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp")

add_executable(IB_SockCL ${IB_SOCKCL_SOURCES})

add_custom_command(
        TARGET IB_SockCL POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_CURRENT_SOURCE_DIR}/resource" "$<TARGET_FILE_DIR:IB_SockCL>/resource"
)

#if (WIN32)
#    if (CMAKE_BUILD_TYPE MATCHES "Debug")
#        target_compile_options(IB_KeyValue PUBLIC /MTd)
#    else()
#        target_compile_options(IB_KeyValue PUBLIC /MT)
#    endif()
#endif ()

target_include_directories(IB_SockCL PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/private")

target_link_libraries(IB_SockCL PRIVATE IB_CORE)