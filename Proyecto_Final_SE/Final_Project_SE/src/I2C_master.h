/*
 * I2C_master.h
 *
 *  Created on: 24 nov 2023
 *      Author: Hezitzaile
 */

#ifndef I2C_MASTER_H_
#include "hal_data.h"
#define I2C_MASTER_H_

fsp_err_t init_i2c(void);
void initialize_LCD(void);
void clear_i2c(void);
fsp_err_t write_LCD(uint8_t line[], uint8_t msg[]);

#endif /* I2C_MASTER_H_ */
