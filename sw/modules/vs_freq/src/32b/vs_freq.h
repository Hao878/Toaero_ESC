#ifndef _VS_FREQ_H_
#define _VS_FREQ_H_

//! \file   ~/sw/modules/vs_freq/src/32b/vs_freq.h
//! \brief  Contains the public interface to the Volts/Hertz
//! \brief  profile (VS_FREQ) module routines
//!
//! (C) Copyright 2014, Texas Instruments, Inc.


// **************************************************************************
// the includes
#include <stdint.h>

// drivers 


// modules
#include "sw/modules/types/src/types.h"
#include "sw/modules/math/src/32b/math.h"
#include "sw/modules/iqmath/src/32b/IQmathLib.h"

//!
//! \defgroup VS_FREQ_

//!
//! \ingroup VS_FREQ_
//@{


#ifdef __cplusplus
extern "C" {
#endif


// **************************************************************************
// the defines


// **************************************************************************
// the typedefs

//! \brief Defines the volts/Hertz profile (VS_FREQ) object
//!
typedef struct _VS_FREQ_Obj_
{
  float_t 		 iqFullScaleFreq_Hz;
  float_t 		 iqFullScaleVoltage_V;
  float_t 		 maxVsMag_pu;
  _iq            Freq;			        //!< Input: Input Frequency (pu)
  _iq            LowFreq;      			//!< Parameter: Low Frequency (pu)
  _iq            HighFreq;       		//!< Parameter: High Frequency at rated voltage (pu)
  _iq            MaxFreq;       		//!< Parameter: Maximum Frequency (pu)
  _iq            VoltMin;			    //!< Parameter: Voltage at low Frequency range (pu)
  _iq            VoltMax;			    //!< Parameter: Rated voltage (pu)
  _iq            VfSlope;			    //!< Variable
  _iq            Vs_out;			    //!< Output: Output voltage (pu)
  MATH_vec2      Vdq_gain;		        //!< Variable
  MATH_vec2		 Vdq_out;				//!< Output: Output voltage (pu)
} VS_FREQ_Obj;

//! \brief Defines the VS_FREQ_obj handle
//!
typedef struct _VS_FREQ_Obj_  *VS_FREQ_Handle;


// **************************************************************************
// the function prototypes


//! \brief     Gets the Vd output value in VS_FREQ
//! \param[in] handle  The volts/hertz (VS_FREQ) handle
//! \return    The Vd output value in VS_FREQ, pu
static inline float_t VS_FREQ_getVd_pu(VS_FREQ_Handle handle)
{
  VS_FREQ_Obj *obj = (VS_FREQ_Obj *)handle;

  return(obj->Vdq_out.value[0]);
} // end of VS_FREQ_getVd_pu() function

//! \brief     Gets the Vq output value in VS_FREQ
//! \param[in] handle  The volts/hertz profile (VS_FREQ) handle
//! \return    The Vq output value in VS_FREQ, pu
static inline float_t VS_FREQ_getVq_pu(VS_FREQ_Handle handle)
{
  VS_FREQ_Obj *obj = (VS_FREQ_Obj *)handle;

  return(obj->Vdq_out.value[1]);
} // end of VS_FREQ_getVq_pu() function


//! \brief     Initializes the angle generator (VS_FREQ) module
//! \param[in] pMemory   A pointer to the memory for the object
//! \param[in] numBytes  The number of bytes allocated for the object, bytes
//! \return    The volts/hertz profile (VS_FREQ) object handle
extern VS_FREQ_Handle VS_FREQ_init(void *pMemory,const size_t numBytes);


//! \brief     Generates an output command voltage for a specific
//!            input command frequency according to the specified
//!            volts/hertz profile.
//! \param[in] handle     The volts/hertz profile (VS_FREQ) handle
//! \param[in] fm_pu      The electrical speed in pu
static inline void VS_FREQ_run(VS_FREQ_Handle handle,const _iq Freq_pu)
{
  VS_FREQ_Obj *obj = (VS_FREQ_Obj *)handle;

  obj->Freq = Freq_pu;

  if(obj->Freq <= obj->LowFreq)
	  obj->Vs_out = obj->VoltMin;
  else if(obj->Freq >= obj->HighFreq)
	  obj->Vs_out = obj->VoltMax;
  else
  {
	  obj->Vs_out = obj->VoltMin + _IQmpy(obj->VfSlope, (obj->Freq - obj->LowFreq));
  }

  obj->Vdq_out.value[0] = _IQmpy(obj->Vs_out, obj->Vdq_gain.value[0]);
  obj->Vdq_out.value[1] = _IQmpy(obj->Vs_out, obj->Vdq_gain.value[1]);

  return;
} // end of VS_FREQ_run()


//! \brief     Sets the parameters
//! \param[in] handle                 The volts/hertz profile (VS_FREQ) handle
//! \param[in] iqFullScaleFreq_Hz     The full scale frequency for IQ variable, Hz
//! \param[in] iqFullScaleVoltage_V   The full scale voltage for the IQ variable, V
//! \param[in] maxVsMag_pu			  The decimation between PWM cycles and the ISR cycle
extern void VS_FREQ_setParams(VS_FREQ_Handle handle,
        					float_t iqFullScaleFreq_Hz,
        					float_t iqFullScaleVoltage_V,
							float_t maxVsMag_pu);

//! \brief     Sets the parameters
//! \param[in] handle               The volts/hertz profile (VS_FREQ) handle
//! \param[in] iqFullScaleFreq_Hz   The full scale frequency for IQ variable, Hz
//! \param[in] LowFreq       		The low frequency for volts/hertz profile, Hz
//! \param[in] HighFreq       		The high frequency for volts/hertz profile, Hz
//! \param[in] VoltMin       		The minimum frequency for volts/hertz profile, Volts
//! \param[in] VoltMax       		The maximum frequency for volts/hertz profile, Volts
extern void VS_FREQ_setProfile(VS_FREQ_Handle handle,
							float_t LowFreq, float_t HighFreq,
                            float_t VoltMin, float_t VoltMax);



#ifdef __cplusplus
}
#endif // extern "C"

//@}  // ingroup

#endif // end of _VS_FREQ_H_ definition

