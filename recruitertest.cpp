#include <gtest/gtest.h>
#include "testhelper.h"

TEST(EmptyTest, emptytest) {

}

TEST(RecruiterCanPostJob, postJob) {
	Recruiter* recruiter = new Recruiter();
	Job* job = createATSJob();
	RecruiterPostJob* recruiterPostJob = new RecruiterPostJob();
	recruiterPostJob->postJob(recruiter, job);
	delete recruiter;
}
/*
TEST(RecruiterCanSeeAListOfJobTheyPost, seejobs) {
	Recruiter* recruiter = new Recruiter();
	Job* job = new Job();
	recruiter->postJob(job);
	RecruiterJobs* jobs = recruiter->getAllJobs();
	delete recruiter;
}

TEST(RecruiterCanSeeAListOfJobTheyPost, postOneJob) {
	Recruiter* recruiter = new Recruiter();
	Job* job = new Job();
	recruiter->postJob(job);
	RecruiterJobs* jobs = recruiter->getAllJobs();
	EXPECT_EQ(jobs->atIndex(0), job);
	delete recruiter;
}

TEST(RecruiterCanSeeAListOfJobTheyPost, postMutipleJob) {
	Recruiter* recruiter = new Recruiter();
	Job* job1 = new Job();
	Job* job2 = new Job();
	Job* job3 = new Job();
	recruiter->postJob(job1);
	recruiter->postJob(job2);
	recruiter->postJob(job3);
	RecruiterJobs* jobs = recruiter->getAllJobs();
	EXPECT_EQ(jobs->atIndex(0), job1);
	EXPECT_EQ(jobs->atIndex(1), job2);
	EXPECT_EQ(jobs->atIndex(2), job3);
	delete recruiter;
}
*/
int main(int argc, char **argv) {
	::testing::InitGoogleTest( &argc, argv );
	return RUN_ALL_TESTS();
}
