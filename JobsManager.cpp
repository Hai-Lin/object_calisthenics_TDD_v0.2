#include "JobsManager.h"

JobsManager::JobsManager() {
	Jobs* jobs = new Jobs();
	_jobs = jobs;
}

void JobsManager::postJob(Recruiter* recruiter, JobType jobType) {
	Job* job = new Job(recruiter, jobType);
	_jobs->addJob(job);
}
