#include "JobSeekerSaveJob.h"

JobSeekerSaveJob::JobSeekerSaveJob() {
	map<JobSeeker*, Jobs*> jobSeekerSavedJobs;
	_jobSeekerSavedJobs = jobSeekerSavedJobs;
}

void JobSeekerSaveJob::saveJob(JobSeeker* jobSeeker, Job* job) {
	if(_jobSeekerSavedJobs.count(jobSeeker) != 0)
		_jobSeekerSavedJobs[jobSeeker]->addJob(job);
	if(_jobSeekerSavedJobs.count(jobSeeker) == 0) {
		Jobs* jobs = new Jobs();
		jobs->addJob(job);
		_jobSeekerSavedJobs[jobSeeker] = jobs;
	}
}

Jobs* JobSeekerSaveJob::getAllJobs(JobSeeker* jobSeeker) {
	return _jobSeekerSavedJobs[jobSeeker];
}
