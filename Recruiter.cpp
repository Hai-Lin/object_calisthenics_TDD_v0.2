#include"Recruiter.h"

RecruiterJobs::RecruiterJobs() {
	vector<Job*> jobs;
	_jobs = jobs;
}

Job* RecruiterJobs::atIndex(int index) {
	return _jobs[index];
}

void RecruiterJobs::addJob(Job* job) {
	_jobs.push_back(job);
}

Recruiter::Recruiter() {
	_jobs = new RecruiterJobs();
}

void Recruiter::postJob(Job* job) {
	_jobs->addJob(job);
}

RecruiterJobs* Recruiter::getAllJobs() {
	return _jobs; 
}

