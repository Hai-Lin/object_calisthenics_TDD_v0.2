#include "Job.h"
#include "JobSeeker.h"

class Jobs {
	private:
		vector<Job*> _jobs;
	public:
		Jobs();
		void addJob(Job*);
};

class JobSeekerAppliedJobs {
	private:
		map<JobSeeker*, Jobs*> _jobSeekerAppliedJobs;
	public:
		JobSeekerAppliedJobs();
		void addAJob(JobSeeker*, Job*);
};

class JobSeekerApplyJob {
	private:
		JobSeekerAppliedJobs* _jobSeekerAppliedJobs;
	public:
		JobSeekerApplyJob();
		bool applyJob(JobSeeker*, Job*);
}; 

