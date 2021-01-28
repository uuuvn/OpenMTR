/* 
 *  File: SingleMotor.cpp
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

#include <SingleMotor.h>

SingleMotor::SingleMotor()
{
    ready = false;
}

SingleMotor::SingleMotor(MotorConnectInfo connectinfo)
{
    begin(connectinfo);
}

void SingleMotor::begin(MotorConnectInfo connectinfo)
{
    ready = false;
    this->connectinfo = connectinfo;
    switch (connectinfo.type)
    {
    case MOTORTYPE_GENERIC:
        pinMode(connectinfo.pinA, OUTPUT);
        digitalWrite(connectinfo.pinA, OPENMTR_MIN_DAC);
        ready = true;
        break;
    case MOTORTYPE_GENERIC_DUALSIDE:
        pinMode(connectinfo.pinA, OUTPUT);
        pinMode(connectinfo.pinB, OUTPUT);
        digitalWrite(connectinfo.pinA, OPENMTR_MIN_DAC);
        digitalWrite(connectinfo.pinB, OPENMTR_MIN_DAC);
        ready = true;
        break;
    case MOTORTYPE_L298P:
        pinMode(connectinfo.pinA, OUTPUT);
        pinMode(connectinfo.pinB, OUTPUT);
        digitalWrite(connectinfo.pinA, OPENMTR_MIN_DAC);
        digitalWrite(connectinfo.pinB, OPENMTR_MIN_DAC);
        ready = true;
        break;

    default:
        break;
    }
}

void SingleMotor::setPower(int power)
{
    if (!ready)
        return;
    switch (connectinfo.type)
    {
    case MOTORTYPE_GENERIC:
        analogWrite(connectinfo.pinA, map(constrain(power, 0, 100), 0, 100, OPENMTR_MIN_DAC, OPENMTR_MAX_DAC));
        break;
    case MOTORTYPE_GENERIC_DUALSIDE:
        if (connectinfo.reverse)
        {
            analogWrite(power > 0 ? connectinfo.pinB : connectinfo.pinA, map(constrain(abs(power), 0, 100), 0, 100, OPENMTR_MIN_DAC, OPENMTR_MAX_DAC));
            analogWrite(power > 0 ? connectinfo.pinA : connectinfo.pinB, OPENMTR_MIN_DAC);
        }
        else
        {
            analogWrite(power > 0 ? connectinfo.pinA : connectinfo.pinB, map(constrain(abs(power), 0, 100), 0, 100, OPENMTR_MIN_DAC, OPENMTR_MAX_DAC));
            analogWrite(power > 0 ? connectinfo.pinB : connectinfo.pinA, OPENMTR_MIN_DAC);
        }
        break;
    case MOTORTYPE_L298P:
        if (connectinfo.reverse)
        {
            digitalWrite(connectinfo.pinB, power > 0);
        }
        else
        {
            digitalWrite(connectinfo.pinB, power < 0);
        }
        analogWrite(connectinfo.pinA, map(constrain(abs(power), 0, 100), 0, 100, 0, 255));
        break;
    default:
        break;
    }
}

void SingleMotor::walk(int power,unsigned int ms){
    this->setPower(power);
    delay(ms);
    this->setPower(0);
}

bool SingleMotor::isReady(){
    return this->ready;
}

MotorConnectInfo & SingleMotor::getConnectInfo(){
    return this->connectinfo;
}