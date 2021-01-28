/* 
 *  File: Defines.h
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

#ifndef OPENMTR_DEFINES_H
#define OPENMTR_DEFINES_H

// MOTOR TYPES

#define MOTORTYPE_GENERIC 1
#define MOTORTYPE_GENERIC_DUALSIDE 2
#define MOTORTYPE_L298P 3

// END MOTOR TYPES

// DAC convert consts

#define OPENMTR_DAC_INVERT//DON'T USE!!!!!

#ifndef OPENMTR_DAC_INVERT
#ifndef OPENMTR_MAX_DAC
#define OPENMTR_MAX_DAC 255
#endif
#ifndef OPENMTR_MIN_DAC
#define OPENMTR_MIN_DAC 0
#endif
#endif
#ifdef OPENMTR_DAC_INVERT
#ifndef OPENMTR_MAX_DAC
#define OPENMTR_MAX_DAC 0
#endif
#ifndef OPENMTR_MIN_DAC
#define OPENMTR_MIN_DAC 255
#endif
#endif

// END DAC convert consts

#endif