#include "JobApplication.h"

JobApplication::JobApplication(Job* job, JobSeeker* jobSeeker, Resume* resume) {
	_job = job;
	_jobSeeker = jobSeeker;
	_resume = resume;
}

bool JobApplication::isAppliedBy(JobSeeker* jobSeeker) {
	return _jobSeeker == jobSeeker;
}

void JobApplication::askForJobFrom(JobSeeker* jobSeeker, Jobs* jobs) {
	if(this->isAppliedBy(jobSeeker))
		jobs->addJob(_job);
}

JobApplications::JobApplications() {
	vector<JobApplication*> jobApplications;
	_jobApplications = jobApplications;
}

void JobApplications::addJobApplication(JobApplication* jobApplication) {
	_jobApplications.push_back(jobApplication);
}

JobApplication* JobApplications::atIndex(int index) {
	return _jobApplications[index];
}

Jobs* JobApplications::seeAllAppliedJobsBy(JobSeeker* jobSeeker) {
	Jobs* jobs = new Jobs();
	for(int index = 0; index < _jobApplications.size(); ++index)
		_jobApplications[index]->askForJobFrom(jobSeeker, jobs);
	return jobs;
}
	
