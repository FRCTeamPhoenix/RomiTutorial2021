#include "commands/DriveTeleop.h"

DriveTeleop::DriveTeleop(DriveSubsystem* driveSubsystem) :
 m_driveSubsystem(driveSubsystem){
     AddRequirements(m_driveSubsystem);
 }

void DriveTeleop::Initialize(){
    m_driveSubsystem->ArcadeDrive(0.0, 0.0);
}

void DriveTeleop::Execute(){
    m_driveSubsystem->ArcadeDrive(m_driveJoystick.GetRawAxis(LEFTSTICK_Y), m_driveJoystick.GetRawAxis(RIGHTSTICK_X));
}

void DriveTeleop::End(bool interrupted){
    m_driveSubsystem->ArcadeDrive(0.0, 0.0);
}

bool DriveTeleop::IsFinished(){
    return false;
}
