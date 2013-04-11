#ifndef JOBAPPLICATION
#define JOBAPPLICATION
#include "Job.h"
#include "JobSeeker.h"
#include "Resume.h"

class JobApplicatorInfo {
	private:
		Resume* _resume;
		JobSeeker* _jobSeeker;
	public:
		JobApplicatorInfo(JobSeeker*);
		JobApplicatorInfo(JobSeeker* jobSeeker, Resume* resume);
		bool isAppliedBy(JobSeeker*);
		void addJobSeekerTo(JobSeekers*);
};

class JobApplication {
	private:
		Job* _job;
		JobApplicatorInfo* _jobApplicationInfo;
	public:
		JobApplication(JobSeeker*, Job*);
		JobApplication(JobSeeker* jobSeeker, Resume* resume, Job* job);
		bool isAppliedBy(JobSeeker*);
		void askForJobFrom(JobSeeker*, Jobs*);	
		void askForJobSeekerFrom(Job*, JobSeekers*);
};

class JobApplications {
	private:
		vector<JobApplication*> _jobApplications;
	public:
		JobApplications();
		void addJobApplication(JobApplication*);
		JobApplication* atIndex(int index);
		Jobs* seeAllAppliedJobsBy(JobSeeker*);
		JobSeekers* jobSeekersWhoApplied(Job*);
};
#endif
