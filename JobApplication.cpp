#include "JobApplication.h"

JobApplicationInfo::JobApplicationInfo(JobSeeker* jobSeeker) {
	_jobSeeker = jobSeeker;
	_resume = jobSeeker->currentResume();
}

JobApplicationInfo::JobApplicationInfo(JobSeeker* jobSeeker, Resume* resume) {
	_jobSeeker = jobSeeker;
	_resume = resume;
}	

bool JobApplicationInfo::isAppliedBy(JobSeeker* jobSeeker) {
	return _jobSeeker == jobSeeker;
}

JobApplication::JobApplication(JobSeeker* jobSeeker, Job* job) {
	_job = job;
	JobApplicationInfo* jobApplicationInfo = new JobApplicationInfo(jobSeeker);
	_jobApplicationInfo = jobApplicationInfo;
}

JobApplication::JobApplication(JobSeeker* jobSeeker, Resume* resume, Job* job) {
	_job = job;
	JobApplicationInfo* jobApplicationInfo = new JobApplicationInfo(jobSeeker, resume);
	_jobApplicationInfo = jobApplicationInfo;
}

bool JobApplication::isAppliedBy(JobSeeker* jobSeeker) {
	return _jobApplicationInfo->isAppliedBy(jobSeeker);
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
	
