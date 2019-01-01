/*
 * interfaceMain.h
 *
 *  Created on: 29 dec. 2018
 *      Author: Olof
 */

struct FilterState
{
	uint8_t doneFlag;
	char filterType;
	char filterState;
	uint8_t filterOrder;
	float initMSE;
	float initValue;
	uint8_t vecInd;

	float32_t R_1;
	float32_t R_2;

	float32_t a_1;
	float32_t a_2;
	float32_t a_3;
	float32_t a_4;

	float32_t b_1;
	float32_t b_2;
	float32_t b_3;
	float32_t b_4;
};


void FilterChoice(struct FilterState* fState);
void KalmanMenu(struct FilterState* fState);
void WienerMenu(struct FilterState* fState);
int keypad(void);
void aVecMenu(struct FilterState* fState);
void bVecMenu(struct FilterState* fState);

#ifndef INTERFACE_INTERFACEMAIN_H_
#define INTERFACE_INTERFACEMAIN_H_




#endif /* INTERFACE_INTERFACEMAIN_H_ */
