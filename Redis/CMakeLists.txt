# Sources
file(GLOB SRCS_G "src/*.cpp")
POCO_SOURCES_AUTO( SRCS ${SRCS_G})

# Headers
file(GLOB_RECURSE HDRS_G "include/*.h" )
POCO_HEADERS_AUTO( SRCS ${HDRS_G})

# Version Resource
if(MSVC AND NOT POCO_STATIC)
    source_group("Resources" FILES ${CMAKE_SOURCE_DIR}/DLLVersion.rc)
    list(APPEND SRCS ${CMAKE_SOURCE_DIR}/DLLVersion.rc)
endif()

add_library(Redis ${SRCS} )
add_library(Poco::Redis ALIAS Redis)
set_target_properties(Redis
    PROPERTIES
    VERSION ${SHARED_LIBRARY_VERSION} SOVERSION ${SHARED_LIBRARY_VERSION}
	OUTPUT_NAME PocoRedis
    DEFINE_SYMBOL Redis_EXPORTS
    )

target_link_libraries(Redis PUBLIC Poco::Net)
target_include_directories(Redis
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
    )

POCO_INSTALL(Redis)
POCO_GENERATE_PACKAGE(Redis)

if (POCO_ENABLE_TESTS)
    add_subdirectory(testsuite)
endif ()
if (POCO_ENABLE_SAMPLES)
#    add_subdirectory(samples)
endif ()

configure_file(PocoRedis.pc.in ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/pkgconfig/PocoRedis.pc @ONLY)
list(APPEND POCO_PKG_CONFIG_FILES ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/pkgconfig/PocoRedis.pc)
set(POCO_PKG_CONFIG_FILES ${POCO_PKG_CONFIG_FILES} PARENT_SCOPE)
