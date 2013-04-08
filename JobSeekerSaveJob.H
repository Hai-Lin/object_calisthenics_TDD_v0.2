#include "Job.h"
#include "JobSeeker.h"

class JobSeekerSavedJobs {
	private:
		map<JobSeeker*, Jobs*> _jobSeekerSavedJobs;
	public:
		JobSeekerSavedJobs();
		void addAJob(JobSeeker*, Job*);
};

class JobSeekerSaveJob {
	private:
		JobSeekerSavedJobs* _jobSeekerSavedJobs;
	public:
		JobSeekerSaveJob();
		bool saveJob(JobSeeker*, Job*);
}; 

