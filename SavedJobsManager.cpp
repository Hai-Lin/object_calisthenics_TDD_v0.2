#include "SavedJobsManager.h"


SavedJobsManager::SavedJobsManager() {
	map<JobSeeker*, SavedJobs*> jobSeekerSavedJobs;
	_jobSeekerSavedJobs = jobSeekerSavedJobs;
}

void SavedJobsManager::saveJob(JobSeeker* jobSeeker, Job* job) {
	if(_jobSeekerSavedJobs.count(jobSeeker) != 0)
		_jobSeekerSavedJobs[jobSeeker]->addJob(jobSeeker, job);
	if(_jobSeekerSavedJobs.count(jobSeeker) == 0) {
		SavedJobs* savedJobs = new SavedJobs();
		savedJobs->addJob(jobSeeker, job);
		_jobSeekerSavedJobs[jobSeeker] = savedJobs;
	}
}

SavedJobs* SavedJobsManager::seeAllSavedJobs(JobSeeker* jobSeeker) {
	return _jobSeekerSavedJobs[jobSeeker];
}
