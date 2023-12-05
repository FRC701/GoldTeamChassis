// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Chassis.h"
#include <frc/smartdashboard/SmartDashboard.h>

Chassis::Chassis(WPI_TalonFX& ID1, WPI_TalonFX& ID2, WPI_TalonFX& ID3, WPI_TalonFX& ID4)
        : mFrontR(ID1),
          mFrontL(ID2),
          mBackR(ID3),
          mBackL(ID4),
          mDrive(mFrontR,mFrontL)
          {
            mBackR.Follow(mFrontR);
    mBackL.Follow(mFrontL);
          }

// This method will be called once per scheduler run
void Chassis::Periodic() {
  frc::SmartDashboard::PutNumber("RightSide", 10*mFrontR.GetSelectedSensorVelocity()*(2/3)/12);
  frc::SmartDashboard::PutNumber("LeftSide", 10*mFrontL.GetSelectedSensorVelocity()*(2/3)/12);
}

void Chassis::TankDrive(double left, double right)
{
    mDrive.TankDrive(left, right);
}
