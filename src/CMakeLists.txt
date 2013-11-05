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
	PATHS "$ENV{FREEIMAGE_ROOT}/Dist"
)
include_directories("${FREEIMAGE_INC}")

find_library(FREEIMAGE_LIB
	NAMES FreeImage freeimage
	PATHS "$ENV{FREEIMAGE_ROOT}/Dist"
)
target_link_libraries (HelloWorldExe ${FREEIMAGE_LIB})

include_directories("${FREEIMAGE_INC}")


find_path(OPENCV_INC
		NAMES "opencv2/opencv.hpp"
		PATHS "$ENV{OPENCV_DIR}/build/include"
		)
include_directories("${OPENCV_INC}")

find_path(JAI_INC
	NAMES "Jai_Factory.h"
	PATHS "C:/Programy/JAI/SDK/library/CPP/include"
	)

find_library(Jai_Factory_Lib
	NAMES Jai_Factory
	PATHS "C:/Programy/JAI/SDK/library/CPP/lib/Win32_i86"
	)

if(NOT "${JAI_INC}")
  add_definitions(-DNO_JAI_CAMERA)
else(NOT "${JAI_INC}")
  include_directories("${JAI_INC}")
  target_link_libraries (HelloWorldExe ${Jai_Factory_Lib})
endif(NOT "${JAI_INC}")

find_library(OPENCV_CALIB3D_LIB
		NAMES opencv_calib3d246 opencv_calib3d
		PATHS "$ENV{OPENCV_DIR}/build/x86/vc11/lib"
		)
		
find_library(OPENCV_CORE_LIB
		NAMES opencv_core246 opencv_core
		PATHS "$ENV{OPENCV_DIR}/build/x86/vc11/lib"
		)
		
find_library(OPENCV_HIGHGUI_LIB
		NAMES opencv_highgui246 opencv_highgui
		PATHS "$ENV{OPENCV_DIR}/build/x86/vc11/lib"
		)


target_link_libraries (HelloWorldExe ${OPENCV_CORE_LIB})		
target_link_libraries (HelloWorldExe ${OPENCV_CALIB3D_LIB})
target_link_libraries (HelloWorldExe ${OPENCV_HIGHGUI_LIB})
	

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")
if(${UNIX})
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif(${UNIX})

include_directories("${PROJECT_BINARY_DIR}/include")

