#include "SavedJob.h"

SavedJob::SavedJob(Job* job, JobSeeker* jobSeeker) {
	_job = job;
	_jobSeeker = jobSeeker;
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

