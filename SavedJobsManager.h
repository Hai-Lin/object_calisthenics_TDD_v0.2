#include "SavedJob.h"

class SavedJobsManager {
	private:
		map<JobSeeker*, SavedJobs*> _jobSeekerSavedJobs;
	public:
		SavedJobsManager();
		void saveJob(JobSeeker*, Job*);
		SavedJobs* seeAllSavedJobs(JobSeeker*);
};

