// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "Constants.h"
#include "sensors/RomiGyro.h"

#include <frc/motorcontrol/Spark.h>
#include <frc/Encoder.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc2/command/SubsystemBase.h>
#include <units/length.h>
#include <units/angle.h>

class DriveSubsystem : public frc2::SubsystemBase {
 public:
  DriveSubsystem();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  /**
   * Will be called periodically whenever the CommandScheduler runs during
   * simulation.
   */
  void SimulationPeriodic() override;

  void ArcadeDrive(double moveForward, double moveTurn);

  void TankDrive(double leftSide, double rightSide);

  void ZeroEncoders();

  void ZeroGyro();

  units::meter_t LeftDistance();

  units::meter_t RightDistance();

  units::meter_t CurrentDistance();

  bool IsStopped();

  units::radian_t GetAngleZ();

  void UpdateDebug();
 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  frc::Spark m_leftMotor{MOTOR_LEFT};
  frc::Spark m_rightMotor{MOTOR_RIGHT};

  frc::Encoder m_leftEncoder{4, 5};
  frc::Encoder m_rightEncoder{6, 7};

  frc::DifferentialDrive m_differentialDrive{m_leftMotor, m_rightMotor};

  RomiGyro m_gyro;
};
