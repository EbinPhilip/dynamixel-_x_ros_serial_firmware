#include <ros.h>
#include "dynamixel_x_mcu_controller/InitializeActuators.h"
#include "dynamixel_x_mcu_controller/EnableActuators.h"
#include "dynamixel_x_mcu_controller/DriveActuators.h"

ros::NodeHandle nh;

using namespace dynamixel_x_mcu_controller;

void initializeCb(const InitializeActuators::Request &, InitializeActuators::Response &);
void enableCb(const EnableActuators::Request &, EnableActuators::Response &);
void driveCb(const DriveActuators::Request &, DriveActuators::Response &);

ros::ServiceServer<InitializeActuators::Request, InitializeActuators::Response>
    initializeService("InitializeActuators", &initializeCb);
ros::ServiceServer<EnableActuators::Request, EnableActuators::Response>
    enableService("EnableActuators", &enableCb);
ros::ServiceServer<DriveActuators::Request, DriveActuators::Response>
    driveService("DriveActuators", &driveCb);

void setup()
{
    nh.initNode();
    nh.advertiseService(initializeService);
    nh.advertiseService(enableService);
    nh.advertiseService(driveService);
}

void loop()
{
    nh.spinOnce();
}

void initializeCb(const InitializeActuators::Request &request, InitializeActuators::Response &response)
{
    response.status = 0;
}

void enableCb(const EnableActuators::Request &request, EnableActuators::Response &response)
{
    response.status = 0;
}

void driveCb(const DriveActuators::Request &request, DriveActuators::Response &response)
{
    response.position = 0;
    response.speed = 0;
    response.effort = 0;
    response.error = 0;
}