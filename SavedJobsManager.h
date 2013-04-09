#include "SavedJob.h"

class SavedJobsManager {
	private:
		SavedJobs* _savedJobs;
	public:
		SavedJobsManager();
		void saveJob(JobSeeker*, Job*);
		Jobs* seeAllSavedJobs(JobSeeker*);
};

