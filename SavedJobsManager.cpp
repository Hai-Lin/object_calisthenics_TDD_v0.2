#include "SavedJobsManager.h"


SavedJobsManager::SavedJobsManager() {
	SavedJobs* savedJobs = new SavedJobs();
	_savedJobs = savedJobs;
}

void SavedJobsManager::saveJob(JobSeeker* jobSeeker, Job* job) {
	if(jobSeeker and job)
		_savedJobs->addJob(jobSeeker, job);
}

Jobs* SavedJobsManager::seeAllSavedJobs(JobSeeker* jobSeeker) {
	return _savedJobs->seeAllSavedJobs(jobSeeker);
}
