/*
Suppose that the direction variable is declared in the following way:
enum{NORTH, SOUTH, EAST, WEST} direction;

Let x and y be int variables. Write a swtich statement that tesets the value of direction, incrementing x if direction is EAST, decrementing x if direction is WEST, increment y if direction is
SOUTH, and decrementing y if direction is NORTH
*/
int x,y;

enum{NORTH, SOUTH, EAST, WEST} direction;
switch(direction){
	case 'NORTH': y++;
		      break;
	case 'SOUTH': y--;
		      break;
	case 'EAST': x++;
		   break;
	case 'WEST': x--;
		    break;
	default: printf("Error in Direction!");
}