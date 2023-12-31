// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/TankDrive.h"

TankDrive::TankDrive(Chassis& chassis,
                     std::function<double()> left,
                     std::function<double()> right)
: mDrive(chassis), mLeft(left), mRight(right)
{
  AddRequirements(&mDrive);
}

// Called when the command is initially scheduled.
void TankDrive::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void TankDrive::Execute() 
{
   mDrive.TankDrive(mLeft(), mRight());
}

// Called once the command ends or is interrupted.
void TankDrive::End(bool interrupted) {}

// Returns true when the command should end.
bool TankDrive::IsFinished() 
{
  return false;
}
