// SpeakToPlay.cpp : main project file.

#include "stdafx.h"
#include "Form1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <cmath>
//C:\Users\salon\Documents\Visual Studio 2010\Projects\SpeakToPlay\Intermediates
char ROOT_SAVE[] = "I:\\Academics\\MTECH\\Sem 1\\Playlist\\Intermediates\\", PATH[200], PATH_READ[200], PATH_WRITE[200], PATH1[500], PATH2[500], PATH3[500], PATH5[800];
char ROOT_DATA[] = "I:\\Academics\\MTECH\\Sem 1\\Playlist\\Final Speech Recordings for Projects\\", BUFF[50], UTT[2];
char RECMODPATH[] = "\"\"I:\\Academics\\MTECH\\Sem 1\\Speech Processing\\Recording_Module\\";
char ROOT[] = "I:\\Academics\\MTECH\\Sem 1\\Speech Processing\\Results\\Program 6\\Intermediates\\";
char FILENAME[500],FILENAME_FILE[500];


FILE *fpSilence, *fpVoice, *fpVoiceDC, *fpVoiceNorm, *fpVoiceNormTemp, *fpVoiceFrame, *fpVoiceFrameHamming, *fpR, *fpA, *fpC;
FILE *fpTokhura, *fpOverallDist, *fpCodebook, *fpUniverse, *fpCluster[65], *fpObs, *fpInitialModel, *fpAllImprovedModels,*fpFilename;
double DC_OFF = 0, MAX = 0, NORM = 0, X = 0, BUFFVAL = 0, K[13], E[13], S = 0;
long double ENRG = 0,AVG_ENRG, ENRG_MAX, ENRG_MIN;
long double alpha[500][10], beta[500][10], zeta[500][10][10], gamma[500][10], delta[500][10], PI[10], B[10][65], A[10][10], B_COMB[100][10][65], A_COMB[100][10][10], A1[10][10], B1[10][65];
long double P, PSTAR, THRESH = powl(10.0, -30);
long int k = 0, k1 = 0, k2 = 0;
int N = 6, M = 64, T, OBS[500], shi[500][10], q[500], t, itr;
int ZCR = 0, AVG_ZCR, ZCR_VARMAX = 0, ZCR_VARMIN = 0, i = 0, j = 0, ERR = 1, v = 0, u = 0, p = 12, CB_SIZE = 1, TOKHURA[] = { 1, 3, 7, 13, 19, 22, 25, 33, 42, 50, 56, 61 }, MIN = 0, MINTOKHI, CLUSTER_SIZE[65], MAX_CLUSTERI = 0;
double ARR[105], eps = 0.03;
double FRAME[320], HAM[320], R0[500], R[13], C[13], CU[13], W[13], AA[13][13], AI[13], CENTROID[13], MINTOKH, PREVTOKH = 0, CURTOKH = 0, TOKH = 0, CODEBOOK[65][13];


using namespace SpeakToPlay;

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



void TestModel(){//Uses HMM to predict what digit is the test data
	long double PMAX = 0;
	int recognised_digit = 10;
	int v_test = 100, u_test = 100, d = 0;
	char recognized[200];
	strcpy(recognized, "english");
	/*
	Using the recording module, first a silence file of 5 seconds is recorded to find the DC shift.
	Then, the test vowel is recorded, which is tested against the test data.
	*/



	//printf("A duration (5 seconds) of silence needs to be recorded. Please make sure there is minimal noise. Press 0 to exit. Press 1 if ready:");
	//scanf("%d", &d);

	//if (d){
	//	strcpy(PATH1, RECMODPATH);
	//	strcat(PATH1, "Recording_Module.exe\"");
	//	strcpy(PATH2, "\"");
	//	strcat(PATH2, ROOT_SAVE);
	//	strcat(PATH2, "SilenceUnknown.wav\"");
	//	strcpy(PATH3, "\"");
	//	strcat(PATH3, ROOT_SAVE);
	//	strcat(PATH3, "SilenceUnknown.txt\"");
	//	strcpy(PATH5, PATH1);
	//	strcat(PATH5, " 5 ");
	//	strcat(PATH5, PATH2);
	//	strcat(PATH5, " ");
	//	strcat(PATH5, PATH3);
	//	strcat(PATH5, "\"");
	//	//printf("Recording started...");
	//	system(PATH5);
	//	//printf("Recording ended...");

	//}
	//else{
	//	//exit(0);
	//}
	strcpy(PATH5, ROOT_SAVE);
	strcat(PATH5, "SilenceUnknown.txt");
	strcpy(PATH_READ, PATH5);

	DCCalc();

	//printf("You will have 1 second. Speak a digit after pressing 1 if ready. Press 0 to exit:");
	//scanf("%d", &d);

	//if (d){
	//	strcpy(PATH1, RECMODPATH);
	//	strcat(PATH1, "Recording_Module.exe\"");
	//	strcpy(PATH2, "\"");
	//	strcat(PATH2, ROOT_SAVE);
	//	strcat(PATH2, "184101038_100_100.wav\"");
	//	strcpy(PATH3, "\"");
	//	strcat(PATH3, ROOT_SAVE);
	//	strcat(PATH3, "184101038_100_100.txt\"");
	//	strcpy(PATH5, PATH1);
	//	strcat(PATH5, " 1 ");
	//	strcat(PATH5, PATH2);
	//	strcat(PATH5, " ");
	//	strcat(PATH5, PATH3);
	//	//printf("Recording started...");
	//	system(PATH5);
	//	//printf("Recording ended...");

	//}
	//else{
	//	//exit(0);
	//}





	//DC SHIFTING DATA
	strcpy(PATH_WRITE, ROOT_SAVE);
	strcat(PATH_WRITE, "T_184101038_");
	_itoa(v_test, UTT, 10);
	strcat(PATH_WRITE, UTT);
	strcat(PATH_WRITE, "_");
	_itoa(u_test, UTT, 10);
	strcat(PATH_WRITE, UTT);
	strcat(PATH_WRITE, "_DC.txt");
	//File name is now "184101038_digit_utteranceNumber_DC.txt"
	//and will be created at ROOT_SAVE[] path after function call

	strcpy(PATH_READ, ROOT_SAVE);
	strcat(PATH_READ, "184101038_");
	_itoa(v_test, UTT, 10);
	strcat(PATH_READ, UTT);
	strcat(PATH_READ, "_");
	_itoa(u_test, UTT, 10);
	strcat(PATH_READ, UTT);
	strcat(PATH_READ, ".txt");
	//File name is now "184101038_digit_utteranceNumber.txt"
	//and will be read from ROOT_DATA[] path after function call

	DC_Shift();

	//NORMALIZATION

	strcpy(PATH_WRITE, ROOT_SAVE);
	strcat(PATH_WRITE, "T_184101038_");
	_itoa(v_test, UTT, 10);
	strcat(PATH_WRITE, UTT);
	strcat(PATH_WRITE, "_");
	_itoa(u_test, UTT, 10);
	strcat(PATH_WRITE, UTT);
	strcat(PATH_WRITE, "_NORM.txt");
	//File name is now "184101038_digit_utteranceNumber_NORM.txt"
	//and will be created at ROOT_SAVE[] path after function call

	strcpy(PATH_READ, ROOT_SAVE);
	strcat(PATH_READ, "T_184101038_");
	_itoa(v_test, UTT, 10);
	strcat(PATH_READ, UTT);
	strcat(PATH_READ, "_");
	_itoa(u_test, UTT, 10);
	strcat(PATH_READ, UTT);
	strcat(PATH_READ, "_DC.txt");
	//File name is now "184101038_digit_utteranceNumber_DC.txt"
	//and will be read from ROOT_SAVE[] path after function call

	Normalize();

	//OPTIMAL FRAME CHOOSING

	strcpy(PATH_READ, ROOT_SAVE);
	strcat(PATH_READ, "T_184101038_");
	_itoa(v_test, UTT, 10);
	strcat(PATH_READ, UTT);
	strcat(PATH_READ, "_");
	_itoa(u_test, UTT, 10);
	strcat(PATH_READ, UTT);
	strcat(PATH_READ, "_NORM.txt");
	//File name is now "184101038_DIGIT_utteranceNumber_NORM.txt"
	//and will be read from ROOT_SAVE[] path after function call

	strcpy(PATH_WRITE, ROOT_SAVE);
	strcat(PATH_WRITE, "T_184101038_");
	_itoa(v_test, UTT, 10);
	strcat(PATH_WRITE, UTT);
	strcat(PATH_WRITE, "_");
	_itoa(u_test, UTT, 10);
	strcat(PATH_WRITE, UTT);
	strcat(PATH_WRITE, "_FRAME.txt");
	//File name is now "184101038_DIGIT_utteranceNumber_FRAME.txt"
	//and will be created at ROOT_SAVE[] path after function call

	Frame_Block();

	//Multiplying with Hamming Window		

	strcpy(PATH_WRITE, ROOT_SAVE);
	strcat(PATH_WRITE, "T_184101038_");
	_itoa(v_test, UTT, 10);
	strcat(PATH_WRITE, UTT);
	strcat(PATH_WRITE, "_");
	_itoa(u_test, UTT, 10);
	strcat(PATH_WRITE, UTT);
	strcat(PATH_WRITE, "_FRAMEHAM.txt");
	//File name is now "184101038_DIGIT_utteranceNumber_FRAMEHAM.txt"
	//and will be created at ROOT_SAVE[] path after function call

	strcpy(PATH_READ, ROOT_SAVE);
	strcat(PATH_READ, "T_184101038_");
	_itoa(v_test, UTT, 10);
	strcat(PATH_READ, UTT);
	strcat(PATH_READ, "_");
	_itoa(u_test, UTT, 10);
	strcat(PATH_READ, UTT);
	strcat(PATH_READ, "_FRAME.txt");
	//File name is now "184101038_DIGIT_utteranceNumber_FRAME.txt"
	//and will be read from ROOT_SAVE[] path after function call

	Apply_Hamming_Window();

	//Calculation of Ri's


	strcpy(PATH_WRITE, ROOT_SAVE);
	strcat(PATH_WRITE, "T_184101038_");
	_itoa(v_test, UTT, 10);
	strcat(PATH_WRITE, UTT);
	strcat(PATH_WRITE, "_");
	_itoa(u_test, UTT, 10);
	strcat(PATH_WRITE, UTT);
	strcat(PATH_WRITE, "_R.txt");
	//File name is now "184101038_DIGIT_utteranceNumber_R.txt"
	//and will be created at ROOT_SAVE[] path after function call

	strcpy(PATH_READ, ROOT_SAVE);
	strcat(PATH_READ, "T_184101038_");
	_itoa(v_test, UTT, 10);
	strcat(PATH_READ, UTT);
	strcat(PATH_READ, "_");
	_itoa(u_test, UTT, 10);
	strcat(PATH_READ, UTT);
	strcat(PATH_READ, "_FRAMEHAM.txt");
	//File name is now "184101038_DIGIT_utteranceNumber_FRMAEHAM.txt"
	//and will be read from ROOT_SAVE[] path after function call

	RCalc();

	//Calculation of ai's

	strcpy(PATH_WRITE, ROOT_SAVE);
	strcat(PATH_WRITE, "T_184101038_");
	_itoa(v_test, UTT, 10);
	strcat(PATH_WRITE, UTT);
	strcat(PATH_WRITE, "_");
	_itoa(u_test, UTT, 10);
	strcat(PATH_WRITE, UTT);
	strcat(PATH_WRITE, "_A.txt");
	//File name is now "184101038_DIGIT_utteranceNumber_A.txt"
	//and will be created at ROOT_SAVE[] path after function call

	strcpy(PATH_READ, ROOT_SAVE);
	strcat(PATH_READ, "T_184101038_");
	_itoa(v_test, UTT, 10);
	strcat(PATH_READ, UTT);
	strcat(PATH_READ, "_");
	_itoa(u_test, UTT, 10);
	strcat(PATH_READ, UTT);
	strcat(PATH_READ, "_R.txt");
	//File name is now "184101038_DIGIT_utteranceNumber_R.txt"
	//and will be read from ROOT_SAVE[] path after function call

	ACalc();

	//Calculation of windowed Ci's

	strcpy(PATH_WRITE, ROOT_SAVE);
	strcat(PATH_WRITE, "T_184101038_");
	_itoa(v_test, UTT, 10);
	strcat(PATH_WRITE, UTT);
	strcat(PATH_WRITE, "_");
	_itoa(u_test, UTT, 10);
	strcat(PATH_WRITE, UTT);
	strcat(PATH_WRITE, "_C.txt");
	//File name is now "184101038_DIGIT_utteranceNumber_C.txt"
	//and will be created at ROOT_SAVE[] path after function call

	strcpy(PATH_READ, ROOT_SAVE);
	strcat(PATH_READ, "T_184101038_");
	_itoa(v_test, UTT, 10);
	strcat(PATH_READ, UTT);
	strcat(PATH_READ, "_");
	_itoa(u_test, UTT, 10);
	strcat(PATH_READ, UTT);
	strcat(PATH_READ, "_A.txt");
	//File name is now "184101038_DIGIT_utteranceNumber_A.txt"
	//and will be read from ROOT_SAVE[] path after function call

	CCalc();

	//Read code book
	strcpy(PATH_READ, ROOT_SAVE);
	strcat(PATH_READ, "Code_Book_32.txt");
	//File name is now "Code_Book_32.txt"
	//and will be read from ROOT_SAVE[] path after function call

	ReadCodebook();

	//Finding the observation sequence

	strcpy(PATH_WRITE, ROOT_SAVE);
	strcat(PATH_WRITE, "T_184101038_");
	_itoa(v_test, UTT, 10);
	strcat(PATH_WRITE, UTT);
	strcat(PATH_WRITE, "_");
	_itoa(u_test, UTT, 10);
	strcat(PATH_WRITE, UTT);
	strcat(PATH_WRITE, "_OBS.txt");
	//File name is now "184101038_DIGIT_utteranceNumber_OBS.txt"
	//and will be created at ROOT_SAVE[] path after function call

	strcpy(PATH_READ, ROOT_SAVE);
	strcat(PATH_READ, "T_184101038_");
	_itoa(v_test, UTT, 10);
	strcat(PATH_READ, UTT);
	strcat(PATH_READ, "_");
	_itoa(u_test, UTT, 10);
	strcat(PATH_READ, UTT);
	strcat(PATH_READ, "_C.txt");
	//File name is now "184101038_DIGIT_utteranceNumber_C.txt"
	//and will be read from ROOT_SAVE[] path after function call

	MakeObservationSeq();

	strcpy(PATH_READ, ROOT_SAVE);
	strcat(PATH_READ, "T_184101038_");
	_itoa(v_test, UTT, 10);
	strcat(PATH_READ, UTT);
	strcat(PATH_READ, "_");
	_itoa(u_test, UTT, 10);
	strcat(PATH_READ, UTT);
	strcat(PATH_READ, "_OBS.txt");
	//File name is now "184101038_DIGIT_utteranceNumber_OBS.txt"
	//and will be read from ROOT_SAVE[] path after function call

	ReadObservations();
	strcpy(FILENAME_FILE, "Hinglish_words");
	strcpy(PATH_READ, ROOT_DATA);
	strcat(PATH_READ, FILENAME_FILE);
	strcat(PATH_READ, ".txt");

	ERR = fopen_s(&fpFilename, PATH_READ, "r");//creates file to write cepstral coefficients Ci's in

	if (ERR){
		printf("Error in OPENING FILE NAMES file");
		scanf("%c");
		//exit(0);
	}
	//Proceeds only if file creating/opening was successful

	while (fscanf(fpFilename, "%s", &FILENAME)){//reads all Ai's per frame and stores them in an array
		if (feof(fpFilename)){
			break;
		}

		strcpy(PATH_READ, ROOT_DATA);
		strcat(PATH_READ, FILENAME);
		strcat(PATH_READ, "_HMM_5.txt");

		//File name is now "184101038_DIGIT_HMM.txt"
		//and will be READ FROM ROOT_SAVE[] path after function call


		readValues();//and call readValues() on it

		forward_procedure();//find the probability

		printf("\nProbability of test word being %s : %le", FILENAME, P);
		if (PMAX < P){
			PMAX = P;
			//recognised_digit = v;//store the model giving the highest
			strcpy(recognized, FILENAME);
		}
	}
	//output answer
	//write answer to file "ANSWER.txt"
	strcpy(PATH_WRITE, ROOT_SAVE);
	strcat(PATH_WRITE, "ANSWER.txt");
	ERR = fopen_s(&fpFilename, PATH_WRITE, "w");//creates file to write cepstral coefficients Ci's in

	if (ERR){
		printf("Error in creating ANSWER.txt file");
		scanf("%c");
		//exit(0);
	}
	fprintf(fpFilename, "%s\n", recognized); //writes the corresponding observation sequence to the ci vector
	fclose(fpFilename);
	//Proceeds only if file creating/opening was successful

	/////////////////////*if (strcmp(recognized, "INVALID")==0){
	////////////////////	printf("\nSorry, word could not be recognised. Please try again!");
	////////////////////}
	////////////////////else{
	////////////////////	printf("\nRecognised word: %s", recognized);
	////////////////////	printf("\nProbability: %le", PMAX);

	////////////////////}*/

}

void ReadObservations(){//makes HMMs most optimal for the observation sequences for all utterances for all digits

	ERR = fopen_s(&fpObs, PATH_READ, "r");//opens file for reading observation sequence

	if (ERR){
		printf("Error in opening Observation sequence file");
		scanf("%c");
		//exit(0);
	}
	//Proceeds only if file creating/opening was successful
	T = 1;
	while (fscanf(fpObs, "%d", &OBS[T++])){//reads all observations 
		if (feof(fpObs)){//when end of file reached, break out of observation read loop
			break;
		}
	}
	T = T - 2;
	fclose(fpObs);//file closed
}

void MakeObservationSeq(){//tranforms cepstral coefficients into observation sequences using codebook

	ERR = fopen_s(&fpObs, PATH_WRITE, "w");//opens OBSERVATION SEQUENCE file for each digit AND EACH UTTERANCE in WRITE mode

	if (ERR){
		printf("Error in opening Observation Sequence file");
		scanf("%c");
		//exit(0);
	}
	//Proceeds only if file creating/opening was successful

	ERR = fopen_s(&fpC, PATH_READ, "r");//opens windowed cepstral coefficient file for each digit in read mode

	if (ERR){
		printf("Error in opening C file");
		scanf("%c");
		//exit(0);
	}
	//Proceeds only if file creating/opening was successful

	k = 0;
	j = 1;
	while (fscanf(fpC, "%lf", &C[j++])){//reads all Ci's 
		if (feof(fpC)){
			break;
		}
		if (j == 13){
			MINTOKH = 10000;
			MINTOKHI = 100;
			for (i = 1; i <= CB_SIZE; i++){//compares Cepstral vector with code vectors by nearest neighbour rule
				TOKH = 0;
				for (j = 1; j < 13; j++){//calculate the Tokhura's distance with every code vector 
					TOKH += TOKHURA[j - 1] * (CODEBOOK[i][j] - C[j])* (CODEBOOK[i][j] - C[j]);
				}
				//TOKHURA[] contains Tokhura's weights
				if (MINTOKH>TOKH){
					MINTOKH = TOKH;//minimum distance
					MINTOKHI = i;//minimum distance code vector index
				}
			}
			fprintf(fpObs, "%d\n", MINTOKHI); //writes the corresponding observation sequence to the ci vector
			j = 1;
			k++;//keeps count of number of Ci sets have been read			
		}
	}

	fclose(fpC);//Ci file closed
	fclose(fpObs);//Observation Sequence file closed

}

void ReadCodebook(){//reads Code book

	ERR = fopen_s(&fpCodebook, PATH_READ, "r");//opens codebook in read mode

	if (ERR){
		printf("Error in opening Code book file");
		scanf("%c");
		//exit(0);
	}
	//Proceeds only if file creating/opening was successful

	i = 1;
	j = 1;
	while (fscanf(fpCodebook, "%lf", &CODEBOOK[i][j++])){//reads all Code vectors
		if (feof(fpCodebook)){
			break;
		}
		if (j == 13){
			j = 1;
			i++;//keeps count of number of Ci sets have been read			
		}
	}
	CB_SIZE = i - 1;
	fclose(fpCodebook);//Codebook file closed
}

void forward_procedure(){
	//initialization
	for (i = 1; i <= T; i++){
		for (j = 1; j <= N; j++){
			alpha[i][j] = 0;
		}
	}
	for (i = 1; i <= N; i++){
		alpha[1][i] = PI[i] * B[i][OBS[1]];
	}
	//induction step
	for (t = 1; t <= T - 1; t++){
		for (j = 1; j <= N; j++){
			for (i = 1; i <= N; i++){
				alpha[t + 1][j] += alpha[t][i] * A[i][j];
			}
			alpha[t + 1][j] *= B[j][OBS[t + 1]];
		}
	}
	/*printf("Alpha\n");
	for (t = 1; t <= T; t++){
	for (i = 1; i <= N; i++){
	printf("%le\t", alpha[t][i]);
	}
	printf("\n");
	}
	*/
	//termination
	P = 0;
	for (i = 1; i <= N; i++){
		P += alpha[T][i];
	}
}

void readValues(){

	ERR = fopen_s(&fpInitialModel, PATH_READ, "r");//opens file for reading initial PI,A,B

	if (ERR){
		printf("Error in opening Start_Model.txt");
		scanf("%c");
		//exit(0);
	}
	//Proceeds only if file creating/opening was successful
	for (i = 1; i <= N; i++){
		if (feof(fpInitialModel)){//when end of file reached, break out of sample read loop
			return;
		}
		fscanf(fpInitialModel, "%lf", &PI[i]);
	}

	for (i = 1; i <= N; i++){
		for (j = 1; j <= N; j++){
			if (feof(fpInitialModel)){//when end of file reached, break out of sample read loop
				return;
			}
			fscanf(fpInitialModel, "%lf", &A[i][j]);
		}
	}

	for (i = 1; i <= N; i++){
		for (j = 1; j <= M; j++){
			if (feof(fpInitialModel)){//when end of file reached, break out of sample read loop
				return;
			}
			fscanf(fpInitialModel, "%lf", &B[i][j]);
		}
	}

	fclose(fpInitialModel);//file closed
}

void MakeCepstral(){//tranforms raw speech data into sets of cepstral vectors

	/*
	Before calling the functions, paths are set appropriately
	*/
	strcpy(FILENAME_FILE, "Universe4_file.txt");
	/*
	Since the two sets of utterances have been recorded in two different sessions,
	two DC OFFSET calculations have been done.
	*/
	//DC OFFSET CALCULATION FOR DIGITS 0 TO 4
	strcpy(PATH_READ, ROOT_DATA);
	strcat(PATH_READ, "Silence.txt");
	//File name is "Silence_0_4.txt"
	//and will be read from ROOT_DATA[] path after function call

	DCCalc();

	strcpy(PATH_READ, ROOT_DATA);
	strcat(PATH_READ, FILENAME_FILE);

	ERR = fopen_s(&fpFilename, PATH_READ, "r");//creates file to write cepstral coefficients Ci's in

	if (ERR){
		printf("Error in OPENING FILE NAMES file");
		scanf("%c");
		//exit(0);
	}
	//Proceeds only if file creating/opening was successful
	//fscanf(fpFilename, "%s", FILENAME);
	while (fscanf(fpFilename, "%s", &FILENAME)){//reads all Ai's per frame and stores them in an array
		if (feof(fpFilename)){
			break;
		}
		printf("%s", FILENAME);
		//DC SHIFTING DATA
		strcpy(PATH_WRITE, ROOT_SAVE);
		strcat(PATH_WRITE, FILENAME);
		strcat(PATH_WRITE, "_DC.txt");
		//File name is now "184101038_digit_utteranceNumber_DC.txt"
		//and will be created at ROOT_SAVE[] path after function call

		strcpy(PATH_READ, ROOT_DATA);
		strcat(PATH_READ, FILENAME);
		strcat(PATH_READ, ".txt");
		//File name is now "184101038_digit_utteranceNumber.txt"
		//and will be read from ROOT_DATA[] path after function call

		DC_Shift();

		//NORMALIZATION

		strcpy(PATH_WRITE, ROOT_SAVE);
		strcat(PATH_WRITE, FILENAME);
		strcat(PATH_WRITE, "_NORM.txt");
		//File name is now "184101038_digit_utteranceNumber_NORM.txt"
		//and will be created at ROOT_SAVE[] path after function call

		strcpy(PATH_READ, ROOT_SAVE);
		strcat(PATH_READ, FILENAME);
		strcat(PATH_READ, "_DC.txt");
		//File name is now "184101038_digit_utteranceNumber_DC.txt"
		//and will be read from ROOT_SAVE[] path after function call

		Normalize();


		//OPTIMAL FRAME CHOOSING

		strcpy(PATH_READ, ROOT_SAVE);
		strcat(PATH_READ, FILENAME);
		strcat(PATH_READ, "_NORM.txt");
		//File name is now "184101038_DIGIT_utteranceNumber_NORM.txt"
		//and will be read from ROOT_SAVE[] path after function call

		strcpy(PATH_WRITE, ROOT_SAVE);
		strcat(PATH_WRITE, FILENAME);
		strcat(PATH_WRITE, "_FRAME.txt");
		//File name is now "184101038_DIGIT_utteranceNumber_FRAME.txt"
		//and will be created at ROOT_SAVE[] path after function call

		Frame_Block();

		//Multiplying with Hamming Window		

		strcpy(PATH_WRITE, ROOT_SAVE);
		strcat(PATH_WRITE, FILENAME);
		strcat(PATH_WRITE, "_FRAMEHAM.txt");
		//File name is now "184101038_DIGIT_utteranceNumber_FRAMEHAM.txt"
		//and will be created at ROOT_SAVE[] path after function call

		strcpy(PATH_READ, ROOT_SAVE);
		strcat(PATH_READ, FILENAME);
		strcat(PATH_READ, "_FRAME.txt");
		//File name is now "184101038_DIGIT_utteranceNumber_FRAME.txt"
		//and will be read from ROOT_SAVE[] path after function call

		Apply_Hamming_Window();

		//Calculation of Ri's


		strcpy(PATH_WRITE, ROOT_SAVE);
		strcat(PATH_WRITE, FILENAME);
		strcat(PATH_WRITE, "_R.txt");
		//File name is now "184101038_DIGIT_utteranceNumber_R.txt"
		//and will be created at ROOT_SAVE[] path after function call

		strcpy(PATH_READ, ROOT_SAVE);
		strcat(PATH_READ, FILENAME);
		strcat(PATH_READ, "_FRAMEHAM.txt");
		//File name is now "184101038_DIGIT_utteranceNumber_FRMAEHAM.txt"
		//and will be read from ROOT_SAVE[] path after function call

		RCalc();

		//Calculation of ai's

		strcpy(PATH_WRITE, ROOT_SAVE);
		strcat(PATH_WRITE, FILENAME);
		strcat(PATH_WRITE, "_A.txt");
		//File name is now "184101038_DIGIT_utteranceNumber_A.txt"
		//and will be created at ROOT_SAVE[] path after function call

		strcpy(PATH_READ, ROOT_SAVE);
		strcat(PATH_READ, FILENAME);
		strcat(PATH_READ, "_R.txt");
		//File name is now "184101038_DIGIT_utteranceNumber_R.txt"
		//and will be read from ROOT_SAVE[] path after function call

		ACalc();

		//Calculation of windowed Ci's

		strcpy(PATH_WRITE, ROOT_SAVE);
		strcat(PATH_WRITE, FILENAME);
		strcat(PATH_WRITE, "_C.txt");
		//File name is now "184101038_DIGIT_utteranceNumber_C.txt"
		//and will be created at ROOT_SAVE[] path after function call

		strcpy(PATH_READ, ROOT_SAVE);
		strcat(PATH_READ, FILENAME);
		strcat(PATH_READ, "_A.txt");
		//File name is now "184101038_DIGIT_utteranceNumber_A.txt"
		//and will be read from ROOT_SAVE[] path after function call

		CCalc();

	}

	fclose(fpFilename);

}

void DCCalc(){
	//START OF DC-OFFSETTING MODULE
	DC_OFF = 0;
	j = 0;
	k = 0;
	ERR = fopen_s(&fpSilence, PATH_READ, "r");//opens silence file in read mode

	if (ERR){
		printf("Error in opening silence file");
		scanf("%c");
		//exit(0);
	}
	//Proceeds only if file creating/opening was successful

	for (i = 1; i <= 5; i++){//checks if file data is preceeded by header data or not and proceeds accordingly
		fgets(BUFF, 100, fpSilence);
		if (i == 1 && BUFF[0] != 'S'){
			sscanf_s(BUFF, "%lf", &ARR[j++]);
			break;
		}
	}
	while (fscanf(fpSilence, "%lf", &ARR[j++])){//reads each sample data and stores 100 of them at a time in ARR[]
		if (feof(fpSilence)){//when end of file reached, break out of sample read loop
			break;
		}
		if (j == 100){
			k++;
			j = 0;
			//trim beginning module start
			if (k < 3){
				//do nothing
			}
			//trim beginning module start
			else{
				for (j = 0; j < 100; j++){
					DC_OFF = DC_OFF + ARR[j];//summing over all sample values in silence file
				}
				j = 0;
			}
		}
	}
	for (i = 0; i < j; i++){
		DC_OFF = DC_OFF + ARR[i];//summing over last remaining sample values in silence file
	}
	DC_OFF = DC_OFF / ((k - 2) * 100 + j);//finding the average value and storing in variable DC_OFF
	fclose(fpSilence);//silence file closed
	//DC_OFF=0.5;
	////END OF DC-OFFSETTING MODULE
}

void DC_Shift(){//return MAX value for normalization
	//DC OFFSETTING DATA

	j = 0;
	k = 0;
	MAX = 0;

	ERR = fopen_s(&fpVoiceDC, PATH_WRITE, "w");//opens file for writing dc offsetted values

	if (ERR){
		printf("Error in creating new voice file");
		scanf("%c");
		//exit(0);
	}
	//Proceeds only if file creating/opening was successful

	ERR = fopen_s(&fpVoice, PATH_READ, "r");//opens voice file for reading raw sample values

	if (ERR){
		printf("Error in opening voice file");
		scanf("%c");
		//exit(0);
	}
	//Proceeds only if file creating/opening was successful

	for (i = 1; i <= 5; i++){//optionally runs either 5 times or only once
		fgets(BUFF, 100, fpVoice);//reads first 5 lines of header if present and puts in buffer BUFF[] one at a time
		if (i == 1 && BUFF[0] != 'S'){//checks if file data is preceeded by header data or not and proceeds accordingly
			sscanf_s(BUFF, "%lf", &ARR[j++]);
			break;
		}
	}
	while (fscanf(fpVoice, "%lf", &ARR[j++])){//reads each sample data and stores 100 of them at a time in ARR[]
		if (feof(fpVoice)){
			break;
		}
		if (j == 100){//if next 100 samples have been read from file
			k++;//keep count of number of 100 samples read uptill now
			for (j = 0; j < 100; j++){
				ARR[j] = ARR[j] - DC_OFF;//dc offsets all 100 values in ARR[]
				fprintf(fpVoiceDC, "%lf\n", ARR[j]);//writes it into file for dc offsetted samples
				if (ARR[j]<0){//finds absolute value of sample
					X = -ARR[j];
				}
				else{
					X = ARR[j];
				}
				if (X>MAX){//stores maximum absolute dc offsetted sample value in entire file in MAX
					MAX = X;
				}
			}
			j = 0;
		}//end of if
	}//end of while
	fclose(fpVoice);//voice file closed
	fclose(fpVoiceDC);//dc offsetted voice file closed

	//END DC-OFFSETTING DATA
}

void Hamming_Window(){
	//Calculating the Hamming window

	for (j = 0; j < 320; j++){
		HAM[j] = 0.54 - 0.46 * cos((2 * 180.0*j) / 319.0);
	}
	//end of Hamming window calculation
}

void Raised_Sine_Window(){
	//Calculating the raised sine window
	W[0] = 1;
	for (j = 1; j <= p; j++){
		W[j] = 1 + 6 * sin(180.0*j / 12);
	}
	//end of raised sine window calculation
}

void Normalize(){

	ERR = fopen_s(&fpVoiceNorm, PATH_WRITE, "w");//creates new file to write normalized sample values in

	if (ERR){
		printf("Error in creating new voice file");
		scanf("%c");
		//exit(0);
	}
	//Proceeds only if file creating/opening was successful

	ERR = fopen_s(&fpVoiceDC, PATH_READ, "r");//opens file for dc offsetted values in read mode

	if (ERR){
		printf("Error in opening voice file");
		scanf("%c");
		//exit(0);
	}
	//Proceeds only if file creating/opening was successful

	NORM = 5000.0 / MAX;//normalization constant
	j = 0;
	k = 0;

	while (fscanf(fpVoiceDC, "%lf", &ARR[j++])){//reads each sample data and stores 100 of them at a time in ARR[]
		if (feof(fpVoiceDC)){//if end of file reached, exit while loop
			break;
		}
		if (j == 100){//once next 100 samples have been read
			k++;//keep count of number of 100 samples read
			for (j = 0; j < 100; j++){//normalizes all 100 values in ARR[]
				ARR[j] = ARR[j] * NORM;//by multiplying with normalizing constant
				fprintf(fpVoiceNorm, "%lf\n", ARR[j]);//writes each normalized sample value in file
			}
			j = 0;
		}
	}
	fclose(fpVoiceDC);//dc offsetted voice file closed
	fclose(fpVoiceNorm);//normalized voice file closed
	//END NORMALIZATION
}

void Frame_Block(){

	j = 0;
	k = 0;
	k1 = 0;//start marker

	ERR = fopen_s(&fpVoiceNormTemp, PATH_READ, "r");//opens normalized sample file again

	if (ERR){
		printf("Error in opening normalized voice file");
		scanf("%c");
		//exit(0);
	}
	//Proceeds only if file creating/opening was successful

	ERR = fopen_s(&fpVoiceFrame, PATH_WRITE, "w");//creates new file to write frame data in

	if (ERR){
		printf("Error in creating new frame file");
		scanf("%c");
		//exit(0);
	}
	//Proceeds only if file creating/opening was successful

	while (fscanf(fpVoiceNormTemp, "%lf", &FRAME[j++])){//reads each sample data and stores 320 of them at a time in FRAME[]
		if (feof(fpVoiceNormTemp)){
			break;
		}
		if (j == 320){
			for (k1 = 0; k1 < 320; k1++){//Frames are stored
				fprintf(fpVoiceFrame, "%lf\n", FRAME[k1]);//inside file
			}
			for (k1 = 80; k1 < 320; k1++){//shift latter 240 samples forward
				FRAME[k1 - 80] = FRAME[k1];
			}
			j = 240;//80 more samples will be read
			//effectively shifting the previous frame by 80 samples
			//to get new frame
		}
	}//end of while loop taking every sample

	fclose(fpVoiceNormTemp);//normalized file closed
	fclose(fpVoiceFrame);//frame samples file closed
}

void Apply_Hamming_Window(){

	ERR = fopen_s(&fpVoiceFrameHamming, PATH_WRITE, "w");//creates new file to write Hamming windowed frame data in

	if (ERR){
		printf("Error in creating new Frame file");
		scanf("%c");
		//exit(0);
	}
	//Proceeds only if file creating/opening was successful

	ERR = fopen_s(&fpVoiceFrame, PATH_READ, "r");//opens frame file in read mode

	if (ERR){
		printf("Error in opening frame file");
		scanf("%c");
		//exit(0);
	}
	//Proceeds only if file creating/opening was successful

	j = 0;
	k = 0;

	while (fscanf(fpVoiceFrame, "%lf", &FRAME[j++])){//reads each sample data and stores 320 of them at a time in FRAME[]
		if (feof(fpVoiceFrame)){
			break;
		}
		if (j == 320){//once next 320 samples (one frame) have been read
			for (j = 0; j < 320; j++){
				FRAME[j] *= HAM[j];//multiply each frame sample with corresponding Hamming Window value
				fprintf(fpVoiceFrameHamming, "%lf\n", FRAME[j]);//and write resultant data into file
			}
			j = 0;
			k++;//keeps count of number of frames read
		}
	}

	fclose(fpVoiceFrameHamming);//Hamming windowed frame file closed
	fclose(fpVoiceFrame);//frame samples file closed
	//End of applying Hamming window
}

void RCalc(){

	ERR = fopen_s(&fpR, PATH_WRITE, "w");//creates new file to write Ri values in

	if (ERR){
		printf("Error in creating new R file");
		scanf("%c");
		//exit(0);
	}
	//Proceeds only if file creating/opening was successful

	ERR = fopen_s(&fpVoiceFrame, PATH_READ, "r");//opens windowed frame file in read mode

	if (ERR){
		printf("Error in opening frame file");
		scanf("%c");
		//exit(0);
	}
	//Proceeds only if file creating/opening was successful

	for (j = 0; j <= p; j++){
		R[j] = 0;
	}

	j = 0;
	k = 0;

	while (fscanf(fpVoiceFrame, "%lf", &FRAME[j++])){//reads each sample data and stores 320 of them at a time in FRAME[]
		if (feof(fpVoiceFrame)){
			break;
		}
		if (j == 320){//once next 320 samples (one frame) have been read
			for (i = 0; i <= p; i++){
				for (j = 0; j < 320 - i; j++){
					R[i] += FRAME[j] * FRAME[j + i];//calculate Ri values
				}
				fprintf(fpR, "%lf\n", R[i]); //and write into file
			}
			k++;//keeps count of number of frames read
			j = 0;
		}
	}

	fclose(fpR);//Ri coefficient file closed
	fclose(fpVoiceFrame);//Hamming windowed frame file closed
	//End of Calculation of Ri's (65 values per utterance per vowel- 12 values per frame)
}

void ACalc(){
	ERR = fopen_s(&fpA, PATH_WRITE, "w");//creates new file for writing LPC coefficients

	if (ERR){
		printf("Error in creating new A file");
		scanf("%c");
		//exit(0);
	}
	//Proceeds only if file creating/opening was successful

	ERR = fopen_s(&fpR, PATH_READ, "r");//opens Ri file in read mode

	if (ERR){
		printf("Error in opening R file");
		scanf("%c");
		//exit(0);
	}
	//Proceeds only if file creating/opening was successful

	for (i = 0; i <= p; i++){
		for (j = 0; j <= p; j++){
			AA[i][j] = 0;
		}
	}

	j = 0;
	k = 0;

	while (fscanf(fpR, "%lf", &R[j++])){//reads all Ri's per frame and stores in an array
		if (feof(fpR)){
			break;
		}
		if (j == 13){//once next 13 Ri values (for one frame) have been read from file			

			//Durbin's Algo
			E[0] = R[0];
			R0[k] = R[0];
			for (i = 1; i <= p; i++){

				K[i] = R[i];
				S = 0;

				for (j = 1; j < i; j++){
					S = S + AA[i - 1][j] * R[i - j];

				}
				K[i] = K[i] - S;
				K[i] /= E[i - 1];

				AA[i][i] = K[i];
				for (j = 1; j < i; j++){
					AA[i][j] = AA[i - 1][j] - (K[i] * AA[i - 1][i - j]);
				}
				E[i] = E[i - 1] * (1 - K[i] * K[i]);
			}

			//End of Durbin's Algo
			for (i = 1; i <= p; i++){
				fprintf(fpA, "%lf\n", AA[p][i]);//writes the calculated LPC coefficients into file
			}

			j = 0;
			k++;//keeps count of the number of Ri sets covered
		}
	}

	fclose(fpA);//Ai file closed
	fclose(fpR);//Ri file closed
	//End of calculation of ai's (60 values per utterance per vowel)

}

void CCalc(){

	ERR = fopen_s(&fpC, PATH_WRITE, "w");//creates file to write cepstral coefficients Ci's in

	if (ERR){
		printf("Error in creating new C file");
		scanf("%c");
		//exit(0);
	}
	//Proceeds only if file creating/opening was successful

	ERR = fopen_s(&fpA, PATH_READ, "r");//opens LPC coefficients Ai file in read mode

	if (ERR){
		printf("Error in opening A file");
		scanf("%c");
		//exit(0);
	}
	//Proceeds only if file creating/opening was successful

	for (j = 0; j <= p; j++){
		C[j] = 0;
		AI[j] = 0;
	}

	j = 1;
	k = 0;

	while (fscanf(fpA, "%lf", &AI[j++])){//reads all Ai's per frame and stores them in an array
		if (feof(fpA)){
			break;
		}
		if (j == 13){//once next 12 (for one frame) LPC coefficients have been read
			//calculate the 13 cepstral coefficients
			//C[0] = log2(R0[k]);
			for (i = 1; i <= p; i++){
				C[i] = AI[i];
				for (j = 1; j < i; j++){
					C[i] += (j*1.0 / i)*C[j] * AI[i - j];
				}
			}

			for (i = 1; i <= p; i++){//and write them to the file
				fprintf(fpC, "%lf\n", C[i] * W[i]);//after multiplying with raised sine window function W[]				
			}

			j = 1;//LPC coefficients are stored from A[1] to A[12] for each frame
			k++;//keeps count of number of LPC coefficient sets have been read

		}
	}

	fclose(fpA);//Ai file closed
	fclose(fpC);//Ci file closed

	//End of calculation of Ci's (65 values per utterance per vowel)
}

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	
	//HAMMING WINDOW CALCULATION
	Hamming_Window();

	//RAISED SINE WINDOW CALCULATION
	Raised_Sine_Window();

	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew Form1());
	return 0;
}


