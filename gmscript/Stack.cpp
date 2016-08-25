#include "Stack.h"




Stack::Stack(size_t len)
{
	dataptr = new byte[len];
	topptr = dataptr + len;//Ö¸ÏòÕ»µ× 
}

Stack::~Stack()
{
}
