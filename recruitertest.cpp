#include "recruitertest.h"


TEST(RecruiterCanSeeAListOfJobTheyPost, postMutipleJob) {
	Recruiter* recruiter = new Recruiter();
	JobsManager* jobsManager = new JobsManager();
	JobType ats = ATS;
	JobType jreq = JReq;
	jobsManager->postJob(recruiter,ats);
	jobsManager->postJob(recruiter,jreq);
	Job* job3 = new Job(recruiter, ats);
	jobsManager->postJob(job3);
	Jobs* jobs = jobsManager->seeJobsPostBy(recruiter);
	EXPECT_EQ(jobs->atIndex(2), job3);
}
