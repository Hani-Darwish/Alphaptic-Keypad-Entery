/***************************************************************
 *  Source File: EF_SpechialTIMER_cfg.h
 *
 *  Description: using Timer driver to make many features with time
 *				 such as delay , make unstuck functions ,..
 *
 *  History:     Version 1.0  - INIT Version
 *  Date   :     25/08/2014
 *  -------------------------------------------------------
 *  Author :     EmbeddedFab.
 *
 *  Copyright (C) <2014>  <EmbeddedFab>

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>

 **************************************************************/

#ifndef OS_TIMER_CFG_H_
#define OS_TIMER_CFG_H_

#include "../Utilities/std_types.h"
#include "../MCAL/EF_Timer.h"
/**************************************************
 * Definitions
 **************************************************/
#define MAX_NUMBER_OF_TIMERS   		10

/* different IDs*/
#define WAIT_USER_PIN 			0
#define WAIT_KEYCHAR_SCAN_ID         1
//#define TWO_MIN_TIMER_ID			2
//#define ONE_SEC_TIMER_ID	   		3
//#define GET_ALL_FRAME_TIMER_ID	    4
#define UART_TIMER_ID				5
#define SPI_TIMER_ID				6
//#define NRF_SEND_ID                 7
//#define GPS_FRAM_ID                 8
/* using with Special Timer to able  SPI Function to be unstuck */
#define SPI_TIMEOUT  				100/SYSTEMTICKTIME
#define UART_WAIT_TIME				150/SYSTEMTICKTIME
#define GET_ALL_FRAME_TIMEOUT       200/SYSTEMTICKTIME
#define NRF_SEND_TIMEOUT            150/SYSTEMTICKTIME
#define GPS_WAIT_FRAM				100
#define WAIT_USER_PIN_TIMEOUT       1000 // around 15 sec

#define WAIT_KEYCHAR_SCAN_TIMEOUT   50

/**************************************************
 * configuration types
 *************************************************/

typedef struct timer_struct
{
  volatile U32_t   timeOut ;     /* max. time counts                	 */
  volatile U32_t   counter ;	 /* count every Timer Interrupt happened */
  volatile BOOLEAN isTimedout;	 /* check if count == timeOut  			 */
  volatile BOOLEAN isEnables;	 /* check if TimerID is Enable 			 */
}TIMER_ID_str;



#endif