#include "JobsManager.h"

JobsManager::JobsManager() {
	Jobs* jobs = new Jobs();
	_jobs = jobs;
}

void JobsManager::askJobFrom(Recruiter* recruiter, Job* job, Jobs* jobs) {
	if(job->isPostedBy(recruiter))
		jobs->addJob(job);
}

void JobsManager::postJob(Job* job) {
	_jobs->addJob(job);
}

Jobs* JobsManager::seeJobsPostBy(Recruiter* recruiter ) {
	Jobs* jobs = new Jobs();
	for(int index = 0; index < _jobs->sizeOf(); ++index)
		askJobFrom(recruiter, _jobs->atIndex(index), jobs);
	return jobs;
}
