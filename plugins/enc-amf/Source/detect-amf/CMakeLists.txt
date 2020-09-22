project(detect-amf)

set(detect-amf_HEADERS
	)

set(detect-amf_SOURCES
	../amf.cpp
	../amf-capabilities.cpp
	../amf-encoder.cpp
	../amf-encoder-h264.cpp
	../amf-encoder-h265.cpp
	../api-base.cpp
	../api-d3d9.cpp
	../api-d3d11.cpp
	../utility.cpp
	detect-amf-support.cpp
	)

if(MSVC)
	add_compile_options("$<$<CONFIG:RelWithDebInfo>:/MT>")
endif()

add_definitions(-DPIPED_PROCESS)

add_executable(detect-amf
	${detect-amf_SOURCES}
	${detect-amf_HEADERS})

target_link_libraries(detect-amf
	${enc-amf_LIBRARIES})

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
	set(_output_suffix "64")
else()
	set(_output_suffix "32")
endif()

set_target_properties(detect-amf
	PROPERTIES
		OUTPUT_NAME "detect-amf${_output_suffix}")

install_obs_datatarget(detect-amf "obs-plugins/enc-amf")
