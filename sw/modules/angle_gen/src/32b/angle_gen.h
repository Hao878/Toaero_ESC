#ifndef _ANGLE_GEN_H_
#define _ANGLE_GEN_H_

//! \file   ~/sw/modules/angle_gen/src/32b/angle_gen.h
//! \brief  Contains the public interface to the angle compensation
//! \brief  generator (ANGLE_GEN) module routines
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
//! \defgroup ANGLE_GEN

//!
//! \ingroup ANGLE_GEN
//@{


#ifdef __cplusplus
extern "C" {
#endif


//! \brief Defines the angle generator (ANGLE_GEN) object
//!
typedef struct _ANGLE_GEN_Obj_
{
  _iq            Freq_pu;    		    //!< the freq input value
  _iq            StepAngleMax;      	//!< predetermined factor for use in angle compensation calculation
  _iq            StepAngle_pu;         	//!< the angle delta value
  _iq            Angle_pu;          	//!< the angle output value
} ANGLE_GEN_Obj;


//! \brief Defines the ANGLE_GEN handle
//!
typedef struct _ANGLE_GEN_Obj_  *ANGLE_GEN_Handle;


// **************************************************************************
// the function prototypes


//! \brief     Gets the predicted angle value
//! \param[in] handle  The angle generator (ANGLE_GEN) handle
//! \return    The predicted angle compensation value, rad
static inline _iq ANGLE_GEN_getAngle_pu(ANGLE_GEN_Handle handle)
{
  ANGLE_GEN_Obj *obj = (ANGLE_GEN_Obj *)handle;

  return(obj->Angle_pu);
} // end of ANGLE_GEN_getAngle_pu() function


//! \brief     Initializes the angle generator (ANGLE_GEN) module
//! \param[in] pMemory   A pointer to the memory for the object
//! \param[in] numBytes  The number of bytes allocated for the object, bytes
//! \return    The angle generator (ANGLE_GEN) object handle
extern ANGLE_GEN_Handle ANGLE_GEN_init(void *pMemory,const size_t numBytes);


//! \brief  Angel generation of input frequency
//! \param[in] handle     The angle generator (ANGLE_GEN) handle
//! \param[in] Freq_pu    The electrical speed in pu
static inline void ANGLE_GEN_run(ANGLE_GEN_Handle handle,const _iq Freq_pu)
{
  ANGLE_GEN_Obj *obj = (ANGLE_GEN_Obj *)handle;

  obj->Freq_pu = Freq_pu;
  obj->StepAngle_pu = _IQmpy(obj->Freq_pu,obj->StepAngleMax);

  uint32_t angleMask = ((uint32_t)0xFFFFFFFF >> (32 - GLOBAL_Q));
  _iq Angle_pu = obj->Angle_pu;

  // increment the angle
  Angle_pu = Angle_pu + obj->StepAngle_pu;

  // mask the angle for wrap around
  // note: must account for the sign of the angle
  Angle_pu = _IQabs(Angle_pu) & angleMask;

  // account for sign
  if(obj->Freq_pu < _IQ(0.0))
  {
	  Angle_pu = -Angle_pu;
  }

  obj->Angle_pu = Angle_pu;

  return;
} // end of ANGLE_GEN_run()


//! \brief     Sets the parameters
//! \param[in] handle               The angle generator (ANGLE_GEN) handle
//! \param[in] iqFullScaleFreq_Hz   The full scale frequency for IQ variable, Hz
//! \param[in] ctrlPeriod_sec       The controller period in usec
extern void ANGLE_GEN_setParams(ANGLE_GEN_Handle handle,
                            float_t iqFullScaleFreq_Hz,
                            float_t ctrlPeriod_sec);


#ifdef __cplusplus
}
#endif // extern "C"

//@}  // ingroup

#endif // end of _ANGLE_GEN_H_ definition

