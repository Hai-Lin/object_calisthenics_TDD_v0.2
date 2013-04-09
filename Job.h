#include"utility.h"
#ifndef JOB
#define JOB

class Job {
	private:
		JobType _jobType;
	public:
		Job(JobType);
		bool isThisJobNeedResume();
};

class Jobs {
	private:
		vector<Job*> _jobs;
	public:
		Jobs();
		void addJob(Job*);
		Job* atIndex(int index);
};

#endif
