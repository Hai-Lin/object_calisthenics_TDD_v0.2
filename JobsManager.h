#include "Job.h"
#include "Recruiter.h"

class JobsManager {
	private:
		Jobs* _jobs;
	public:
		JobsManager();
		void postJob(Recruiter*, JobType);
		//Jobs* seeJobsPostBy(Recruiter*);
};
