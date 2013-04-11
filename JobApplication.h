#ifndef JOBAPPLICATION
#define JOBAPPLICATION
#include "Job.h"
#include "JobSeeker.h"
#include "Resume.h"
#include "Date.h"

class JobApplicatorInfo {
	private:
		JobSeeker* _jobSeeker;
		Resume* _resume;
	public:
		JobApplicatorInfo(JobSeeker*);
		JobApplicatorInfo(JobSeeker* jobSeeker, Resume* resume);
		void addJobSeekerTo(JobSeekers*);
		bool isAppliedBy(JobSeeker*);
};

class JobApplicationInfo {
	private:
		Job* _job;
		JobApplicatorInfo* _jobApplicatorInfo;
	public:
		JobApplicationInfo(JobSeeker*, Job*);
		JobApplicationInfo(JobSeeker* jobSeeker, Resume* resume, Job* job);
		bool isAppliedBy(JobSeeker*);
		bool isJob(Job*);
		bool isPostBy(Recruiter*);
		void addJobSeekerTo(JobSeekers*);
		void askForJobFrom(JobSeeker*, Jobs*);	
		void askForJobSeekerFrom(Job*, JobSeekers*);
};

class JobApplication {
	private:
		Date* _date;
		JobApplicationInfo* _jobApplicationInfo;
		bool isAppliedBy(JobSeeker*);
		bool isJob(Job*);
		bool isPostBy(Recruiter*);
	public:
		JobApplication(JobSeeker*, Job*, Date*);
		JobApplication(JobSeeker* jobSeeker, Resume* resume, Job* job, Date* date);
		void askForJobFrom(JobSeeker*, Jobs*);	
		void askForJobSeekerFrom(Date*, JobSeekers*); 
		void askForJobSeekerFrom(Job*, JobSeekers*);
		void askForJobSeekerFrom(Job*, Date*, JobSeekers*); 
		void askForJobSeekerFrom(Job*, Date*, Recruiter*, JobSeekers*); 
};

class JobApplications {
	private:
		vector<JobApplication*> _jobApplications;
	public:
		JobApplications();
		void addJobApplication(JobApplication*);
		JobApplication* atIndex(int index);
		JobSeekers* jobSeekersWhoAppliedTo(Job*);
		JobSeekers* jobSeekersAppliedOn(Date*);
		JobSeekers* jobSeekersAppliedToOn(Job*, Date*);
		JobSeekers* jobSeekersAppliedToOnPostBy(Job*, Date*, Recruiter*);
		Jobs* seeAllAppliedJobsBy(JobSeeker*);
};
#endif
