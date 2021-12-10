#include "commands/DriveTeleop.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <iostream>

DriveTeleop::DriveTeleop(DriveSubsystem* driveSubsystem) :
 m_driveSubsystem(driveSubsystem),
 m_heading(0_rad){
     AddRequirements(m_driveSubsystem);
}

void DriveTeleop::Initialize(){
    m_heading = 0_deg;
    m_driveSubsystem->ArcadeDrive(0.0, 0.0);
    m_timer.Start();
    m_driveSubsystem->ZeroGyro();
    m_lastExecute = m_timer.Get();
}

void DriveTeleop::Execute(){
    //calculate delta time
    units::second_t currentTime = m_timer.Get();
    units::second_t deltaTime = currentTime - m_lastExecute;
    m_lastExecute = currentTime;

    double leftStickY = m_driveJoystick.GetRawAxis(LEFTSTICK_Y);
    double rightStickX = m_driveJoystick.GetRawAxis(RIGHTSTICK_X);

    //update heading
    m_heading += rightStickX * TURN_RATE * deltaTime;
    m_turnController.SetSetpoint(m_heading.to<double>());
    double adjust = m_turnController.Calculate(m_driveSubsystem->GetAngleZ().to<double>());

    double leftSide = leftStickY + adjust;
    double rightSide = leftStickY - adjust;
    //prevent from going out of -1 to 1 range
    if(rightSide > 1.0){
        double delta = rightSide - 1.0;
        leftSide -= delta;
        rightSide -= delta;
    }else if(leftSide < -1.0){
        double delta = leftSide + 1.0;
        leftSide += delta;
        rightSide += delta;
    }

    m_driveSubsystem->TankDrive(leftSide, rightSide);
}

void DriveTeleop::End(bool interrupted){
    m_timer.Stop();
    m_driveSubsystem->ArcadeDrive(0.0, 0.0);
}

bool DriveTeleop::IsFinished(){
    return false;
}
