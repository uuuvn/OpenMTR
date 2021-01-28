/* 
 *  File: Motor.h
 *  
 *  MIT License
 *  
 *  Copyright (c) 2021 Nikolay Voynilenko
 *  
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 */

#ifndef OPENMTR_MOTOR_H
#define OPENMTR_MOTOR_H

#include <Defines.h>
#include <Arduino.h>

class MotorConnectInfo
{
public:
    static MotorConnectInfo generic(uint32_t pinA,bool reverse = false);
    static MotorConnectInfo generic_dualside(uint32_t pinA,uint32_t pinB,bool reverse = false);
    static MotorConnectInfo driver_L298P(uint32_t pwm,uint32_t dir,bool reverse = false);
    byte type = 0;
    uint32_t pinA = 0;
    uint32_t pinB = 0;
    bool reverse = false;
};

#endif