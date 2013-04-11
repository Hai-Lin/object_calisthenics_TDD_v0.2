#include "JobApplication.h"

JobApplication::JobApplication(JobSeeker* jobSeeker, Job* job, Date* date) {
	_date = date;	
	JobApplicationInfo* jobApplicationInfo = new JobApplicationInfo(jobSeeker, job);
	_jobApplicationInfo = jobApplicationInfo;
}

JobApplication::JobApplication(JobSeeker* jobSeeker, Resume* resume, Job* job, Date* date) {
	_date = date;	
	JobApplicationInfo* jobApplicationInfo = new JobApplicationInfo(jobSeeker, resume, job);
	_jobApplicationInfo = jobApplicationInfo;
}

bool JobApplication::isAppliedBy(JobSeeker* jobSeeker) {
	return _jobApplicationInfo->isAppliedBy(jobSeeker);
}

void JobApplication::askForJobFrom(JobSeeker* jobSeeker, Jobs* jobs) {
	_jobApplicationInfo->askForJobFrom(jobSeeker, jobs);
}

void JobApplication::askForJobSeekerFrom(Job* job, JobSeekers* jobSeekers) {
	_jobApplicationInfo->askForJobSeekerFrom(job, jobSeekers);
}

void JobApplication::askForJobSeekerFrom(Date* date, JobSeekers* jobSeekers) {
	if(_date == date)
		_jobApplicationInfo->addJobSeekerTo(jobSeekers);
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

JobSeekers* JobApplications::jobSeekersWhoAppliedTo(Job* job) {
	JobSeekers* jobSeekers = new JobSeekers();
	for(int index = 0; index < _jobApplications.size(); ++index) 
		_jobApplications[index]->askForJobSeekerFrom(job, jobSeekers);
	return jobSeekers;
}

JobSeekers* JobApplications::jobSeekersAppliedOn(Date* date) {
	JobSeekers* jobSeekers = new JobSeekers();
	for(int index = 0; index < _jobApplications.size(); ++index)
		_jobApplications[index]->askForJobSeekerFrom(date, jobSeekers);
	return jobSeekers;
}
