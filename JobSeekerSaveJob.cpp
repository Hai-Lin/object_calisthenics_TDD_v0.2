#include "JobSeekerSaveJob.h"

JobSeekerSavedJobs::JobSeekerSavedJobs() {
	map<JobSeeker*, Jobs*> jobSeekerSavedJobs;
	_jobSeekerSavedJobs = jobSeekerSavedJobs;
}

void JobSeekerSavedJobs::addAJob(JobSeeker* jobSeeker, Job* job) {
	if(_jobSeekerSavedJobs.count(jobSeeker) != 0)
		_jobSeekerSavedJobs[jobSeeker]->addJob(job);
	if(_jobSeekerSavedJobs.count(jobSeeker) == 0) {
		Jobs* jobs = new Jobs();
		jobs->addJob(job);
		_jobSeekerSavedJobs[jobSeeker] = jobs;
	}
}

JobSeekerSaveJob::JobSeekerSaveJob() {
	_jobSeekerSavedJobs = new JobSeekerSavedJobs();
}

bool JobSeekerSaveJob::saveJob(JobSeeker* jobSeeker, Job* job) {
	if(!jobSeeker or !job)
		return false;
	_jobSeekerSavedJobs->addAJob(jobSeeker, job);
	return true;
}

