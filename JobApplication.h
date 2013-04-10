#ifndef JOBAPPLICATION
#define JOBAPPLICATION
#include "Job.h"
#include "JobSeeker.h"
#include "Resume.h"

class JobApplicationInfo {
	private:
		Resume* _resume;
		JobSeeker* _jobSeeker;
	public:
		JobApplicationInfo(JobSeeker*);
		JobApplicationInfo(JobSeeker* jobSeeker, Resume* resume);
		bool isAppliedBy(JobSeeker*);
};

class JobApplication {
	private:
		Job* _job;
		JobApplicationInfo* _jobApplicationInfo;
	public:
		JobApplication(JobSeeker*, Job*);
		JobApplication(JobSeeker* jobSeeker, Resume* resume, Job* job);
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
#endif
