/*
 * NTC_temprature.h
 *
 * Created: 4/9/2022 6:25:04 PM
 *  Author: Omer Sakkar
 */ 


#ifndef NTC_TEMPRATURE_H_
#define NTC_TEMPRATURE_H_

#include "Std_macros.h"
#include "math.h"

#define RS_resistor_VALUE 2430

#define AVERAGE_COUNT 10 //number of samples used in the moving average filter formula

/*Steinhart–Hart equation macros for */
#define A_cofficient 0.001470471016183087
#define B_cofficient 0.0002377828020130871
#define C_cofficient 1.0426312286528971e-7

/* --------Functions prototypes ----------------*/


/**
   @brief   Converts ads result to corresponding temperature value check word doc for hardware details
   @param   adc_result: the result of the adc
   @return temperature
*/
float calculate_temperature(uint16_t adc_result	);


/**
   @brief   filter temperature values using moving average filter
   @param   raw temperature
   @return  filtered temperature
*/
float filter_temperature(float raw_temperature);



#endif /* NTC_TEMPRATURE_H_ */