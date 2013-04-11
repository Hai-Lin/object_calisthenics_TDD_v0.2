#include "JobApplication.h"

class JobApplicationsManager {
	private:
		JobApplications* _jobApplications;
		bool canApplyThisJob(JobSeeker*, Job*);
	public:
		JobApplicationsManager();
		bool applyJob(JobSeeker*, Job*, Date*);
		Jobs* seeAllAppliedJobsBy(JobSeeker*);
		JobSeekers* jobSeekersWhoApplied(Job*);
		JobSeekers* jobSeekersAppliedOn(Date*);
};

