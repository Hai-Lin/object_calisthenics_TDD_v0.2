#include"JobSeeker.h"

JobSeekerJobs::JobSeekerJobs() {
	vector<Job*> jobs;
	_jobs = jobs;
}

void JobSeekerJobs::addJob(Job* job) {
	_jobs.push_back(job);
}

JobSeeker::JobSeeker() {
	JobSeekerJobs* jobSeekerJobs = new JobSeekerJobs();
	_savedJobs = jobSeekerJobs;
}

void JobSeeker::saveJob(Job* job) {
	_savedJobs->addJob(job);
}

