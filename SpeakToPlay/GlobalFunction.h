#pragma once

void MakeCepstral();//tranforms raw speech data into sets of cepstral vectors



void DCCalc();//calculates DC offset
void DC_Shift();//DC offsets data and calculates MAX value for normalization
void CalEnergyZCR();//calculates various parameters related to energy and zcr

void Normalize();//normalizes voice data so that max sample value is 5000
void Hamming_Window();//calculates the Hamming window values (320 values as frame size is taken as 320 samples)
void Raised_Sine_Window();//calculates the Raised Sine window values (12 values as we calculate Q=12 Ci's)
void Frame_Block();//chooses the optimal part of the speech waveform and extracts 5 frames
void Apply_Hamming_Window();//applies (multiplies) Hamming window values with corresponding frame values
void RCalc();//Calculates 13 Ri's (R0 to R12)
void ACalc();//Calculates 12 ai's (a1 to a12)
void CCalc();//Calculates 13 ci's (co to c12)

void MakeObservationSeq();//tranforms cepstral coefficients into observation sequences using codebook
void ReadObservations();//makes HMMs most optimal for the observation sequences for all utterances for all digits
void ReadCodebook();//reads Code book


void TestModel();//Uses HMM to predict what digit is the test data

void readValues();

void forward_procedure();

