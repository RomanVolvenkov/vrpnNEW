project(antilatency_integration)

set(API_HEADERS
	${CMAKE_CURRENT_SOURCE_DIR}/AntilatencySDK/Api/AndroidJniWrapper.h
	${CMAKE_CURRENT_SOURCE_DIR}/AntilatencySDK/Api/Antilatency.Alt.Environment.h
	${CMAKE_CURRENT_SOURCE_DIR}/AntilatencySDK/Api/Antilatency.Alt.Environment.Pillars.h
	${CMAKE_CURRENT_SOURCE_DIR}/AntilatencySDK/Api/Antilatency.Alt.Tracking.h
	${CMAKE_CURRENT_SOURCE_DIR}/AntilatencySDK/Api/Antilatency.Api.h
	${CMAKE_CURRENT_SOURCE_DIR}/AntilatencySDK/Api/Antilatency.Bracer.h
	${CMAKE_CURRENT_SOURCE_DIR}/AntilatencySDK/Api/Antilatency.DeviceNetwork.h
	${CMAKE_CURRENT_SOURCE_DIR}/AntilatencySDK/Api/Antilatency.DeviceNetwork.Interop.h
	${CMAKE_CURRENT_SOURCE_DIR}/AntilatencySDK/Api/Antilatency.HardwareExtensionInterface.h
	${CMAKE_CURRENT_SOURCE_DIR}/AntilatencySDK/Api/Antilatency.HardwareExtensionInterface.Interop.h
	${CMAKE_CURRENT_SOURCE_DIR}/AntilatencySDK/Api/Antilatency.InterfaceContract.h
	${CMAKE_CURRENT_SOURCE_DIR}/AntilatencySDK/Api/Antilatency.InterfaceContract.LibraryLoader.h
	${CMAKE_CURRENT_SOURCE_DIR}/AntilatencySDK/Api/Antilatency.InterfaceContract.LibraryLoader.Qt.h
	${CMAKE_CURRENT_SOURCE_DIR}/AntilatencySDK/Api/Antilatency.InterfaceContract.LibraryLoader.Unix.h
	${CMAKE_CURRENT_SOURCE_DIR}/AntilatencySDK/Api/Antilatency.InterfaceContract.LibraryLoader.Uwp.h
	${CMAKE_CURRENT_SOURCE_DIR}/AntilatencySDK/Api/Antilatency.InterfaceContract.LibraryLoader.Win32.h
	${CMAKE_CURRENT_SOURCE_DIR}/AntilatencySDK/Api/Antilatency.Math.h
	${CMAKE_CURRENT_SOURCE_DIR}/AntilatencySDK/Api/Antilatency.RadioMetrics.h
	${CMAKE_CURRENT_SOURCE_DIR}/AntilatencySDK/Api/Antilatency.RadioMetrics.Interop.h
	${CMAKE_CURRENT_SOURCE_DIR}/AntilatencySDK/Api/Antilatency.StorageClient.h
	${CMAKE_CURRENT_SOURCE_DIR}/AntilatencySDK/Api/Antilatency.TrackingAlignment.h)
	
	

	
add_library(antilatency_integration INTERFACE)

target_sources(antilatency_integration INTERFACE
	${CMAKE_CURRENT_SOURCE_DIR}/src/vrpn_AntilatencyAdapter_Generic_Server_Object.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/vrpn_AntilatencyAdapter_Generic_Server_Object.C
	${CMAKE_CURRENT_SOURCE_DIR}/src/vrpn_Tracker_Alt.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/vrpn_Tracker_Alt.C)
	
target_include_directories(antilatency_integration INTERFACE AntilatencySDK/Api)