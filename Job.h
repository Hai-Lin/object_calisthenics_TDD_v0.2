#include"utility.h"
#ifndef JOB
#define JOB
class Recruiter;

class Job {
	private:
		JobType _jobType;
		Recruiter* _postByRecruiter;
	public:
		Job(Recruiter*, JobType);
		bool isThisJobNeedResume();
		bool isPostedBy(Recruiter*);
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
