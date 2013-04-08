#include"utility.h"
class Job;

class JobSeekerJobs
{
	private:
		vector<Job*> _jobs;
	public:
		JobSeekerJobs();
		void addJob(Job*);
};

class JobSeeker {
	private:
		JobSeekerJobs* _savedJobs;
	public:
		JobSeeker();
		void saveJob(Job* );
};
