#pragma once

#include "Constants.h"
#include "subsystems/DriveSubsystem.h"

#include <frc2/command/CommandHelper.h>
#include <frc2/command/CommandBase.h>
#include <frc/Joystick.h>

class DriveTeleop : public frc2::CommandHelper<frc2::CommandBase, DriveTeleop>{
public:
    DriveTeleop(DriveSubsystem* driveSubsystem);

    void Initialize() override;

    void Execute() override;

    void End(bool interrupted) override;

    bool IsFinished() override;

private:
    DriveSubsystem* m_driveSubsystem;
    frc::Joystick m_driveJoystick{DRIVE_JOYSTICK};

};