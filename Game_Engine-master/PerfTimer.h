#ifndef __PERFTIMER_H__
#define __PERFTIMER_H__

#include "Globals.h"
#include "SDL\include\SDL.h"

class PerfTimer
{
public:

	// Constructor
	PerfTimer();

	void Start();
	double ReadMs() const;
	int ReadTicks() const;

private:
	int	started_at;
	static int frequency;
};

#endif //__PERFTIMER_H__