#ifndef _CONN_H_
#define _CONN_H_

#include <stdint.h>
#include <sys/socket.h>
#include <netinet/in.h>

typedef struct lsing_s lsing_t;
typedef struct conn_s conn_t;
typedef struct cpool_s cpool_t;

struct lsing_s
{
	int fd;
	struct sockaddr_in addr;

	uint16_t port;
	int backlog;
};

struct conn_s
{
	int fd;
	struct sockaddr_in addr;

	void *data;
};

struct cpool_s
{
	uint32_t conn_n;
	conn_t *conns;
	uint32_t free_conn_n;
	conn_t *free_conns;
};

conn_t *conn_create();

void conn_destroy();

#endif /*_CONN_H_*/
