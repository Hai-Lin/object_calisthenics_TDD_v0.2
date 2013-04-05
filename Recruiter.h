#include "Job.h"
class Recruiter{
	private:
		JobCollection* _jobCollection;
	public:
		Recruiter();
		void postJob(Job*);
		JobCollection* getAllJobs();
};
