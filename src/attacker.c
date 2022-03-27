// Standard headers
#include <stdio.h>
#include <stdlib.h>

// Internal headers
#include "direction.h"
#include "position.h"
#include "spy.h"

// Main header
#include "attacker.h"

// Macros
#define UNUSED(x) (void)(x) // Auxiliary to avoid error of unused parameter

/*----------------------------------------------------------------------------*/
/*                              PUBLIC FUNCTIONS                              */
/*----------------------------------------------------------------------------*/

static bool spy_usado=false;

direction_t execute_attacker_strategy(
    position_t attacker_position, Spy defender_spy) {

 	UNUSED(attacker_position);
	int num = rand()%16;
	int usar_spy = rand()%10;	

	if(usar_spy == 2 && spy_usado == false){
		position_t defensor = get_spy_position(defender_spy);
		spy_usado = true;
		UNUSED(defensor);
	}

	if(spy_usado == false){

		if(0<=num && num<=4)
			return (direction_t) DIR_RIGHT;
	
		else if(5<=num && num<=8)
			return (direction_t) DIR_UP_RIGHT;//diagonal para cima direita
		
		else if(num == 9)
			return (direction_t) DIR_UP;//cima
	
		else if(num == 10)
			return (direction_t) DIR_DOWN_RIGHT;//diagonal para baixo direita
	
		else if(num == 11)
			return (direction_t) DIR_DOWN;//baixo
	
		else if(num == 12)
			return (direction_t) DIR_STAY;//parado
	
		else if(num == 13)
			return (direction_t) DIR_UP_LEFT;//diagonal esquerda cima
	
		else if(num == 14)
			return (direction_t) DIR_LEFT;//esquerda
	
		else 
			return (direction_t) DIR_DOWN_LEFT;//diagonal esquerda baixo

	}else{
		if(0<=num && num<=4)
			return (direction_t) DIR_RIGHT;

		else if(5<=num && num<=8)
			return (direction_t) DIR_DOWN_RIGHT;

		else if(num == 9)
			return (direction_t) DIR_DOWN;

		else if(num == 10)
			return (direction_t) DIR_UP_RIGHT;
		
		else if(num == 11)
			return (direction_t) DIR_UP;

		else if(num == 12)
			return (direction_t) DIR_STAY;

		else if(num == 13)
			return (direction_t) DIR_DOWN_LEFT;

		else if(num == 14)
			return (direction_t) DIR_LEFT;

		else
			return (direction_t) DIR_UP_LEFT;
	}
}


/*----------------------------------------------------------------------------*/
