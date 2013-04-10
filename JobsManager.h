#include "Job.h"
#include "Recruiter.h"

class JobsManager {
	private:
		Jobs* _jobs;
		void askJobFrom(Recruiter*, Job*, Jobs*);
	public:
		JobsManager();
		void postJob(Recruiter*, JobType);
		void postJob(Job*);
		Jobs* seeJobsPostBy(Recruiter*);
};
