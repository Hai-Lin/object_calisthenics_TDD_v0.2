#include"utility.h"
class Job;
class Resume;

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
		Resume* _resume;
	public:
		JobSeeker(Resume* = NULL);
		void saveJob(Job*);
		bool hasResume();
};
