/* 
 *  File: Robot.h
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

#ifndef OPENMTR_ROBOT_H
#define OPENMTR_ROBOT_H
#include <Motor.h>
#include <SingleMotor.h>

class Robot
{
protected:
    SingleMotor left;
    SingleMotor right;
    bool ready = false;
public:
    Robot();
    Robot(MotorConnectInfo left,MotorConnectInfo right);
    void begin(MotorConnectInfo left,MotorConnectInfo right);
    void setPower(int left,int right);
    void setPowerAndDirection(int power,int dir); 
    void walk(int power,int dir,unsigned int ms);
};

#endif