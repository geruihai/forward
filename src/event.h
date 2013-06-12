#ifndef _EVENT_H_
#define _EVENT_H_

#include "core.h"

typedef int (*event_handle_cb)(event_t *event);

struct event_s
{
	int epfd;

	event_handle_cb handle;

	int write:1;

	int accept:1;

	int instance:1;
};

#endif /*_EVENT_H_*/
