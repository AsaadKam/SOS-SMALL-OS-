/*
 * APP.C
 *
 * Created: 17/12/2019 18:33:53
 *  Author: Asaad
 */

 
          /****Description of application****/
		  
/***********************************************************
 * -We demonstrate SOS by creating two tasks one of them   *
 *  is high priority but both of them have the same        *
 *   periodicity and one of them has higher execution than *
 *   the other one to demonstrate system and simulate it   *
 *  (Take care the system could let a task miss it's time  *
 *   as an exmaple if another task waiting a task execute  *
 *	 as an example if the execute in 3 seconds and         *
 *   another task execute every second surely it will      *
 *    miss the time  )                                     *        
 *********************************************************** 
 * -LED_1_1000mili_Periodic_HIGH_PER--> has execution time *
 *  1 second                                               *
 ***********************************************************                                                      
 * -LED_2_1000mili_Periodic_LOW_PER--> has no execution    *
 *  time.                                                  *
 ***********************************************************/
 
/*- INCLUDES ----------------------------------------------*/
/**Include Dio for LEDs to test**/
#include"DIO.h"
#include"SOS.h"

/*- LOCAL FUNCTIONS IMPLEMENTATION ------------------------*/
void LED_1_1000mili_Periodic_HIGH_PER(void)
{
	DIO_INIT_Pin(1,OUTPUT);
    DIO_toggle_Pin(1);
	/***1 second execution time ***/
    for(int i=0;i<1000;i++)
	{
		for(int i=0;i<1000;i++);
	}
}
void LED_2_1000mili_Periodic_LOW_PER(void)
{
	DIO_INIT_Pin(2,OUTPUT);
    DIO_toggle_Pin(2);
}
int main()
{
	/**Small Os create**/
    SOS_Init();
	/**Create tasks**/ 
	SOS_Start(LED_2_1000mili_Periodic_LOW_PER,1000U,SOS_Function_PERIODIC,1);
	SOS_Start(LED_1_1000mili_Periodic_HIGH_PER,1000U,SOS_Function_PERIODIC,0);
	/*Start small OS dispatching**/
	SOS_Dispatch();
}

