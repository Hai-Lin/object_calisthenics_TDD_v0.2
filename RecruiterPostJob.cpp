#include "RecruiterPostJob.h"

RecruiterPostJob::RecruiterPostJob() {
	map<Recruiter*, Jobs*> recruiterPostJobs;
	_recruiterPostJobs = recruiterPostJobs;
}

void RecruiterPostJob::postJob(Recruiter* recruiter, Job* job) {
	if(_recruiterPostJobs.count(recruiter) != 0)
		_recruiterPostJobs[recruiter]->addJob(job);
	if(_recruiterPostJobs.count(recruiter) == 0) {
		Jobs* jobs = new Jobs();
		jobs->addJob(job);
		_recruiterPostJobs[recruiter] = jobs;
	}
}

Jobs* RecruiterPostJob::getRecruiterJobs(Recruiter* recruiter) {
	return _recruiterPostJobs[recruiter];
}
