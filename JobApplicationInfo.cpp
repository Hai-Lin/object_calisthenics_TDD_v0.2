#include "JobApplication.h"

JobApplicationInfo::JobApplicationInfo(JobSeeker* jobSeeker, Job* job) {
	_job = job;
	JobApplicatorInfo* jobApplicatorInfo = new JobApplicatorInfo(jobSeeker);
	_jobApplicatorInfo = jobApplicatorInfo;
}

JobApplicationInfo::JobApplicationInfo(JobSeeker* jobSeeker, Resume* resume, Job* job) {
	_job = job;
	JobApplicatorInfo* jobApplicatorInfo = new JobApplicatorInfo(jobSeeker, resume);
	_jobApplicatorInfo = jobApplicatorInfo;
}

bool JobApplicationInfo::isAppliedBy(JobSeeker* jobSeeker) {
	return _jobApplicatorInfo->isAppliedBy(jobSeeker);
}

bool JobApplicationInfo::isJob(Job* job) {
	return job == _job;
}

bool JobApplicationInfo::isPostBy(Recruiter* recruiter) {
	return _job->isPostedBy(recruiter);
}

void JobApplicationInfo::askForJobFrom(JobSeeker* jobSeeker, Jobs* jobs) {
	if(this->isAppliedBy(jobSeeker))
		jobs->addJob(_job);
}

void JobApplicationInfo::askForJobSeekerFrom(Job* job, JobSeekers* jobSeekers) {
	if(_job == job)
		_jobApplicatorInfo->addJobSeekerTo(jobSeekers);
}

void JobApplicationInfo::addJobSeekerTo(JobSeekers* jobSeekers) {
	_jobApplicatorInfo->addJobSeekerTo(jobSeekers);
}

