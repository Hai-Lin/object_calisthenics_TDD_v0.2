#include"Recruiter.h"

Recruiter::Recruiter() {
	_jobCollection = new JobCollection();
}

void Recruiter::postJob(Job* job) {
	_jobCollection->addJobToCollection(job);
}

JobCollection* Recruiter::getAllJobs() {
	return _jobCollection; 
}

