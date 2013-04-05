#include"Recruiter.h"

Recruiter::Recruiter() {
	_jobCollection = new JobCollection();
}

Job* Recruiter::postJob() {
	Job* job = new Job();
	_jobCollection->addJobToCollection(job);
	return job; 
}

JobCollection* Recruiter::getAllJobs() {
	return _jobCollection; 
}

