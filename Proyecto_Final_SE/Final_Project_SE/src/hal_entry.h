/*
 * hal_entry.h
 *
 *  Created on: 21 dic 2023
 *      Author: Hezitzaile
 */

#ifndef HAL_ENTRY_H_
#define HAL_ENTRY_H_


void update_filter(uint16_t new_value);
void emergency_stop(void);
uint16_t calculate_average();
void parse_value(uint16_t value);


#endif /* HAL_ENTRY_H_ */
