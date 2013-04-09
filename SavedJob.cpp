#include "SavedJob.h"

SavedJob::SavedJob(Job* job, JobSeeker* jobSeeker) {
	_job = job;
	_jobSeeker = jobSeeker;
}

bool SavedJob::isSavedBy(JobSeeker* jobSeeker) {
	return jobSeeker == _jobSeeker ? true : false;
}

void SavedJob::askForJobFromJobSeeker(JobSeeker* jobSeeker, Jobs* jobs) { 
	if(this->isSavedBy(jobSeeker))
		jobs->addJob(_job);
}

SavedJobs::SavedJobs() {
	vector<SavedJob*> jobs;
	_savedJobs = jobs;
}

void SavedJobs::addJob(JobSeeker* jobSeeker, Job* job) {
	if(job)
	{
		SavedJob* savedJob = new SavedJob(job, jobSeeker);
		_savedJobs.push_back(savedJob);
	}
}

SavedJob* SavedJobs::atIndex(int index) {
	if(index >= _savedJobs.size()) {
		cout<<"index is too big, exit!!"<<endl;
		exit(-1);
	}
	return _savedJobs[index];
}

Jobs* SavedJobs::seeAllSavedJobs(JobSeeker* jobSeeker) {
	Jobs* jobs = new Jobs();
	for(int index = 0; index < _savedJobs.size(); ++index)
		_savedJobs[index]->askForJobFromJobSeeker(jobSeeker, jobs);
	return jobs;
}

