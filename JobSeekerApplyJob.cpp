#include "JobSeekerApplyJob.h"
/*
Jobs::Jobs() {
	vector<Job*> jobs;
	_jobs = jobs;
}

void Jobs::addJob(Job* job) {
	_jobs.push_back(job);
}
*/
JobSeekerAppliedJobs::JobSeekerAppliedJobs() {
	map<JobSeeker*, Jobs*> jobSeekerAppliedJobs;
	_jobSeekerAppliedJobs = jobSeekerAppliedJobs;
}

void JobSeekerAppliedJobs::addAJob(JobSeeker* jobSeeker, Job* job) {
	if(_jobSeekerAppliedJobs.count(jobSeeker) != 0)
		_jobSeekerAppliedJobs[jobSeeker]->addJob(job);
	if(_jobSeekerAppliedJobs.count(jobSeeker) == 0) {
		Jobs* jobs = new Jobs();
		jobs->addJob(job);
		_jobSeekerAppliedJobs[jobSeeker] = jobs;
	}
}

JobSeekerApplyJob::JobSeekerApplyJob() {
	_jobSeekerAppliedJobs = new JobSeekerAppliedJobs();
}

bool JobSeekerApplyJob::applyJob(JobSeeker* jobSeeker, Job* job) {
	if(job->isThisJobNeedResume() and jobSeeker->hasResume() or !job->isThisJobNeedResume())
	{
		_jobSeekerAppliedJobs->addAJob(jobSeeker, job);	
		return true;
	}
	return false;
}

