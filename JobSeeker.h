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
		Resume* currentResume();
};

class JobSeekers {
	private:
		vector<JobSeeker*> _jobSeekers;
	public:
		JobSeekers();
		void addJobSeeker(JobSeeker*);
		JobSeeker* atIndex(int);
};

#endif
