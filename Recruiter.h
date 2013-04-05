#include"utility.h"
class Job;
class RecruiterJobs{
	private:
		vector<Job*> _jobs;
	public:
		RecruiterJobs();	
		Job* atIndex(int index);
		void addJob(Job* );
};

class Recruiter{
	private:
		RecruiterJobs* _jobs;
	public:
		Recruiter();
		void postJob(Job*);
		RecruiterJobs* getAllJobs();
};
