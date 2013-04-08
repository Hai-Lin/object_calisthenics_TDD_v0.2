#include"Job.h"

Job::Job(JobType jobType) {
	_jobType = jobType;
}

bool Job::isThisJobNeedResume() {
	if(_jobType == ATS) 
		return false;
	if(_jobType == JReq)
		return true;
}
	
Jobs::Jobs() {
	vector<Job*> jobs;
	_jobs = jobs;
}

void Jobs::addJob(Job* job) {
	_jobs.push_back(job);
}
