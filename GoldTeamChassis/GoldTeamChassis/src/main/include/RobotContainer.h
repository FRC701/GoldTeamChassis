// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/button/CommandXboxController.h>

#include "Constants.h"
#include "subsystems/ExampleSubsystem.h"

#include <frc/XboxController.h>

#include "Constants.h"

#include "subsystems/Chassis.h"



/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and trigger mappings) should be declared here.
 */
class RobotContainer {
 public:





  using WPI_TalonFX = ctre::phoenix::motorcontrol::can::WPI_TalonFX;

  RobotContainer();



  frc2::CommandPtr GetAutonomousCommand();
    static constexpr int kFrontR{0};
  static constexpr int kFrontL{1};
  static constexpr int kBackR{2};
  static constexpr int kBackL{3};


 private:
  // Replace with CommandPS4Controller or CommandJoystick if needed
  frc2::CommandXboxController m_driverController{
      OperatorConstants::kDriverControllerPort};
  frc::XboxController driver{0};
  // The robot's subsystems are defined here...
  ExampleSubsystem m_subsystem;

    WPI_TalonFX mFrontR{kFrontR};
  WPI_TalonFX mFrontL{kFrontL};
  WPI_TalonFX mBackR{kBackR};
  WPI_TalonFX mBackL{kBackL};
  Chassis mChassis{mFrontR, mFrontL, mBackR, mBackL};
  

  void ConfigureBindings();
};
