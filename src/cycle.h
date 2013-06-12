#include <stdio.h>
#include <stdlib.h>

#include "core.h"
#include "conn.h"
#include "event.h"

typedef struct cycle_s cycle_t;
typedef void (*cycle_cleanup_cb)(cycle_t *cycle);

struct cycle_s
{
	cpool_t *pool;

	uint32_t conn_n;
	conn_t *conns;
	uint32_t free_conn_n;
	conn_t *free_conns;

	event_t *rev;
	event_t *wev;

	cycle_cleanup_cb cleanup;

	int open:1;
	int close:1;
};

cycle_t *cycle_create();

void cycle_destroy(cycle_t *cycle);
