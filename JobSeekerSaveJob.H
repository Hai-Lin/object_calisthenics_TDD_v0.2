#include "Job.h"
#include "JobSeeker.h"

class JobSeekerSaveJob {
	private:
		map<JobSeeker*, Jobs*> _jobSeekerSavedJobs;
	public:
		JobSeekerSaveJob();
		void saveJob(JobSeeker*, Job*);
		Jobs* getAllJobs(JobSeeker*);
};

