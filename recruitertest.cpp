#include <gtest/gtest.h>
#include "testhelper.h"

TEST(EmptyTest, emptytest) {

}

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
	Job* job1 = new Job(ATS);
	Job* job2 = new Job(JReq);
	Job* job3 = new Job(ATS);
	RecruiterPostJob* recruiterPostJob = new RecruiterPostJob();
	recruiterPostJob->postJob(recruiter, job1);
	recruiterPostJob->postJob(recruiter, job2);
	recruiterPostJob->postJob(recruiter, job3);
	Jobs* jobs = recruiterPostJob->getRecruiterJobs(recruiter);
	EXPECT_EQ(jobs->atIndex(0), job1);
	EXPECT_EQ(jobs->atIndex(1), job2);
	EXPECT_EQ(jobs->atIndex(2), job3);
	delete recruiterPostJob;
	delete recruiter;
	delete job1;
	delete job2;
	delete job3;
}
int main(int argc, char **argv) {
	::testing::InitGoogleTest( &argc, argv );
	return RUN_ALL_TESTS();
}
