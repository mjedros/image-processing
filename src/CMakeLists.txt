add_executable(HelloWorldExe HelloWorld.cpp file.cpp)
find_library(OPENCL_LIB 
	NAMES OpenCL
	PATHS "$ENV{AMDAPPSDKROOT}/lib/x86" "$ENV{CUDA_PATH}/lib/Win32"
	)
target_link_libraries (HelloWorldExe ${OPENCL_LIB})
find_path(OPENCL_INC
	NAMES "CL/cl.h"
	PATHS "$ENV{AMDAPPSDKROOT}/include" "$ENV{CUDA_PATH}/include"
)

include_directories("${OPENCL_INC}")

find_path(FREEIMAGE_INC
	NAMES "FreeImage.h"
	PATHS "${FREEIMAGE_ROOT}/Dist"
)
include_directories("${FREEIMAGE_INC}")

find_library(FREEIMAGE_LIB
	NAMES FreeImage freeimage
	PATHS "${FREEIMAGE_ROOT}/Dist"
)
target_link_libraries (HelloWorldExe ${FREEIMAGE_LIB})

include_directories("${FREEIMAGE_INC}")

if(${UNIX})
	set(CMAKE_CXX_FLAGS "-std=c++11")
endif(${UNIX})

