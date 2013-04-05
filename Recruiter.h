#include "Job.h"
class Recruiter{
	private:
		JobCollection* _jobCollection;
	public:
		Recruiter();
		Job* postJob();
		JobCollection* getAllJobs();
};
