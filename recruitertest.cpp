#include "recruitertest.h"

TEST(RecruiterCanPostJob, postOneJob) {
	Recruiter* recruiter = new Recruiter();
	Job* job = createATSJob();
	RecruiterPostJob* recruiterPostJob = new RecruiterPostJob();
	recruiterPostJob->postJob(recruiter, job);
	Jobs* jobs = recruiterPostJob->getRecruiterJobs(recruiter);
	EXPECT_EQ(jobs->atIndex(0), job);
	delete recruiterPostJob;
	delete recruiter;
	delete job;
}

TEST(RecruiterCanSeeAListOfJobTheyPost, postMutipleJob) {
	Recruiter* recruiter = new Recruiter();
	JobsManager* jobsManager = new JobsManager();
	JobType ats = ATS;
	JobType jreq = JReq;
	jobsManager->postJob(recruiter,ats);
	jobsManager->postJob(recruiter,jreq);
	Job* job3 = new Job(recruiter, ats);
	/*
	jobsManager->postJob(job3);
	Jobs* jobs = jobsManager->listJobsPostBy(recruiter);
	EXPECT_EQ(jobs->atIndex(2), job3);
	*/
}
