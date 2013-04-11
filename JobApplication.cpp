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

bool JobApplication::isJob(Job* job) {
	return _jobApplicationInfo->isJob(job);
}

bool JobApplication::isPostBy(Recruiter* recruiter) {
	return _jobApplicationInfo->isPostBy(recruiter);
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

void JobApplication::askForJobSeekerFrom(Job* job, Date* date, JobSeekers* jobSeekers) {
	if(_date == date and this->isJob(job))
		_jobApplicationInfo->addJobSeekerTo(jobSeekers);
}

void JobApplication::askForJobSeekerFrom(Job* job, Date* date, Recruiter* recruiter, JobSeekers* jobSeekers) {
	if(_date == date and this->isJob(job) and this-> isPostBy(recruiter))
		_jobApplicationInfo->addJobSeekerTo(jobSeekers);
}

int JobApplication::increaseJobApplicationNumber(Job* job, int total) {
	if(this->isJob(job))
		total++;
	return total;
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

int JobApplications::getApplicationNumber(Job* job) {
	int result = 0;
	for(int index = 0; index < _jobApplications.size(); ++index) 
		result = _jobApplications[index]->increaseJobApplicationNumber(job, result);
	return result;
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

JobSeekers* JobApplications::jobSeekersAppliedToOn(Job* job, Date* date) {
	JobSeekers* jobSeekers = new JobSeekers();
	for(int index = 0; index < _jobApplications.size(); ++index)
		_jobApplications[index]->askForJobSeekerFrom(job, date, jobSeekers);
	return jobSeekers;
}

JobSeekers* JobApplications::jobSeekersAppliedToOnPostBy(Job* job, Date* date, Recruiter* recruiter) {
	JobSeekers* jobSeekers = new JobSeekers();
	for(int index = 0; index < _jobApplications.size(); ++index)
		_jobApplications[index]->askForJobSeekerFrom(job, date, recruiter, jobSeekers);
	return jobSeekers;
}
