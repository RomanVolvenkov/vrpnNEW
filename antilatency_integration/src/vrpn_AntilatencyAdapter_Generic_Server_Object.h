#pragma once

#include "../../server_src/vrpn_Generic_server_object.h"

class VRPN_API vrpn_Connection;

class vrpn_AntilatencyAdapter_Generic_Server_Object : public vrpn_Generic_Server_Object {
public:
    vrpn_AntilatencyAdapter_Generic_Server_Object(
        vrpn_Connection *connection_to_use,
        const char *config_file_name = "vrpn.cfg", bool be_verbose = false,
        bool bail_on_open_error = false);

protected:
    // old version backup for relook
    //int setup_Tracker_Alt(char *&pch, char *line, FILE * /*config_file*/);
};