#include"utility.h"
#ifndef JOB
#define JOB
class Recruiter;

class Job {
	private:
		Recruiter* _postByRecruiter;
	public:
		Job(Recruiter*);
		virtual bool isThisJobNeedResume() = 0;
		bool isPostedBy(Recruiter*);
};

class Jobs {
	private:
		vector<Job*> _jobs;
	public:
		Jobs();
		void addJob(Job*);
		Job* atIndex(int index);
		int sizeOf();
};

class ATSJob : public Job {
	public:
		ATSJob(Recruiter* recruiter) : Job(recruiter)  {}
};

#endif
