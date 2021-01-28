/* 
 *  File: Robot.cpp
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

#include <Robot.h>

Robot::Robot(){
    ready = false;
}
Robot::Robot(MotorConnectInfo left,MotorConnectInfo right){
    this->begin(left,right);
}
void Robot::begin(MotorConnectInfo left,MotorConnectInfo right){
    this->left.begin(left);
    this->right.begin(right);
    ready = this->left.isReady() && this->right.isReady();
}
void Robot::setPower(int left,int right){
    this->left.setPower(left);
    this->right.setPower(right);
}
void Robot::setPowerAndDirection(int power,int dir){
    this->left.setPower(constrain(power + dir,-100,100));
    this->right.setPower(constrain(power - dir,-100,100));
}