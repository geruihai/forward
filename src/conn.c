#include <stdint.h>
#include <stdlib.h>

#include "conn.h"

lsing_t *lsing_create(uint16_t port, int backlog)
{
	lsing_t *ls;

	ls = calloc(sizeof(lsing_t), 1);
	if(ls == NULL){
		//TODO:
		return NULL;
	}

	return ls;
}

void lsing_destroy(lsing_t *ls)
{
	if(ls)
		free(ls);
}

conn_t *conn_create()
{
	conn_t *conn;

	conn = calloc(sizeof(conn_t), 1);
	if(conn == NULL){
		//TODO:
		return NULL;
	}

	return conn;
}

void conn_destroy(conn_t *conn)
{
	if(conn)
		free(conn);
}

cpool_t *cpool_create(int n)
{
	cpool_t *pool;

	pool = calloc(sizeof(cpool_t), 1);
	if(pool == NULL){
		//TODO:
		return NULL;
	}

	pool->conn_n = n;
	pool->conn = calloc(sizeof(conn_t), n);
	if(pool->conn == NULL){
		//TODO:
		return NULL;
	}

	pool->free_conn_n = n;
	pool->free_conns = pool->conns;

	return pool;
}

void cpool_destroy(cpool_t *pool)
{
	if(pool) 
		free(pool);
}
