#ifndef JOBAPPLICATION
#define JOBAPPLICATION
#include "Job.h"
#include "JobSeeker.h"
#include "Resume.h"
#include "Date.h"

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

class JobApplicationInfo {
	private:
		Job* _job;
		JobApplicatorInfo* _jobApplicatorInfo;
	public:
		JobApplicationInfo(JobSeeker*, Job*);
		JobApplicationInfo(JobSeeker* jobSeeker, Resume* resume, Job* job);
		bool isAppliedBy(JobSeeker*);
		void addJobSeekerTo(JobSeekers*);
		void askForJobFrom(JobSeeker*, Jobs*);	
		void askForJobSeekerFrom(Job*, JobSeekers*);
};

class JobApplication {
	private:
		Date* _date;
		JobApplicationInfo* _jobApplicationInfo;
	public:
		JobApplication(JobSeeker*, Job*, Date*);
		JobApplication(JobSeeker* jobSeeker, Resume* resume, Job* job, Date* date);
		bool isAppliedBy(JobSeeker*);
		void askForJobFrom(JobSeeker*, Jobs*);	
		void askForJobSeekerFrom(Job*, JobSeekers*);
		void askForJobSeekerFrom(Date*, JobSeekers*); 
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
		JobSeekers* jobSeekersAppliedOn(Date*);
};
#endif
