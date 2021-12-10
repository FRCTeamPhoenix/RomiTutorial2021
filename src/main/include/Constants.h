// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

#include <units/length.h>
#include <units/velocity.h>
#include <units/time.h>
#include <units/angle.h>

#include <wpi/math>

const int MOTOR_LEFT = 0;
const int MOTOR_RIGHT = 1;

const int DRIVE_JOYSTICK = 0;

const int LEFTSTICK_X = 0;
const int LEFTSTICK_Y = 1;
const int RIGHTSTICK_X = 4;
const int RIGHTSTICK_Y = 5;

const auto TURN_RATE = wpi::math::pi * 0.5_rad / 1_s;

//drive subsystem variables
const double TICKS_PER_REVOLUTION = 1440.0;
const units::meter_t WHEEL_DIAMETER = 70_mm;
//minimum velocity before considered stopped
const units::meters_per_second_t MIN_RATE = 0.05_mps;
//how long to be below min velocity before stopped
const units::second_t MAX_PERIOD = 0.25_s;

//distance PID values
const units::meter_t DISTANCE_PID_TOLERANCE = 30_mm;
const double DISTANCE_P = 24.0;
const double DISTANCE_I = 0.0;
const double DISTANCE_D = 0.8;

const units::radian_t TURN_PID_TOLERANCE = 2_deg;
const double TURN_P = 0.6;
const double TURN_I = 0.0;
const double TURN_D = 0.0;