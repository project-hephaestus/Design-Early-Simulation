#ifndef _stub_bidder_h
#define _stub_bidder_h

#include <stdarg.h>
#include "gridlabd.h"
#include "auction.h"

class stub_bidder {
public:
	stub_bidder(MODULE *);
	int create(void);
	int init(OBJECT *parent);
	int isa(char *classname);
	TIMESTAMP presync(TIMESTAMP t0, TIMESTAMP t1);
	TIMESTAMP sync(TIMESTAMP t0, TIMESTAMP t1);
	TIMESTAMP postsync(TIMESTAMP t0, TIMESTAMP t1);
	static CLASS *oclass;
public:
	double bid_period;
	int16 count;
	int16 change;
	object market;
	//object market_second;
	typedef enum {
		BUYER=0, 
		SELLER=1,
	} ROLE;
	enumeration role;
	double price;
	double quantity;
	double cost;
	int64 *thismkt_id;
private:
	int64 next_t;
	KEY new_bid_id;
	KEY lastbid_id;
	int64 lastmkt_id;
};

#endif //_stub_bidder_h
