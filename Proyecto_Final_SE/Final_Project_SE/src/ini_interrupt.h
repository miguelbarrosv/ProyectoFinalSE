/*
 * ini_interrupt.h
 *
 *  Created on: 23 dic 2023
 *      Author: Hezitzaile
 */

#ifndef INI_INTERRUPT_H_
#define INI_INTERRUPT_H_


fsp_err_t icu_init(void);
fsp_err_t icu_enable(void);
void icu_deinit(void);


#endif /* INI_INTERRUPT_H_ */
