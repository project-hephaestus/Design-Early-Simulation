#include <stdarg.h>
#include "gridlabd.h"
#include "market.h"

#ifndef _market_game_theory_h_
#define _market_game_theory_h_


struct linked_list
{
    char name[60];
	double q_i;
	double c_i;
	double r_i;
    struct linked_list *next;
};
typedef struct linked_list node;  /* node type defined */

	
void create_list(char *name, double q_i, double c_i);
void print_results(node *list);

void find_solution(double d_0);




#endif
