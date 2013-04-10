#include "Job.h"
#include "JobSeeker.h"
#include "Resume.h"

class JobApplication {
	private:
		Job* _job;
		JobSeeker* _jobSeeker;
		Resume* _resume;
	public:
		JobApplication(Job* job, JobSeeker* jobSeeker, Resume* resume = NULL);
		bool isAppliedBy(JobSeeker*);
		void askForJobFrom(JobSeeker*, Jobs*);	
};

class JobApplications {
	private:
		vector<JobApplication*> _jobApplications;
	public:
		JobApplications();
		void addJobApplication(JobApplication*);
		JobApplication* atIndex(int index);
		Jobs* seeAllAppliedJobsBy(JobSeeker*);
};
