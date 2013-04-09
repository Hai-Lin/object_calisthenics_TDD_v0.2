#include "Job.h"
#include "Recruiter.h"
#include "utility.h"

class RecruiterPostJob {
	private:
		map<Recruiter*, Jobs*> _recruiterPostJobs;
	public:
		RecruiterPostJob();
		void postJob(Recruiter*, Job*);
		Jobs* getRecruiterJobs(Recruiter*);
};

