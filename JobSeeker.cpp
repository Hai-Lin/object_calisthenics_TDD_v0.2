#include"JobSeeker.h"

JobSeekerJobs::JobSeekerJobs() {
	vector<Job*> jobs;
	_jobs = jobs;
}

void JobSeekerJobs::addJob(Job* job) {
	_jobs.push_back(job);
}

JobSeeker::JobSeeker(Resume* resume) {
	JobSeekerJobs* jobSeekerJobs = new JobSeekerJobs();
	_savedJobs = jobSeekerJobs;
	_resume = resume;
}

void JobSeeker::saveJob(Job* job) {
	_savedJobs->addJob(job);
}

bool JobSeeker::hasResume() {
	if(_resume != NULL)
		return true;
	if(_resume == NULL)
		return false;
}

