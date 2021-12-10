// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveSubsystem.h"

#include <wpi/math>

DriveSubsystem::DriveSubsystem() {
  m_gyro.Reset();

  // Implementation of subsystem constructor goes here.
  m_rightMotor.SetInverted(true);

  m_leftEncoder.SetDistancePerPulse(wpi::math::pi * WHEEL_DIAMETER.to<double>() / TICKS_PER_REVOLUTION);
  m_rightEncoder.SetDistancePerPulse(wpi::math::pi * WHEEL_DIAMETER.to<double>() / TICKS_PER_REVOLUTION);

  //minimum velocity before considered stopped
  m_leftEncoder.SetMinRate(MIN_RATE.to<double>());
  m_rightEncoder.SetMinRate(MIN_RATE.to<double>());

  //how long to be below min rate before stopping
  m_leftEncoder.SetMaxPeriod(MAX_PERIOD);
  m_rightEncoder.SetMaxPeriod(MAX_PERIOD);

  m_leftEncoder.SetSamplesToAverage(2);
  m_rightEncoder.SetSamplesToAverage(2);
}

void DriveSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void DriveSubsystem::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
}

void DriveSubsystem::ArcadeDrive(double moveForward, double moveTurn){
  m_differentialDrive.ArcadeDrive(moveForward, moveTurn);
}

void DriveSubsystem::TankDrive(double leftSide, double rightSide){
  m_differentialDrive.TankDrive(leftSide, rightSide);
}

void DriveSubsystem::ZeroEncoders(){
  m_rightEncoder.Reset();
  m_leftEncoder.Reset();
}

void DriveSubsystem::ZeroGyro(){
  m_gyro.Reset();
}

units::meter_t DriveSubsystem::LeftDistance(){
  return units::meter_t(m_leftEncoder.GetDistance());
}

units::meter_t DriveSubsystem::RightDistance(){
  return units::meter_t(m_rightEncoder.GetDistance());
}

units::meter_t DriveSubsystem::CurrentDistance(){
  return (LeftDistance() + RightDistance()) / 2.0;
}

bool DriveSubsystem::IsStopped(){
  return m_leftEncoder.GetStopped() && m_rightEncoder.GetStopped();
}

units::radian_t DriveSubsystem::GetAngleZ(){
  return units::degree_t(m_gyro.GetAngleZ());
}

void DriveSubsystem::UpdateDebug(){
  m_gyro.UpdateDebugValues();
}