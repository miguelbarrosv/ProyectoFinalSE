/*
 * ADC_pot.h
 *
 *  Created on: 23 nov 2023
 *      Author: Hezitzaile
 */

#ifndef ADC_POT_H_
#include "hal_data.h"
#define ADC_POT_H_

void ADCInit(void);
void ADCStartScan (void);
void ADCWaitConversion (void);
uint16_t ReadADC (adc_channel_t Achan);
//static fsp_err_t ADC_Initialize(void);

#endif /* ADC_POT_H_ */
