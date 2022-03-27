// Standard headers
#include <stdio.h>
#include <stdlib.h>

// Internal headers
#include "direction.h"
#include "position.h"
#include "spy.h"

// Main header
#include "defender.h"

// Macros
#define UNUSED(x) (void)(x) // Auxiliary to avoid error of unused parameter

/*----------------------------------------------------------------------------*/
/*                              PUBLIC FUNCTIONS                              */
/*----------------------------------------------------------------------------*/

static bool spy_usado = false;

direction_t execute_defender_strategy(
    position_t defender_position, Spy attacker_spy) {
	UNUSED(defender_position);
	int usar_spy = rand()%10;
	int num = rand()%16;
	
	if(usar_spy == 2 && spy_usado == false){
		position_t atacante = get_spy_position(attacker_spy);
		spy_usado = true;
		UNUSED(atacante);	
	}

	if(spy_usado == false){
		
		if(0<=num && num<=4)
			return (direction_t) DIR_LEFT;
	
		else if(5<=num && num<=8)
			return (direction_t) DIR_DOWN_LEFT;

		else if(num == 9)
			return (direction_t) DIR_DOWN;

		else if(num == 10)
			return (direction_t) DIR_UP_LEFT;
		
		else if(num == 11)
			return (direction_t) DIR_UP;

		else if(num == 12)
			return (direction_t) DIR_STAY;

		else if(num == 13)
			return (direction_t) DIR_UP_RIGHT;

		else if(num == 14)
			return (direction_t) DIR_RIGHT;

		else
			return (direction_t) DIR_DOWN_RIGHT;

	}else{
		
		if(0<=num && num<=4)
			return (direction_t) DIR_LEFT;

		else if(5<=num && num<=8)
			return (direction_t) DIR_UP_LEFT;
	
		else if(num == 9)
			return (direction_t) DIR_DOWN;

		else if(num == 10)
			return (direction_t) DIR_DOWN_LEFT;

		else if(num == 11)
			return (direction_t) DIR_UP;
		
		else if(num == 12)
			return (direction_t) DIR_STAY;

		else if(num == 13)
			return (direction_t) DIR_UP_RIGHT;

		else if(num == 14)
			return (direction_t) DIR_RIGHT;

		else
			return (direction_t) DIR_DOWN_RIGHT;		

	}

}


/*----------------------------------------------------------------------------*/
