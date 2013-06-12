#include <stdio.h>
#include <stdlib.h>

#include "core.h"

cycle_t *cycle_create()
{
	cycle_t *cycle;

	cycle = calloc(sizeof(cycle_t), 1);
	if(cycle == NULL){
		//TODO:
		return NULL;
	}

	cycle->pool = cpool_create(1024);
	if(cycle->pool == NULL){
		//TODO:
		return NULL;
	}

	cycle->cleanup = cycle_destroy;

	return cycle;
}

void cycle_destroy(cycle_t *cycle)
{
	if(cycle)
		free(cycle);
}
