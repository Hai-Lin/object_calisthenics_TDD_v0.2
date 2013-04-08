#include"utility.h"
class Job;
class Resume;

#ifndef JOBSEEKER
#define JOBSEEKER

class JobSeeker {
	private:
		Resume* _resume;
	public:
		JobSeeker(Resume* = NULL);
		bool hasResume();
};

#endif
