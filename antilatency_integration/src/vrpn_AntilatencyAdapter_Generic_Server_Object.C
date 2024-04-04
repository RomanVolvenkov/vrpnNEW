#include "vrpn_AntilatencyAdapter_Generic_Server_Object.h"

#include "vrpn_Connection.h"
#include "vrpn_Tracker_Alt.h"
#include "vrpn_MainloopContainer.h"

#include <locale>
#include <iostream>
#include <sstream>
#include <iomanip>


//old version backup for relook

//int vrpn_AntilatencyAdapter_Generic_Server_Object::setup_Tracker_Alt(char*& pch, char* line, FILE* /*config_file*/)
//{
//    std::string envCode;
//    std::stringstream ss;
//    ss << line;
//    std::string str;
//    std::vector<std::pair<std::string, std::string>> devicesNamePlacement;
//    bool zv = false;
//    bool zav = false;
//    float extrapolationTime = 0;
//    ss >> str; // get rid of vrpn_Tracker_Alt
//
//    const char pathSeparator =
//#ifdef _WIN32
//        '\\';
//#else
//        '/';
//#endif
//
//    while (ss >> str) {
//        if (str[0] == '-') {
//            if (str == "-env") { // environment
//                if (!(ss >> str)) {
//                    std::cout << "error in arguments line"
//                              << "\r\n";
//                    return -1;
//                }
//                envCode = str;
//            }
//            else if (str == "-et") { // extrapolation time
//                if (!(ss >> extrapolationTime)) {
//                    std::cout << "error in arguments line"
//                              << "\r\n";
//                    return -1;
//                }
//            }
//            else if (str == "-p") { // placement
//                std::string placement;
//                if (!(ss >> placement)) {
//                    std::cout << "error in arguments line"
//                              << "\r\n";
//                    return -1;
//                }
//                if (devicesNamePlacement.size() != 0) {
//                    devicesNamePlacement[devicesNamePlacement.size() - 1]
//                        .second = placement;
//                }
//            }
//            else if (str == "-zv") { // zero velocity
//                zv = true;
//            }
//            else if (str == "-zav") { // zero angular velocity
//                zav = true;
//            }
//        }
//        else {
//            devicesNamePlacement.emplace_back(std::make_pair(str, ""));
//        }
//    }
//
//    for (size_t i = 0; i < devicesNamePlacement.size(); ++i) {
//        try {
//            auto namePlacement = devicesNamePlacement[i];
//            auto newDevice = new vrpn_Tracker_Alt(
//                namePlacement.first.c_str(), connection, namePlacement.second,
//                envCode, zv, zav);
//            newDevice->setExtrapolationTime(extrapolationTime);
//            _devices->add(newDevice);
//        }
//        catch (std::runtime_error e) {
//            std::cout << "error while adding device "
//                      << devicesNamePlacement[i].first << ": " << e.what()
//                      << std::endl;
//        }
//    }
//    return 0;
//}

vrpn_AntilatencyAdapter_Generic_Server_Object::vrpn_AntilatencyAdapter_Generic_Server_Object(
        vrpn_Connection* connection_to_use, const char* config_file_name,
        bool be_verbose, bool bail_on_open_error)
    : vrpn_Generic_Server_Object(connection_to_use, config_file_name, be_verbose, bail_on_open_error,
          [&](char*& pch, char* line, FILE* /*config_file*/)->int 
    {
              std::string envCode;
              std::stringstream ss;
              ss << line;
              std::string str;
              std::vector<std::pair<std::string, std::string>>
                  devicesNamePlacement;
              bool zv = false;
              bool zav = false;
              float extrapolationTime = 0;
              ss >> str; // get rid of vrpn_Tracker_Alt

              const char pathSeparator =
#ifdef _WIN32
                  '\\';
#else
                  '/';
#endif

              while (ss >> str) {
                  if (str[0] == '-') {
                      if (str == "-env") { // environment
                          if (!(ss >> str)) {
                              std::cout << "error in arguments line"
                                        << "\r\n";
                              return -1;
                          }
                          envCode = str;
                      }
                      else if (str == "-et") { // extrapolation time
                          if (!(ss >> extrapolationTime)) {
                              std::cout << "error in arguments line"
                                        << "\r\n";
                              return -1;
                          }
                      }
                      else if (str == "-p") { // placement
                          std::string placement;
                          if (!(ss >> placement)) {
                              std::cout << "error in arguments line"
                                        << "\r\n";
                              return -1;
                          }
                          if (devicesNamePlacement.size() != 0) {
                              devicesNamePlacement[devicesNamePlacement.size() -
                                                   1]
                                  .second = placement;
                          }
                      }
                      else if (str == "-zv") { // zero velocity
                          zv = true;
                      }
                      else if (str == "-zav") { // zero angular velocity
                          zav = true;
                      }
                  }
                  else {
                      devicesNamePlacement.emplace_back(
                          std::make_pair(str, ""));
                  }
              }

              for (size_t i = 0; i < devicesNamePlacement.size(); ++i) {
                  try {
                      auto namePlacement = devicesNamePlacement[i];
                      auto newDevice = new vrpn_Tracker_Alt(
                          namePlacement.first.c_str(), connection,
                          namePlacement.second, envCode, zv, zav);
                      newDevice->setExtrapolationTime(extrapolationTime);
                      _devices->add(newDevice);
                  }
                  catch (std::runtime_error e) {
                      std::cout << "error while adding device "
                                << devicesNamePlacement[i].first << ": "
                                << e.what() << std::endl;
                  }
              }
              return 0;
          })
{}