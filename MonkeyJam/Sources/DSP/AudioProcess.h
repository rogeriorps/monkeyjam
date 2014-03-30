/*
 * AudioProcess.h
 *
 *  Created on: Feb 22, 2014
 *      Author: ehughes
 */

#include "arm_math.h"
#include "IIR.h"
#include "PeakingComb.h"

#ifndef AUDIOPROCESS_H_
#define AUDIOPROCESS_H_


#define PATCH_PASS_THROUGH			0x00
#define PATCH_SINE_TEST				0x01
#define PATCH_TUBEY_CLEAN			0x02
#define PATCH_OVERDRIVE				0x03
#define PATCH_OCTAVE				0x04
#define PATCH_COMB_THE_DESERT		0x05


extern uint8_t CurrentPatch;

#define PEAKING_COMB_SIZE	512
extern PeakingComb		MyPeakingComb;


//Samples that just came in.
extern q31_t LeftIn;
extern q31_t RightIn;

//Samples to go out next
extern q31_t LeftOut;
extern q31_t RightOut;

void InitAudioProcess();
void AudioProcess();
void ChangePatch(uint8_t NewPatch);

//Used by Effects

extern q31_t OD_Level;
#define NUM_IIR	4
extern q31_t_IIR MyIIR[NUM_IIR];

#endif /* AUDIOPROCESS_H_ */