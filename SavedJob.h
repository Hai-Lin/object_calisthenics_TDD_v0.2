#ifndef SAVEDJOB
#define SAVEDJOB
#include "JobSeeker.h"
#include "Job.h"

class SavedJob {
	private:
		Job* _job;
		JobSeeker* _jobSeeker;
		bool isSavedBy(JobSeeker*);
	public:
		SavedJob(Job*, JobSeeker*);
		void askForJobFromJobSeeker(JobSeeker* jobSeeker, Jobs* jobs); 
};

class SavedJobs {
	private:
		vector<SavedJob* > _savedJobs;
	public:
		SavedJobs();
		void addJob(JobSeeker*, Job*);
		SavedJob* atIndex(int index);
		Jobs* seeAllSavedJobs(JobSeeker*);
};

#endif
