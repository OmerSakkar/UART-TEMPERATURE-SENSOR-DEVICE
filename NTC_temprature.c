/*
 * NTC_temprature.c
 *
 * Created: 4/9/2022 6:29:56 PM
 *  Author: Omer Sakkar
 */ 
#include "NTC_temprature.h"
 
 uint16_t temprature_buffre[AVERAGE_COUNT];
 
 
 /* This function uses Steinhart�Hart equation to calculate temp*/
float calculate_temperature(uint16_t adc_result	)
{
	double thermistor_resistence;
	double log_thermistor_resistence;
	float temprature;
	
	/* First, we need to convert the ADC value to the corresponding
	   thermistor resistor value using the voltage divider equation
	   Rthemistor = Rs * ( (ADCmax / ADCresult) - 1 )				*/	
	thermistor_resistence = RS_resistor_VALUE * ( ( (float)1023/adc_result ) - 1 );
	
	log_thermistor_resistence = log(thermistor_resistence); //find ln(thermistor_resistence)
	
	/* use the Steinhart�Hart equation to calculate temperature:
	   T = = 1 / (A + B[ln(R)] + C[ln(R)]^3).  */                
	temprature = 1 / ( (A_cofficient) + (B_cofficient) * log_thermistor_resistence + (C_cofficient) * log_thermistor_resistence * log_thermistor_resistence * log_thermistor_resistence);
	
	temprature -= 273; 
	
	return temprature;
	
}


/*This function uses moving average filter to filter temprature results */
float filter_temperature(float raw_temperature)
{
	 static uint8_t oldest_sample = 0; 
	 float moving_average = 0.0;
	 
	 temprature_buffre[oldest_sample++] = raw_temperature; //overwrite the oldest sample with the new raw temprature sample . 
	 if (oldest_sample >= AVERAGE_COUNT) 
	 {
		 oldest_sample = 0; 
	 }
	 
	 for(uint8_t i=0; i< AVERAGE_COUNT; i++)
	 {
		moving_average += temprature_buffre[i]; 
	 	moving_average /= AVERAGE_COUNT;	
	 
	 return moving_average; //return filtered temprature		
}


