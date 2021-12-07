#include "commands/DriveDistance.h"
#include <iostream>

DriveDistance::DriveDistance(DriveSubsystem* driveSubsystem, units::meter_t distance):
m_driveSubsystem(driveSubsystem),
m_distance(distance){
    AddRequirements(driveSubsystem);
}

void DriveDistance::Initialize(){
    m_driveSubsystem->TankDrive(0.0, 0.0);
    m_driveSubsystem->ZeroEncoders();
    m_pidController.SetSetpoint(m_distance.to<double>());
    m_pidController.SetTolerance(PID_TOLERANCE.to<double>());
    std::cout << "started moving with distance: " << m_distance.to<double>() << std::endl;
}

void DriveDistance::Execute(){
    double speed = m_pidController.Calculate(m_driveSubsystem->CurrentDistance().to<double>());
    m_driveSubsystem->TankDrive(speed, speed);
}

void DriveDistance::End(bool interrupted){
    m_driveSubsystem->TankDrive(0.0, 0.0);
    std::cout << "finished drive distance" << std::endl;
}

bool DriveDistance::IsFinished(){
    return m_driveSubsystem->IsStopped() && m_pidController.AtSetpoint();
}