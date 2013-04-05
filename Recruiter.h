#include "Job.h"
class Recruiter{
	private:
		JobCollection* _jobCollection;
	public:
		Job* postJob();
		JobCollection* getAllJobs();
};
