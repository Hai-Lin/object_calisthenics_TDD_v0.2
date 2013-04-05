#include"Recruiter.h"
Job* Recruiter::postJob() {
	Job* job = new Job();
	return job; 
}

JobCollection* Recruiter::getAllJobs() {
	return _jobCollection; 
}

