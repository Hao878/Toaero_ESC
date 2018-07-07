/* --COPYRIGHT--,BSD
 * Copyright (c) 2012, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/
//! \file   ~/sw/modules/vs_freq/src/32b/vs_freq.c
//! \brief  Portable C fixed point code.  These functions define the
//!         Volts/Hertz profile (VS_FREQ) module routines
//!
//! (C) Copyright 2015, Texas Instruments, Inc.


// **************************************************************************
// the includes
#include "sw/modules/vs_freq/src/32b/vs_freq.h"
#include "user.h"


// **************************************************************************
// the defines


// **************************************************************************
// the globals


// **************************************************************************
// the functions

extern VS_FREQ_Handle VS_FREQ_init(void *pMemory,const size_t numBytes)
{
  VS_FREQ_Handle handle;

  if(numBytes < sizeof(VS_FREQ_Obj))
    return((VS_FREQ_Handle)NULL);

  // assign the handle
  handle = (VS_FREQ_Handle)pMemory;

  return(handle);
} // end of VS_FREQ_init() function


extern void VS_FREQ_setParams(VS_FREQ_Handle handle,
        					float_t iqFullScaleFreq_Hz,
        					float_t iqFullScaleVoltage_V,
							float_t maxVsMag_pu)
{
  VS_FREQ_Obj *obj = (VS_FREQ_Obj *)handle;

  obj->iqFullScaleFreq_Hz = iqFullScaleFreq_Hz;
  obj->iqFullScaleVoltage_V = iqFullScaleVoltage_V;
  obj->maxVsMag_pu = maxVsMag_pu;
  obj->MaxFreq = _IQ(USER_MOTOR_FREQ_MAX/iqFullScaleFreq_Hz);

  return;
} // end of VS_FREQ_setParams() function

extern void VS_FREQ_setProfile(VS_FREQ_Handle handle,
							float_t LowFreq, float_t HighFreq,
                            float_t VoltMin, float_t VoltMax)

{
  VS_FREQ_Obj *obj = (VS_FREQ_Obj *)handle;

  obj->LowFreq = _IQ(LowFreq/obj->iqFullScaleFreq_Hz);
  obj->HighFreq = _IQ(HighFreq/obj->iqFullScaleFreq_Hz);

  obj->VoltMin = _IQ(VoltMin/obj->iqFullScaleVoltage_V);
  obj->VoltMax = _IQ(VoltMax/obj->iqFullScaleVoltage_V);

  obj->VfSlope = _IQdiv((obj->VoltMax - obj->VoltMin), (obj->HighFreq - obj->LowFreq));

  obj->Vdq_gain.value[0] = _IQ(0.3);
  obj->Vdq_gain.value[1] = _IQsqrt(_IQ(obj->maxVsMag_pu*obj->maxVsMag_pu) - _IQmpy(obj->Vdq_gain.value[0], obj->Vdq_gain.value[0]));

  return;
} // end of VS_FREQ_setProfile() function

// end of file

