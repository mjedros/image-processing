#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <CL/cl.h>
#include <opencv2/opencv.hpp>
#include "FreeImage.h"

#include <memory>
#include <vector>
#include <functional>
#include <iostream>
#include <sstream>
#include <time.h>
#include <stdio.h>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv/highgui.h>

#ifndef NO_JAI_CAMERA
#include <Jai_Factory.h>
#endif

using namespace cv;
using std::cout;

#ifndef NO_JAI_CAMERA
bool OpenFactoryAndCamera() {
  J_STATUS_TYPE retval;
  uint32_t iSize;
  uint32_t iNumDev;
  bool8_t bHasChange;
  FACTORY_HANDLE m_hFactory;

  // Open factory
  retval = J_Factory_Open(reinterpret_cast<const int8_t *>(""), &m_hFactory);
  if (retval != J_ST_SUCCESS) {
    cout << "Could not open factory!";
    return false;
  }
  cout << "Opening factory succeeded\n";

  // Update camera list
  retval = J_Factory_UpdateCameraList(m_hFactory, &bHasChange);
  if (retval != J_ST_SUCCESS) {
    cout << "Could not update camera list!";
    return false;
  }
  cout << "Updating camera list succeeded\n";

  // Get the number of Cameras
  retval = J_Factory_GetNumOfCameras(m_hFactory, &iNumDev);
  if (retval != J_ST_SUCCESS) {
    cout << "Could not get the number of cameras!";
    return false;
  }
  if (iNumDev == 0) {
    cout << "There is no camera!";
    return false;
  }
  cout << iNumDev << " cameras were found\n";

  // Get camera ID
  int8_t m_sCameraId[J_CAMERA_ID_SIZE]; // Camera ID
  iSize = (uint32_t)sizeof(m_sCameraId);
  retval = J_Factory_GetCameraIDByIndex(m_hFactory, 0, m_sCameraId, &iSize);
  if (retval != J_ST_SUCCESS) {
    cout << "Could not get the camera ID!";
    return false;
  }
  using std::string;
  cout << "Camera ID: "; //<< string(static_cast<char*>(m_sCameraId));

  // Open camera
  CAM_HANDLE m_hCam; // Camera Handle
  retval = J_Camera_Open(m_hFactory, m_sCameraId, &m_hCam);
  if (retval != J_ST_SUCCESS) {
    cout << "Could not open the camera!";
    return FALSE;
  }
  cout << "Opening camera succeeded\n";
  printf("Id %s", m_sCameraId);

  return true;
}
#else
bool OpenFactoryAndCamera() { return false; }
#endif

int main() {
  OpenFactoryAndCamera();
  int i;
  using std::cin;
  cin >> i;
}
