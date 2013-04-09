#include "JobSeeker.h"
#include "Job.h"

class SavedJob {
	private:
		Job* _job;
		JobSeeker* _jobSeeker;
	public:
		SavedJob(Job*, JobSeeker*);
};

class SavedJobs {
	private:
		vector<SavedJob* > _savedJobs;
};
