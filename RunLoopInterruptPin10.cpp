/*
 * RunLoopInterruptPin10.cpp
 *
 * Copyright (c) 2017 by Sebastien MARCHAND (Web:www.marscaper.com, Email:sebastien@marscaper.com)
 */
/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "arduino.h"

#include "RunLoopInterruptPin10.hpp"

// Global pointer needed to acces instance in ISR
static RunLoopInterrupt *__interruptInstance = NULL;

static void interruptServiceRoutine()
{
  __interruptInstance->hardwareLoop();
}

#pragma mark -
#pragma mark Memory management

RunLoopInterruptPin10::RunLoopInterruptPin10(uint8_t inputMode,int interruptMode)
{
  __interruptInstance = this;

  pinMode(10, inputMode);
  
  _attachInterrupt(digitalPinToInterrupt(10), interruptServiceRoutine, interruptMode);
}

RunLoopInterruptPin10::~RunLoopInterruptPin10()
{
  __interruptInstance = NULL;
  
  _detachInterrupt(digitalPinToInterrupt(2));
}
